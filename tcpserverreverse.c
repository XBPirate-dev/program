#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
         char buf[100], rbuf[100];
         int k;
         socklen_t len;
         int sock_desc,temp_sock_desc;
         struct sockaddr_in server,client;
         sock_desc = socket(AF_INET,SOCK_STREAM,0);
         
         if (sock_desc == -1)
                printf("Error in socket creation.");
         server.sin_family = AF_INET;
         server.sin_addr.s_addr = INADDR_ANY;
         server.sin_port = 3003;
         
         k = bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
         
         if(k==-1)
                printf("Error in binding.");
         k= listen(sock_desc,1);
         
         if(k==-1)
                printf("Error in listening.");
         len = sizeof(client);
         temp_sock_desc = accept(sock_desc,(struct sockaddr*)&client,&len);
         
         if(temp_sock_desc==-1)
                printf("Error in temporary socket creation.");
         
         k=recv(temp_sock_desc,buf,100,0);
         
         
         int j=0, n;
        n = strlen(buf);
        for(int i = n-1; i >= 0; i--)  
        {  
		rbuf[j] = buf[i];  
		j++;  
        }  
    
        for(int d = 0; d < n; d++)
        {
        	buf[d] = rbuf[d];
        }
        k = send(temp_sock_desc, buf, 100, 0);
        close(temp_sock_desc);
        return 0;
}
