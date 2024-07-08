//udp_server


#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char array[100];
	int cnct, len, sock_desc;
	struct sockaddr_in server, client;
	
	sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_desc==-1)
		printf("Error in socket creation\n");
		
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = 3003;
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	cnct = bind(sock_desc, (struct sockaddr *)&server, sizeof(server));
	if(cnct==-1)
		printf("Error in binding\n");
		
	cnct = recvfrom(sock_desc, array, sizeof(array), 0, (struct sockaddr*)&client, sizeof(client));
	printf("Message received from client is: %s\n",array);
	
	close(sock_desc);
	
	return 0;
}
