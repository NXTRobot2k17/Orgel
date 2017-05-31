//*******************************************************************
/*!
\file   cHwI2Cslave.h
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
class DataHandler : public cHwI2Cslave::DataHandler
{
  public:
    //---------------------------------------------------------------
    virtual void receive(BYTE dataIn, BYTE id)
    {
      if(id==0)
        adr = dataIn;
      else
        data[adr] = dataIn;
    }

    //---------------------------------------------------------------
    virtual BYTE transmit(BYTE id)
    {
      return(data[adr]);
    }

    //---------------------------------------------------------------
    BYTE data[256];
    BYTE adr;
};
