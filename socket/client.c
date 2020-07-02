#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

void *recvMsg(void *arg)
{
	int clientSocket = *(int *)arg;
	
	for(;;){
		char msg[1024];
		int nread = read(clientSocket, msg, 1024);
		msg[nread] = '\0';
		fputs(msg, stdout);
	}
	
	return NULL;
}

int main(void)
{
	int clientSocket=socket(AF_INET, SOCK_STREAM,0);
	assert(clientSocket != -1);
	
	struct sockaddr_in servAddr;
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(7777);
	
	assert(connect(clientSocket, (struct sockaddr *)&servAddr, sizeof(struct sockaddr_in) ) != -1);
	
	//create thread for read() -->print
	pthread_t tid;
	//void *result;
	pthread_create(&tid, NULL, recvMsg, (void*)&clientSocket);
	//pthread_join(tid, &result);
	
	//keyboard -> write
	for(;;){
		char msg[1024];
		fgets(msg, 1024,stdin);
		if(strcmp(msg, "/q\n")==0 || strcmp(msg, "Q\n") == 0)
			break;
		//fputs(msg, stdout);
		write(clientSocket, msg, strlen(msg)); //null \0  not sent. 
	}
	
	
	close(clientSocket);
	return 0;
}
