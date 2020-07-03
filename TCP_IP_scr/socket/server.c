#include <unistd.h> 
//unix provided system call -> read/write close
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h> 
#include <pthread.h>
#define TRUE 1

pthread_mutex_t mutex;

int dataSockets[1024];
int count; // counting data sockets

void *handleClient(void *arg)
{
	int dataSock = *(int *)arg; // change it to int*
	int nread;
	char msg[1024]; // max is 1024 but real read num is nread!
	while(nread = read(dataSock, msg, 1024) ){
		pthread_mutex_lock(&mutex);	
		for (int i=0; i<count; ++i){
			write(dataSockets[i], msg, nread);
		}
		pthread_mutex_unlock(&mutex);
		
	}
	//EOF
	close(dataSock);
	return NULL; //no meaning
	
}

int main(void)
{
	pthread_mutex_init(&mutex, NULL);
	int servSock = socket(AF_INET, SOCK_STREAM, 0); //file descriptor
	assert(servSock != -1); //-1 means error
	
	int option;
	socklen_t optionLen = sizeof(option);
	option = TRUE;
	setsockopt(servSock, SOL_SOCKET, SO_REUSEADDR, (void *)&option, optionLen);
	
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //4byte to big endian long type
	servAddr.sin_port = htons(7777); //2byte big endian 
	
	
	assert(bind(servSock, (struct sockaddr *)&servAddr,sizeof(struct sockaddr_in) ) != -1); //struct sent using pointer to reduce overhead
	assert(listen(servSock, 5) != -1);
	
	for(;;){
		int dataSock; 
		struct sockaddr_in clientAddr;
		int len;
		assert( (dataSock = accept(servSock, (struct sockaddr *)&clientAddr, &len)) != -1);
		//assert( (dataSock = accept(servSock, NULL, NULL)) != -1); //don't care about client info
		printf("client IP: %s\n", inet_ntoa(clientAddr.sin_addr)); // inet_ntoa -> chage number to string
		
		pthread_mutex_lock(&mutex);
		dataSockets[count] = dataSock;
		++count;
		pthread_mutex_unlock(&mutex);
		
		//create thread for read()/write()
		pthread_t pid;	
		pthread_create(&pid, NULL, handleClient, (void*)&dataSock);
		pthread_detach(pid); //
	}

	
	close(servSock);
	return 0;
}
