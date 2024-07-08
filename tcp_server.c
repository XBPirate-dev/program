//tcp_server//

#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
	char buff[100];
	int k;
	socklen_t len;
	int sock_desc, temp_sock_desc;
	struct sockaddr_in server, client;
	
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_desc==-1)
		printf("Error in socket creation\n");
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = 3003;
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	k = bind(sock_desc, (struct sockaddr *)&server, sizeof(server));
	if(k==-1)
		printf("Error in binding\n");
	k=listen(sock_desc,1);
	if(k==-1)
		printf("Error in listening\n");
	
	len = sizeof(client);
	temp_sock_desc = accept(sock_desc, (struct sockaddr *)&client, &len);
	if(temp_sock_desc==-1)
		printf("Error in temporary socket creation\n");
		
	k = recv(temp_sock_desc, buff, 100, 0);
	printf("Message received from client is: %s\n",buff);
	
	close(temp_sock_desc);
	return 0;
}
