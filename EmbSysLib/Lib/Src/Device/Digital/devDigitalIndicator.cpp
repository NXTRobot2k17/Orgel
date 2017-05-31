//*******************************************************************
/*!
\file   cDevDigitalIndicator.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devDigitalIndicator.h"

//*******************************************************************
//
// cDevDigitalIndicator
//
//*******************************************************************
//-------------------------------------------------------------------
cDevDigitalIndicator::cDevDigitalIndicator( cDevDigital &devDigitalIn,
                                            cHwTimer    &timerIn )
: devDigital( devDigitalIn ),
  timer     ( timerIn      )
{
  timeout   = 0;
  cycleTime = timer.getCycleTime();
  clr();
  timer.add(this);
}

//-------------------------------------------------------------------
void cDevDigitalIndicator::update( void )
{
  if( timeout > 0 )
  {
    timeout--;
    if( timeout == 0 )
    {
      clr();
    }
  }
}

//EOF
