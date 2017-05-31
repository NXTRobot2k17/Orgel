//*******************************************************************
#ifndef _NET_TCP_H
#define _NET_TCP_H

//*******************************************************************
#pragma pack(1)

class cNetARP;

class cNetTCP_Header
{
  public:                        // Byte No.:
    cNetWORD  sourcePort;        //   0
    cNetWORD  destPort;          //   2
    cNetDWORD sequenceNumber;    //   4
    cNetDWORD acknowledgeNumber; //   8
    cNetWORD  dataOffset_flags;  //  12
    cNetWORD  windowSize;        //  14
    cNetWORD  checksum;          //  16
    cNetWORD  urgentPointer;     //  18
    // no options and padding
                                 // length = 20

    // getter und setter fuer dataOffset / flags
    // The tcp header length is only a 4 bit field (the upper 4 bits).
    // It is calculated in units of 4 bytes.
    // E.g 24 bytes: 24/4=6 => 0x60=header len field
    // buf[TCP_HEADER_LEN_P]=(((TCP_HEADER_LEN_PLAIN+4)/4)) <<4; // 0x60

    WORD getDataOffset()
    {
      return( (WORD)((dataOffset_flags.data & 0x00FF)>>4) * 4 );
    }

    void setDataOffset( BYTE offset )
    {
      dataOffset_flags.data = (dataOffset_flags.data &0xFF00) | (offset/4)<<4;
    }

    BYTE getFlags()
    {
      return( (dataOffset_flags.data & 0xFF00) >> 8 );
    }

    void setFlags( BYTE flags )
    {
      dataOffset_flags.data = (dataOffset_flags.data &0x00FF) | ((WORD)flags<<8);
    }
};

//*******************************************************************
class cNetTCP_Msg
{
  public:                   // Byte No.:
    cHwEthernet_Header eth; //   0
    cNetIP_Header      ip;  //  14
    cNetTCP_Header     tcp; //  34
                            //  length = 54
};

//*******************************************************************
#pragma pack(8)

//#include "NetConnection.h"

class cNetTCP;

//*******************************************
//
//*******************************************

//*******************************************
//
//*******************************************
class cNetTCP : public cNetTransport
{
  public:

    class Socket : public cNetTransport::Socket
    {
      public:
        //-----------------------------------------------------------
        Socket( cNetTCP         &tcp,
                cNetApplication &app,
                cNetAddr<4>      inAddr,
                WORD             port,
                WORD             updateTime = 0 );

    virtual void open( cNetAddr<4> addr,
                       WORD port );

    virtual void close( void );

    virtual BYTE isConnected( void );

    virtual BYTE isReady( void );

    virtual void clear( void );

    virtual void fillBuffer( const char c);

    virtual void send( void );

    virtual BYTE get( char *c );

    virtual BYTE *getDataPtr( void );

    virtual void setDataLength( WORD len);

       private:
        //-------------------------------------------------------------------
        virtual BYTE process( void );
        virtual void update( void );
        virtual void timeout( void );


      private:
        enum
        {
          STATE_PENDING          = 100,
          STATE_OPEN_WAIT_SERVER,
          STATE_CONNECTED_WAIT_ACK,
          STATE_FINISHING
        };

      private:
        WORD  flags;

        WORD  dataLen;
        BYTE *dataPtr;
        BYTE  mss;
        DWORD initialSeqNum;
        DWORD seqNum;
        DWORD ackNum;
        DWORD ackNumExpected;
        BYTE type;

    //  private:
        cNetTCP         &tcp;

      friend class cNetTCP;

    };

    //---------------------------------------------------------------
    enum
    {
      FLAG_NONE   = 0x00,
      FLAG_FIN    = 0x01,
      FLAG_SYN    = 0x02,
      FLAG_RST    = 0x04,
      FLAG_PUSH   = 0x08,
      FLAG_ACK    = 0x10,
      FLAG_URG_V  = 0x20,
      FLAG_ECE_V  = 0x40,
      FLAG_CWR_V  = 0x80
    };

  public:
    //---------------------------------------------------------------
    cNetTCP( cNetIP  &ip
           );

    virtual void handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy );



  private:
    //---------------------------------------------------------------
    void create( Socket &con, WORD payloadLen );

  public:
    //cNetIP   &ip;
    virtual cNetAddr<4> &getAddr( void )
    {
      return( ip.addr );
    }

    virtual const cNetAddr<6> &getAddrPhy( void )
    {
      return( ip.eth.addrPhy );
    }

  public:
    cNetIP   &ip;

  private:
    //---------------------------------------------------------------
    WORD inPos;
    WORD inBufLen;
    BYTE *buf;

}; // cNetTCP

#endif
