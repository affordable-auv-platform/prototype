#ifndef _UDP_SEND_HPP_
#define _UDP_SEND_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include "port.h"
#include <string.h>
#include <unistd.h>

namespace udp_send
{	
	
	class UdpSend
	{
       #define BUFLEN 2048
	   
	   public: 	
       
	   UdpSend();
	   ~UdpSend();
	   
	   void setup(void);
	   void send(char output[]);
	   void endConection(void);

	};
}

#endif // _UDP_SEND_HPP_
