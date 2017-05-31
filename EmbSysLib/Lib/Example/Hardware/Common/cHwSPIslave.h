//*******************************************************************
/*!
\file   cHwI2Cslave.h
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
class DataHandler : public cHwSPIslave::DataHandler
{
  public:
    //---------------------------------------------------------------
    DataHandler()
    {
      id = 0;
    }

    //---------------------------------------------------------------
    virtual BYTE transceive(BYTE dataIn)
    {
      if(id==0)
      {
        adr = dataIn&0x7F;
        rw  = dataIn>>7;
        id++;
        return(data[adr]); 
      }
      else
      {
        id = 0;
        if(rw) // schreiben
        {
          data[adr] = dataIn;
          return(0); 
        }
        else //lesen
        {
          return(0); 
        }
      }
    }

    //---------------------------------------------------------------
    BYTE data[128];
    BYTE adr;
    BYTE id;
    BYTE rw;
};
