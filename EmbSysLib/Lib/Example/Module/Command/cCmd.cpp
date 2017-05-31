//*******************************************************************
/*!
\file   cCmd.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample Command
*/

//*******************************************************************
#include "lib.h"
#include "Module/Command.h"
#include "config.h"

//*******************************************************************
cDevComUART  com( uart, 30, 30, cCmd::EOS, "+-\r" );
//                       |   |         |     |
//                       |   |         |     +- string containing single key commands
//                       |   |         +------- string containing terminating characters
//                       |   +----------------- output buffer size
//                       +--------------------- input buffer size

//*******************************************************************
cDevMemory mem( memHardware );

//*******************************************************************
const char *texte[] = { "zero 0",
                        "one",
                        "two",
                        "three",
                        "four",
                        "12345678901234567890",
                        NULL
                      };

//*******************************************************************
void msgKey( cDevComUART &com, const char *keyName )
{
  com.printf( "\r\n%s pressed\r\n", keyName );
}

//*******************************************************************
#include "hardware/MCU/ATmega/WORKAROUND_AVR_BUG.h"
//*******************************************************************

//*******************************************************************
int main(void)
{
 // com.printf("cCmd, "__DATE__" "__TIME__"\r\n" );

  // Instantiate the command manager
  cCmd cmd( com, &mem );

  // Instantiate some command items
  // Parameters:
  cCmdParaType< int   >   X( cmd, "X", "%d",      cCmdPara::EVENT, 1        );

  cCmdParaType< float >   Y( cmd, "Y", "%g Volt", cCmdPara::MEMORY, 2.0      );
  // Lists:

  cCmdParaList            L( cmd, "L", "\"%s\"",  cCmdPara::MEMORY, texte, 0 );

  // Strings:
  cCmdParaString          S( cmd, "S", "\"%s\"",  cCmdPara::MEMORY, ""       );

  // Events:
  cCmdParaEvent  reset   ( cmd, "reset" );
  cCmdParaEvent  del     ( cmd, "del"   );
  cCmdParaEvent  store   ( cmd, "store"   );
  // Single key events:
  cCmdParaEvent  keyUP   ( cmd, "\xC1"  ); // 0x80|'A'
  cCmdParaEvent  keyDWN  ( cmd, "\xC2"  ); // 0x80|'B'
  cCmdParaEvent  keyRIGHT( cmd, "\xC3"  ); // 0x80|'C'
  cCmdParaEvent  keyLEFT ( cmd, "\xC4"  ); // 0x80|'D'
  cCmdParaEvent  keyPLUS ( cmd, "+"     );
  cCmdParaEvent  keyMINUS( cmd, "-"     );
  cCmdParaEvent  keyENTER( cmd, "\r"    );

  while( 1 )
  {
    sys.run();   // runs the timer, usefull in VIRTUAL only

    //-----------
    cmd.update();  // update commands input and output
    //-----------

    // Handle events and data inputs
    if( reset.isNew() )
    {
      sys.reset();
    }
    else if( del.isNew() )
    {
      cmd.clear(); // clear data memory
    }
    else if( store.isNew() )
    {
      cmd.store();
    }
    else if( keyUP.isNew()    ) { X = X + 1; msgKey( com, "UP"    ); S="UP";        }
    else if( keyDWN.isNew()   ) { X = X - 1; msgKey( com, "DWN"   ); S.set("DWN");  }
    else if( keyRIGHT.isNew() ) { Y = Y + 1; msgKey( com, "RIGHT" ); }
    else if( keyLEFT.isNew()  ) { Y = Y - 1; msgKey( com, "LEFT"  ); }
    else if( keyPLUS.isNew()  ) { L = L + 1; msgKey( com, "'+'"   ); }
    else if( keyMINUS.isNew() ) { L = L - 1; msgKey( com, "'-'"   ); }
    else if( keyENTER.isNew() ) {            msgKey( com, "ENTER" ); }

    if( cmd.isNew() ) // any parameter touched?
    {
      // Let's have a dump
      com.printf( "\r\n"                      );
      com.printf( "X=%d ",      (int)X         );
      com.printf( "Y=%g ",      Y.get()        );
      com.printf( "L=%d (%s) ", L.get(),
                                L.getString()  );
      com.printf( "S='%s'",     (const char*)S );
      com.printf( "\r\n"                       );
    }
  } // while( 1 )
}

//EOF
