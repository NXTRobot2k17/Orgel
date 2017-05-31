//*******************************************************************
/*!
\file   HTTP.cpp
\author Thomas Breuer
\date   06.02.2014
*/

//*******************************************************************
//
// cHTTP
//
//*******************************************************************
//-------------------------------------------------------------------
cHTTP::cHTTP( cNetTCP &tcp,
              WORD     port )

 : socket( tcp, *this, broadcastAddr, port, 5/* update time [ms] */ )

{
  socket.openDefault();
  page = NULL;
}

//-------------------------------------------------------------------
void cHTTP::process( void )
{
  char c;
  char str[20];

  BYTE pos;

  while( socket.get( &c ) )
  {
    if( c == '/')
    {
      break;
    }
  }

  // Parse GET-command: page name
  pos = 0;
  while( socket.get( &c ) )
  {
    if( c == '?' || c == ' ')
    {
      break;
    }
    if( pos < 20-1 )
    {
      str[pos++] = c;
    }
  }
  str[pos++] = 0;

  if( strlen( str ) == 0 )
  {
    strcpy( str, "index.html" );
  }

  // select page by name
/*
  cHTTP_Page *ptr = (cHTTP_Page *)pageList.getFirst();
  while( ptr )
  {
    if(    ptr
        && ptr->content
        && strncmp(ptr->name, str, strlen(ptr->name)) == 0 )
    {
      break;
    }
    ptr = (cHTTP_Page *)ptr->getNext();
  }
*/

   char pageName[20];

   strcpy( pageName, str );

  // page found?
  if( page )
  {
 //   printf("page (%s)\n", str);
    if( c == '?' )  // end of page name
    {
      page->clear();

      // Parse parameter
      pos = 0;
      while( socket.get( &c ) /*&& pos < 20-1*/)
      {
        if( pos>=20-1 || c == '&' || c == ' ' ) // end of parameter or parameter list?
        {
          str[pos]=0;
          pos=0;

          page->setValue( str );

          if( c == ' ') // end of parameter list?
          {
            break;
          }
        }
        else
        {
          str[pos++] = (c=='+')?' ':c;
        }
      }
    }
    page->update();
    page->createPage( socket, pageName );
  }
  else
  {
 //   printf("no page (%s)\n", str);
    socket.close( );
  }
}

//-------------------------------------------------------------------
/*
void cHTTP::addPage( cHTTP_Page *page )
{
  pageList.add( page );
}
*/
//EOF
