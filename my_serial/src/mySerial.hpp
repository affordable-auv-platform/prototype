#ifndef MY_SERIAL_HPP_
#define MY_SERIAL_HPP_

#include <SerialStream.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;
using namespace LibSerial;

namespace my_serial
{	
	typedef struct  info_out{
		int x, y, z;
		int up,down,right,left;
		int deltat;
	};

	class mySerial
	{     
	   public: 	
       
	   mySerial();
	   ~mySerial();
	   
	   void setup(void);
	   void close(void);
	   string read();
	   void send(string); 	

	};
}

#endif // _UDP_SEND_HPP_
