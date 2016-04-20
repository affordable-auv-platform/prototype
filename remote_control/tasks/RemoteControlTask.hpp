/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef REMOTE_CONTROL_REMOTECONTROLTASK_TASK_HPP
#define REMOTE_CONTROL_REMOTECONTROLTASK_TASK_HPP


#include "controldev/ControlDevTypes.hpp"
#include "remote_control/RemoteControlTaskBase.hpp"
#include "udp_communication/udpSend.hpp"

using namespace controldev;
using namespace udp_send;

namespace remote_control {

    class RemoteControlTask : public RemoteControlTaskBase
    {
	friend class RemoteControlTaskBase;
    protected:
   	
    UdpSend *mpSend;
    RawCommand raw;
    char buf[2048];
	
    public:

        RemoteControlTask(std::string const& name = "remote_control::RemoteControlTask", TaskCore::TaskState initial_state = Stopped);

        RemoteControlTask(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state = Stopped);

		~RemoteControlTask();

        bool configureHook();

        bool startHook();
        
        void updateHook();

        void errorHook();

        void stopHook();

        void cleanupHook();
    };
}

#endif

