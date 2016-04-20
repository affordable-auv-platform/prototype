#ifndef UDP_SERIAL_UDPSERIALTASK_TASK_HPP
#define UDP_SERIAL_UDPSERIALTASK_TASK_HPP

#include "udp_serial/UdpSerialTaskBase.hpp"
#include "udp_communication/udpRecv.hpp"
#include "my_serial/mySerial.hpp" 
#include <iostream>
#include <cstring>

using namespace std;

using namespace udp_recv;
using namespace my_serial;

namespace udp_serial {

    class UdpSerialTask : public UdpSerialTaskBase
    {
	friend class UdpSerialTaskBase;
    protected:

    UdpRecv *mpRecv;
    mySerial  *serialLink;
    //unsigned char buf[2048];

    public:

        UdpSerialTask(std::string const& name = "udp_serial::UdpSerialTask", TaskCore::TaskState initial_state = Stopped);

        UdpSerialTask(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state = Stopped);

	    ~UdpSerialTask();

        bool configureHook();

        bool startHook();

        void updateHook();

        void errorHook();

        void stopHook();

        void cleanupHook();
    };
}

#endif

