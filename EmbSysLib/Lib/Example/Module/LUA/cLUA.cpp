//*******************************************************************
/*!
\file   cDevTextIO.cpp
\author Thomas Breuer
\date   15.02.2013, 18.03.2016
\brief  Sample code, class cDevTextIO
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cDevTextIO_UART  text_IO( uart, 30, 30, "#\r\n", " +-ABCD123\r\t" );
//                              |   |    |        |
//                              |   |    |        +- list of single keys
//                              |   |    +---------- list of terminating
//                              |   |                characters
//                              |   +--------------- output buffer size
//                              +------------------- input buffer size

#include "Module/LUA.h"

int pmain (lua_State *L) ;

class cLua
{
  public:
    cLua( void *p)
    {
      L = luaL_newstate( );  /* create state */
      luaL_setParent(L,p);
    }
    ~cLua()
    {
      lua_close(L);
    }

    struct lua_State *L;

    void l_message (const char *pname, const char *msg)
    {
      if (pname)
        lua_writestringerror("%s: ", pname);
      lua_writestringerror("%s\n", msg);
    }

    int report (lua_State *L, int status)
    {
      if (status != LUA_OK)
      {
        const char *msg = lua_tostring(L, -1);
        l_message("cLua", msg);
        lua_pop(L, 1);  /* remove message */
      }
      return status;
    }

    int run(char* file)
    {
      int status, result;
      char *lua_argv[] ={"lua","",NULL};
      lua_argv[1] = file;
      if (L == NULL)
      {
        l_message("cLua", "cannot create state: not enough memory");
        return EXIT_FAILURE;
      }
      lua_pushcfunction(L, &pmain);  /* to call 'pmain' in protected mode */
      lua_pushinteger(L, /*argc*/2);  /* 1st argument */
      lua_pushlightuserdata(L, lua_argv); /* 2nd argument */
      status = lua_pcall(L, 2, 1, 0);  /* do the call */
      result = lua_toboolean(L, -1);  /* get result */
      report(L, status);
      return (result && status == LUA_OK) ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    int call(char *cmd)
    {
      if (luaL_loadstring(L, cmd) || lua_pcall(L,0,0,0) )
      {
        printf("ERROR %s %s\n",cmd,lua_tostring(L,-1));
      }
    }

    int registerFunction(char *name, int (*ptr)(lua_State *L) )
    {
      lua_pushcfunction(L, ptr );
      lua_setglobal(L, name);
    }
};

//*******************************************************************
class cMyLua : public cLua
{
  public:
    cMyLua(int idIn, void *p=0) : cLua((p)?p:this)
    {
      id = idIn;

      registerFunction( "test", test );
    }

    static int test( lua_State *L)
    {
      double l = lua_tonumber(L,1);
      double d = lua_tonumber(L,2);
      cMyLua *ptr = (cMyLua*)luaL_getParent(L);

      printf("test(): %d %lf\n",(int)l,d);

      ptr->func(l,d);
      //lua_pushnumber(L,0);
      return(0);
    }

    virtual int setFreq( float f)
    {
      lua_getglobal(L,"setFreq");
      lua_pushnumber(L,f);
      if( lua_pcall(L,1,1,0) != LUA_OK )
        printf("error:%s\n",lua_tostring(L,-1));
      int isnum;
      float r = lua_tonumberx(L,-1, &isnum );
       lua_pop(L,1);
      id = 100*r;
      printf("ret:%f\n",r);
      return(r);
    }

    int id;

    virtual void func(int l, float x)
    {
      //printf("func-1:%d\n",id);
      lcd.printf(l,0,20,"func:%d %f\n",id,x);
      dac.set(32000.0*(x+1),0);
    }
};

//*******************************************************************
class cMyLua2 : public cMyLua
{
  public:
    cMyLua2(int idIn) : cMyLua(7,this)
    {
    }

    virtual void func(int l, float x)
    {
      printf("func-2:%d\n",id);
      lcd.printf(l,0,20,"func-2:%d %f\n",id,x);
    }
};

//*******************************************************************
cHwMemory_MCU mem( "test.lua" );

//*******************************************************************
int main( void )

{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );
  int cnt=0;
  int run = true;

  /*
  char *lua_argv[] ={"lua","luac.out",NULL};

  lua_ymain(2,lua_argv);
  */

  cMyLua lua(1);
  cMyLua2 lua2(2);


//lua_pushcfunction(lua.L, test );
//lua_setglobal(lua.L, "test");

  lua.run("test.lua");
  lua.call("xprint(111)");

  //lua2.registerFunction( "test", lua2.test );
  lua2.run("test.lua");
  lua2.call("test(2)\n");
//lua_State *L = luaL_newstate();
//luaL_openlibs(L);

char str[128];
for(int i=0;i<10;i++)
{

}
//lua_close(lua.L);
float f=0;
  while( run )
  {
    net.update();
    sprintf(str,"xprint(%d);\n",cnt++);
   lua.call(str);
    if( char *str = text_IO.getString() )
    {
      switch( (BYTE)str[0] )
      {
        case 0xC1: text_IO.printf( "<Ctrl up>   \r\n" );
        f+=0.01;
        sprintf(str,"f=%f;\n",f);
        lua.call(str);
        lcd.printf(2,0,20,str);
        break;
        case 0xC2: text_IO.printf( "<Ctrl down> \r\n" );
        f-=0.01;
        sprintf(str,"f=%f;\n",f);
        lua.setFreq(f);
        lcd.printf(2,0,20,str);
        break;
        case 0xC3: text_IO.printf( "<Ctrl right>\r\n" ); break;
        case 0xC4: text_IO.printf( "<Ctrl left> \r\n" ); break;
        case '\t': lua.run("test.lua");break;
        case '\r':  run = false; break;
        default:   text_IO.printf( "-->%s\r\n", str   ); printf("-->%s\r\n", str  );break;
      }
    }
    //text_IO.printf( "" );
    //Sleep(1);
    //if( cnt++ > 500)
    //{
    //  uart.set( 0 );
    //  cnt=0;
    //}
  }
}
