#include "udpSend.hpp"
 
namespace udp_send
{		
	struct sockaddr_in myaddr, remaddr;
	int fd, i, slen = sizeof(remaddr);
	//char *server = "169.254.1.2";
	//char *server = "192.168.7.2";
	char *server = "127.0.0.1";
	char buf[BUFLEN];
	
	
	UdpSend::UdpSend(){
	}

	UdpSend::~UdpSend(){
	}

    void UdpSend::setup(){

		/* create a socket */
		if ((fd=socket(AF_INET, SOCK_DGRAM, 0))==-1)
			printf("socket created\n");

		/* bind it to all local addresses and pick any port number */
		memset((char *)&myaddr, 0, sizeof(myaddr));
		myaddr.sin_family = AF_INET;
		myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		myaddr.sin_port = htons(0);

		if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
			perror("bind failed");
		}       

		/* now define remaddr, the address to whom we want to send messages */
		/* For convenience, the host address is expressed as a numeric IP address */
		/* that we will convert to a binary format via inet_aton */
		memset((char *) &remaddr, 0, sizeof(remaddr));
		remaddr.sin_family = AF_INET;
		remaddr.sin_port = htons(SERVICE_PORT);
		if (inet_aton(server, &remaddr.sin_addr)==0) {
			fprintf(stderr, "inet_aton() failed\n");
			exit(1);
		}	
	}	
		
    void UdpSend::send(char output[]){	

		//printf("Sending packet %d to %s port %d\n", i, server, SERVICE_PORT);
		//sprintf(buf, "%s", output);
		printf("%s\n",output);
		
		if (sendto(fd, output, strlen(output), 0, (struct sockaddr *)&remaddr, slen)==-1)
			perror("sendto");	
				
	}

	void UdpSend::endConection(){	
		close(fd);
	}

}
