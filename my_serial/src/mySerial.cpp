#include "mySerial.hpp"
 
namespace my_serial
{		
	SerialStream canalSerial;
	char msg[256];
	int val[8];
	int cont = 0;
	info_out info;
	
	mySerial::mySerial(){
	}

	mySerial::~mySerial(){
	}

	void mySerial::setup(){
		
		canalSerial.Open("/dev/ttyO1");

		if (!canalSerial.good()){
			printf("Sem conexão!\n");
			//return 0;
		}
		
		//Config
		canalSerial.SetBaudRate(SerialStreamBuf::BAUD_115200);
		canalSerial.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
		canalSerial.SetParity(SerialStreamBuf::PARITY_NONE);
		canalSerial.SetNumOfStopBits(1);

	}
	
	//Didn't finish (See tthe structure to be listen and change the one on this code, choose a way to return to de orogen component)
	string mySerial::read(){
		
		int in_avail = canalSerial.rdbuf()->in_avail();

		if (in_avail > 0){
			char ch = 0;
			canalSerial >> ch;

			//send out the garbage 
			if(ch == '*'){
		    	if (cont > 0){
		    		if (msg[0] == '*') {
						msg[cont] = '\0';
						//printf("%s\n", msg);
						sscanf(msg,"*%d,%d,%d,%d,%d,%d,%d,%d", &info.x,&info.y,&info.z,&info.up,&info.down,&info.right,&info.left,&info.deltat);
						printf("%d -- %d -- %d -- %d  -- %d -- %d -- %d -- %d\n",info.x,info.y,info.z,info.up,info.down,info.right,info.left,info.deltat);
		    		}

		    		//clean the buffer for the next message 
					cont = 0;
					memset(msg, 0, 256);	
		    	}
		    }
		    msg[cont++] = ch;
		}			
	}
	
	//Make
	void mySerial::send(string msg){	
		canalSerial << msg << std::endl ;
	}
	
	void mySerial::close(){
		canalSerial.Close();
	}
}
