
#include "UdpSerialTask.hpp"

using namespace udp_serial;

	UdpSerialTask::UdpSerialTask(std::string const& name, TaskCore::TaskState initial_state)
		: UdpSerialTaskBase(name, initial_state)
	{
		mpRecv = new UdpRecv();
		serialLink = new mySerial();
	}

	UdpSerialTask::UdpSerialTask(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
		: UdpSerialTaskBase(name, engine, initial_state)
	{
		mpRecv = new UdpRecv();
		serialLink = new mySerial(); 
	}

	UdpSerialTask::~UdpSerialTask()
	{
	    if (mpRecv != NULL){
		    delete mpRecv;
	        mpRecv = NULL;
		}
				
		if (serialLink != NULL){
	 		delete serialLink;
			serialLink = NULL; 					
		}	
				
	}


	bool UdpSerialTask::configureHook()
	{
		if (! UdpSerialTaskBase::configureHook())
			return false;
		return true;
	}
	
	bool UdpSerialTask::startHook()
	{
		if (! UdpSerialTaskBase::startHook())
			return false;
		
		//Starting server 	
		mpRecv->configServer();	
		
		//Config serial 
		//serialLink->setup();	
		return true;
	}
	
	void UdpSerialTask::updateHook()
	{
		
		string msg = mpRecv->listen();
        string cmd; 
         
        //Call the listener 
        if(!msg.empty()){	   
			//std::cout << msg << std::endl;		   	   		
		
			//split the string 	
			char *cmsg = new char[msg.length() + 1];
			strcpy(cmsg, msg.c_str());							
			char *token = std::strtok( cmsg,";");
			
			int cont = 0; 
			
			while (token != NULL) {
				
				//std::cout << token << '\n';
				
				//Comand layer OpenRov Layer 
				switch (cont)
				{
					case 1:
							//Lift
							//std::cout << token << '\n';
							cmd << ";lift(" << token << ");";
							// serialLink->send(cmd);
					break;
					case 3:
							//Throw
							cmd << ";thro(" << token << ");";
							// serialLink->send(cmd);
					break;
					case 4:
							//Yaw						
							cmd << ";yaw(" << token << ");"; 
							// serialLink->send(cmd);
					break;
					default:					
							//Hold functions 
							if (token == "100"){
							  cmd << ";holdHeading_toggle();"; 
							  // serialLink->send(cmd);	
							}else{
							  cmd << ";holdDepth_toggle();"; 
							  // serialLink->send(cmd);
							}
				}		
				
				token = std::strtok(NULL,";");
				cont++;
			}
		   
		   //send the msg to the microcontroler 
		  // serialLink->send(msg);
		}

		UdpSerialTaskBase::updateHook();
	}
	
	void UdpSerialTask::errorHook()
	{
		//closing the conections 
		//mpRecv->close(); 
	    serialLink->close();
		
		UdpSerialTaskBase::errorHook();
	}
	
	void UdpSerialTask::stopHook()
	{
		//closing the conections 
		//mpRecv->close(); 
	    serialLink->close();
		
		UdpSerialTaskBase::stopHook();
	}
	
	void UdpSerialTask::cleanupHook()
	{
		UdpSerialTaskBase::cleanupHook();
	}
