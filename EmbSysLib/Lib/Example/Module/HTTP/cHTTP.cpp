//*******************************************************************
/*!
\file   cHTTP.cpp
\author Thomas Breuer
\date   15.05.2014
\brief  Sample HTTP-Webserver
*/

//*******************************************************************
#include "lib.h"
#include "Module/HTTP.h"
#include "config.h"

//*******************************************************************
//#include "HTML/index.h"
//#include "HTML/event_form.h"


/*static const char *event_formHTML = (const char*)0x70000;

static const char *imagePNG = (const char*)0x60000;
static const char *faviconICO = (const char*)0x50000;
*/

//#include "HTML/request.h"
//#include "HTML/monitor.h"

#ifdef _MCU_TYPE_VIRTUAL
// #include "content.h"

#else
  //const char *content = (char*)0x50000;
#endif


//**************************************************************************************
const char *eventList1[] = {"Standby", "ON", "OFF", NULL};
const char *eventList2[] = {"Button", NULL};

//**************************************************************************************
class cPage : public cHTTP_Page
{
  public:
    cPage( cHTTP      &http,
                    //const char *name,
                    cHwMemory &content )
    : cHTTP_Page( http, /*name,*/ content),

      cnt( *this, "cnt",    "%d",   0       ),
      btn1 ( *this, "btn1",  eventList1,0       ),
      btn2 ( *this, "btn2",  eventList2,0       ),
      num3( *this, "num3",   "%d",   0       ),
      mon3( *this, "mon3",   "%.2f",   0       ),
      btn1cnt( *this, "btn1cnt",   "%d",   0       ),
      btn2cnt( *this, "btn2cnt",   "%d",   0       )


    {
    }

    virtual void update( void )
    {
      cnt.set( (cnt.get() + 1)%100 );
      if( btn1.isNew() )
      {
        btn1.set( (btn1.get()+1)%3 );
        btn1cnt.set( btn1cnt.get()+1);
      }
     if( btn2.isNew() )
      {
        btn1.set( 0 );
        btn2cnt.set( btn2cnt.get()+1);
      }
      mon3.set( 0.01*num3.get() );
    }

cHTTP_ParaType<WORD>  cnt;
cHTTP_ParaEvent       btn1;
cHTTP_ParaEvent       btn2;

cHTTP_ParaType<int>   num3;
cHTTP_ParaType<float> mon3;

cHTTP_ParaType<int>   btn1cnt;
cHTTP_ParaType<int>   btn2cnt;
};

//*******************************************************************
int main (void)
{
  com.printf("cHTTP (Webserver) ");
  com.printf( __DATE__ " " __TIME__ "\r\n");

  //##########################################
  #ifdef _MCU_TYPE_VIRTUAL
    // cNetWinSock net;

    // cNetWinSockTCP tcp( net );
    // cNetWinSockUDP udp( net );
    cNetTCP tcp( net );

  //##########################################
  #else
    cNetIP   ip   ( net, myIP, timer );
    cNetICMP icmp ( ip );
    cNetTCP  tcp  ( ip );
    cNetUDP  udp  ( ip );                      // optional (*)
    cNetDHCP dhcp ( udp, "EmbCpp-Webserver" ); // optional (*)
    // (*): not used, if IP-address is predefined

  #endif
  //##########################################

  cHTTP http( tcp );

//    cHTTP_Page  index( http, "index.html",  indexHTML );

    cPage form( http, /*"index.html",*/ contentMem );
 /*   cPage request( http, "request.html", requestHTML );
    cHTTP_Page image( http, "image.png", imagePNG, 2151 );
    cHTTP_Page favicon( http, "favicon.ico", faviconICO, 209 );
*/
    cHTTP_ParaString      nachname( form, "nachname", "%s",   "hello" );
    cHTTP_ParaString      vorname( form, "vorname", "%s",   "hello" );
    cHTTP_ParaType<int>   fz  ( form, "z",   "%d",   0       );
 //   cHTTP_ParaType<int>   rz  ( request, "z",   "%d",   0       );
    cHTTP_ParaType<float>   ra  ( form, "ana1",   "%.2f",   0       );


    cHTTP_ParaType<int>   num1( form, "num1",   "%d",   0       );
    cHTTP_ParaType<int>   num2( form, "num2",   "%d",   0       );
    cHTTP_ParaType<float> mon1( form, "mon1",   "%.2f",   0       );
    cHTTP_ParaType<float> mon2( form, "mon2",   "%.2f",   0       );
    cHTTP_ParaType<int>   opt1( form, "opt1",   "%d",     0       );
    cHTTP_ParaString      opt2( form, "opt2",   "%s",   "on"       );

    cHTTP_ParaType<int>   sel1( form, "sel1", "%d",  0         );
    cHTTP_ParaString      sel2( form, "sel2", "%s",  "A"       );

/*
  //    cHTTP_ParaString      txt( form, "txt", "%s",   "hello" );
      cHTTP_ParaType<int>   fx  ( form, "x",   "%d",   0       );
      cHTTP_ParaType<int>   fy  ( form, "y",   "%d",   0       );


      cHTTP_ParaType<BYTE>  fa  ( form, "a",   "%hhd", 0       );
      cHTTP_ParaType<BYTE>  fb  ( form, "b",   "%hhd", 0       );

  //    cHTTP_ParaOption      fop1( form, "op1",         0       );
  //    cHTTP_ParaOption      fop2( form, "op2",         0       );
  //    cHTTP_ParaOption      fop3( form, "op3",         0       );
*/
/*    cPage monitor( http, "monitor.html", monitorHTML );

      cHTTP_ParaString      mtxt( monitor, "txt", "%s",   "hello" );
      cHTTP_ParaType<int>   mx  ( monitor, "x",   "%d",   0       );
      cHTTP_ParaType<BYTE>  mb  ( monitor, "b",   "%hhd", 0       );

*/
  BYTE flag = true;

  while (1)
  {
    if( flag && !(net.getIP() == zeroAddr) )
    {
      flag = false;
      com.printf("IP:  %d.%d.%d.%d\r\n",
                    net.getIP().addr[0],
                    net.getIP().addr[1],
                    net.getIP().addr[2],
                    net.getIP().addr[3] );
    }

    net.update();
        mon1.set( 0.01*num1.get() );
        mon2.set( 0.01*num2.get() );

   #ifdef _MCU_TYPE_VIRTUAL
     if( form.isNew() )
     {
        printf("opt1=%d opt2=%s sel1=%d sel2=%s\n", opt1.get(), opt2.get(), sel1.get(), sel2.get());
     }
   #else
//    ra.set( (float)in );
   #endif
    // rz.set(fz.get()+10);

/*
    if( request.isNew())
  printf("value=%d\n", rz.get());
*/
    /*
    if( form.isNew() )
    {
      mtxt.set( ftxt.get() );
      mx.set( fx.get() );
      mb.set( fb.get() );
    }
*/

  }
}
