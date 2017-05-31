//*******************************************************************
/*!
\file   cDevDisplayChar.cpp
\author Thomas Breuer
\date   15.02.2013
\brief  Sample Device Display (character)
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cDevDisplayChar lcd( disp );

//*******************************************************************
int main( void )
{
  BYTE cnt = 0;

  while( 1 )
  {
    if( cnt == 0 )
    {
      lcd.clear();

      lcd.printf( 0, 0, 0, "cDevDisplayChar" );
      lcd.printf( 1, 0, 0, __DATE__ "," __TIME__"\r\n" );
      lcd.printf( 2, 0, 0, "123456789012345678901234567890" );
      lcd.printf( 3, 0, 0, "------------------------------" );
    }
    lcd.printf( 3, 3, 10, "cnt = %d", cnt++ );
  }
}
