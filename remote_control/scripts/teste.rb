### Note: Fris stop the server then stop the client ###

require 'orocos'
require 'readline'
include Orocos

## Initialize orocos ##
Orocos.initialize

## Execute the task ##
Orocos.run 'remote_control::RemoteControlTask' => 'remote',
     'controldev::JoystickTask' => 'joystick' do
  
    ## Get the specific task context ##
    remote = Orocos.name_service.get 'remote'
    joystick = Orocos.name_service.get 'joystick'

    ## Connect the ports ## //trocar por rawj
    joystick.raw_command.connect_to remote.joy

    ## Set some properties ##
    joystick.device = "/dev/input/js0" # this might be another port

    ## Configure the tasks ##
    joystick.configure

    ## Start the tasks ##
    joystick.start
    remote.start

    Readline::readline("Press Enter to exit\n") do
    end
end
