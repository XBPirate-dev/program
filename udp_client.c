//udp_client//


#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char array[100];
	int cnct, sock_desc;
	struct sockaddr_in server, client;
	
	sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_desc==-1)
		printf("Error in socket creation\n");
		
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	printf("Enter data to be sent:");
	fgets(array,100,stdin);
	cnct = sendto(sock_desc, array, sizeof(array), 0, (struct sockaddr*)&client, sizeof(client));
	close(sock_desc);
	return 0;
	}
