rock_library(udp_communication
    SOURCES udpSend.cpp udpRecv.cpp
    HEADERS port.h udpSend.hpp udpRecv.hpp
    DEPS_PKGCONFIG base-types base-lib)


