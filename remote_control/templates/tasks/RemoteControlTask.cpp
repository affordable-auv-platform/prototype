/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "RemoteControlTask.hpp"

using namespace remote_control;

RemoteControlTask::RemoteControlTask(std::string const& name, TaskCore::TaskState initial_state)
    : RemoteControlTaskBase(name, initial_state)
{
}

RemoteControlTask::RemoteControlTask(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : RemoteControlTaskBase(name, engine, initial_state)
{
}

RemoteControlTask::~RemoteControlTask()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See RemoteControlTask.hpp for more detailed
// documentation about them.

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
    return true;
}
void RemoteControlTask::updateHook()
{
    RemoteControlTaskBase::updateHook();
}
void RemoteControlTask::errorHook()
{
    RemoteControlTaskBase::errorHook();
}
void RemoteControlTask::stopHook()
{
    RemoteControlTaskBase::stopHook();
}
void RemoteControlTask::cleanupHook()
{
    RemoteControlTaskBase::cleanupHook();
}
