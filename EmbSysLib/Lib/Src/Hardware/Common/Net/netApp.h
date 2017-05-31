#ifndef _NET_APP_H
#define _NET_APP_H

#include "Std/List.h"

class cNetApplication : public cList::Item
{
  public:
    cNetApplication( void )
    {
    }

    virtual void process( void ) = 0;

    virtual void update( void ) = 0;

    virtual void timeout( void ) = 0;
};

#endif
