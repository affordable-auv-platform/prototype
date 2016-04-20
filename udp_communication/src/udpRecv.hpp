#ifndef _UDP_RECV_HPP_
#define _UDP_RECV_HPP_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "port.h"
#include <iostream>

using namespace std;

namespace udp_recv{	
	
	class UdpRecv{
		
	#define BUFSIZE 2048

	public:
	
    UdpRecv();
	~UdpRecv();
    
    void configServer(void);
    string listen(void);
	};
}

#endif // _UDP_RECV_HPP_
