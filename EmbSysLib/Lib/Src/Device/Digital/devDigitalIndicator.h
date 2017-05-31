//*******************************************************************
/*!
\file   devDigitalIndicator.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   13.08.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_DIGITAL_INDICATOR_H
#define _DEV_DIGITAL_INDICATOR_H

//*******************************************************************
#include "devDigital.h"

//*******************************************************************
/*!
\class   cDevDigitalIndicator

\brief   ...

...

\example cDevDigitalIndicator.cpp
*/
class cDevDigitalIndicator : public cList::Item
{
  public:
    //---------------------------------------------------------------
    /*! \enum Mode
        \brief Define the operating modes of a GPIO port pin
    */
    /*
    typedef enum
    {
      // Input modes
      In    = cHwPort::In,     //!< Input, floating
      InPU  = cHwPort::InPU,   //!< Input, pull-up
      InPD  = cHwPort::InPD,   //!< Input, pull-down

      // Output modes
      Out   = cHwPort::OutPP,  //!< Output, push-pull
      OutOD = cHwPort::OutOD,  //!< Output, open drain
      OutPU = cHwPort::OutPU,  //!< Output, open drain & pull-up
      OutPD = cHwPort::OutPD   //!< Output, open drain & pull-down
    } Mode;
    */

  public:
    //---------------------------------------------------------------
    /*! Initialize a digital port pin
        \param port  Reference to the hardware object
        \param pinId Port pin number
        \param mode  Operating mode
        \param def   Default value: Corresponding physical value
                     (0: low, 1: high), when logical value is
                      false
    */
    cDevDigitalIndicator( cDevDigital &devDigital,
                          cHwTimer    &timer );

  public:
    //---------------------------------------------------------------
    // Setter methods
    //---------------------------------------------------------------
    //---------------------------------------------------------------
    /*! Set digital output to logic level 'true'
    */
    virtual void set( void )
    {
      devDigital.set();
    }

     //---------------------------------------------------------------
    /*! Set digital output to logic level 'false'
    */
    virtual void clr( void )
    {
      devDigital.clr();
    }

    //---------------------------------------------------------------
    /*! ...
    */
    virtual void trigger( WORD timeoutIn )
    {
      devDigital.set();
      timeout = ((DWORD)timeoutIn*1000)/cycleTime;
    }

  private:
    //---------------------------------------------------------------
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    cDevDigital &devDigital;
    cHwTimer    &timer;
    DWORD        timeout;
    DWORD        cycleTime;

}; //cDevDigitalIndicator

#endif
