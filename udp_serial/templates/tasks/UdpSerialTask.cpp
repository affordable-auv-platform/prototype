/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "UdpSerialTask.hpp"

using namespace udp_serial;

UdpSerialTask::UdpSerialTask(std::string const& name, TaskCore::TaskState initial_state)
    : UdpSerialTaskBase(name, initial_state)
{
}

UdpSerialTask::UdpSerialTask(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : UdpSerialTaskBase(name, engine, initial_state)
{
}

UdpSerialTask::~UdpSerialTask()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See UdpSerialTask.hpp for more detailed
// documentation about them.

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
    return true;
}
void UdpSerialTask::updateHook()
{
    UdpSerialTaskBase::updateHook();
}
void UdpSerialTask::errorHook()
{
    UdpSerialTaskBase::errorHook();
}
void UdpSerialTask::stopHook()
{
    UdpSerialTaskBase::stopHook();
}
void UdpSerialTask::cleanupHook()
{
    UdpSerialTaskBase::cleanupHook();
}
