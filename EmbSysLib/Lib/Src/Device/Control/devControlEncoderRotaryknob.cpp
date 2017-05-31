//*******************************************************************
/*!
\file   devControlEncoderRotaryKnob.cpp
\author Thomas Breuer
\date   12.04.2011
*/


//*******************************************************************
//
// cDevControlEncoderRotaryKnob
//
//*******************************************************************
//-------------------------------------------------------------------
cDevControlEncoderRotaryKnob::cDevControlEncoderRotaryKnob( cDevDigital *btnLeftIn,
                                              cDevDigital *btnRightIn,
                                              cDevDigital *btnCtrlIn,
                                              cHwTimer    *timerPtr )
: cDevControlEncoder( btnCtrlIn, timerPtr ),
  btnLeft    ( btnLeftIn ),
  btnRight   ( btnRightIn )

{
}

//-------------------------------------------------------------------
cDevControlEncoder::tEvent cDevControlEncoderRotaryKnob::getIncrement( void )
{
  if( btnLeft && btnRight )
  {
    btnLeft->update();
    btnRight->update();

    if( btnLeft->isSet() != btnRight->isSet() )
    {
      if( btnLeft->isChanged() )
      {
        return( LEFT );
      }

      if( btnRight->isChanged() )
      {
        return( RIGHT );
      }
    }
  }
  return( NONE );
}

//EOF
