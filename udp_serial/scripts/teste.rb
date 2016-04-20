require 'orocos'
require 'readline'

include Orocos
Orocos.initialize

Orocos.run 'udp_serial::UdpSerialTask' => 'udpSerial' do 

   udpSerial = TaskContext.get 'udpSerial'
    
   udpSerial.start
    
   Readline::readline("Press ENTER to exit\n") do
   end 

end


