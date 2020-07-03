#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

void error_handling(char *message);
void * handle_clnt(void * arg);
#define BUF_SIZE 100
#define MAX_CLNT 256

int main(int argc, char *argv[])
{

	int  serv_sock;
	int clnt_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	pthread_t t_id;

	if(argc!=2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");
	printf("server socket = %d\n", serv_sock);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; // IPv4
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1) //casting
		error_handling("bind() error");
	if(listen(serv_sock, 5)==-1)
		error_handling("listen () error");

	while(1){
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

	if(clnt_sock == -1)
		error_handling("accept() error");
	pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);
	pthread_detach(t_id);

	printf("Connected client IP: %s \n", inet_ntoa(clnt_addr.sin_addr));
	}

	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void * handle_clnt(void * arg) //thread
{
	int clnt_sock=*((int*)arg);
	int str_len=0;
	char msg[BUF_SIZE];

	while(1){
		memset(msg, 0, sizeof(BUF_SIZE));
		str_len=read(clnt_sock, msg, sizeof(msg)-1);
		if(str_len == -1){
			printf("finish\n"); break;
		}
		if(!strcmp(msg, "LED_OON\n")){ //LED_ON not work
			printf("message : %s\n", msg);
		}
		else if(!strcmp(msg, "LED_OFF\n")){
			printf("message : %s\n", msg);
		}
	}
	close(clnt_sock);
	return NULL;
}


void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
