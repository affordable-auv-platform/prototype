#include "RemoteControlTask.hpp"

using namespace remote_control;
     int i = 0;

	RemoteControlTask::RemoteControlTask(std::string const& name, TaskCore::TaskState initial_state)
		: RemoteControlTaskBase(name, initial_state)
	{
		mpSend = new UdpSend();
	}

	RemoteControlTask::RemoteControlTask(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
		: RemoteControlTaskBase(name, engine, initial_state)
	{
		mpSend = new UdpSend();
	}

	RemoteControlTask::~RemoteControlTask()
	{
			if (mpSend != NULL){
			delete mpSend;
			mpSend = NULL;
			}
	}

	bool RemoteControlTask::configureHook()
	{
		if (! RemoteControlTaskBase::configureHook())
			return false;
		return true;
	}

	bool RemoteControlTask::startHook()
	{
		if (! RemoteControlTaskBase::startHook())
			return false;
		
		//Starting the connection	
		mpSend->setup();	
		return true;
	}
	
	void RemoteControlTask::updateHook()
	{	
		//Recive the information from joystick 
		_joy.read(raw);
		
		//Put in a string (Using Axis_Pan(4) insted Axis_Turn(2) at the orogen component of the Joystick)  
		sprintf(buf,"%d;%.f;%.f;%.f;%.f",i,100*raw.axisValue[0][0],100*raw.axisValue[0][1],-100*raw.axisValue[0][2],100*raw.axisValue[1][0]);
		//std::cout << buf << std::endl;
		//Send via UDP 
		mpSend->send(buf);
		
		//Index of strings 
		i++;
		
		RemoteControlTaskBase::updateHook();
	}
	
	void RemoteControlTask::errorHook()
	{
		mpSend->endConection();
		RemoteControlTaskBase::errorHook();
	}
	
	void RemoteControlTask::stopHook()
	{
		mpSend->endConection();
		RemoteControlTaskBase::stopHook();
	}
	
	void RemoteControlTask::cleanupHook()
	{
		mpSend->endConection();
		RemoteControlTaskBase::cleanupHook();
	}
