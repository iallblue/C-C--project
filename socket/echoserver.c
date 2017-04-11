#include "sockethelp.c"
#include <signal.h>

/********************************************************************
 *
 *
 *	socket��صĸ�������������ֱ��ʹ�ÿͻ��������ϣ����߷���˿�������
 * 
 *
 ********************************************************************/



//ע�⵱˫���������Ӻ󣬿ͻ�����ͨ��clientfd���кͷ����ͨ�ŵģ��������ͨ��connfd�Ϳͻ���ͨ�ŵ�
void dothing(int connfd)
{
	size_t n;
	char buf[MAXLINE];
	char send_buf[MAXLINE];
	my_rio_t rio; //�������ļ�������

	//(������)�ļ���������rio �󶨣����ڶ�ȡ��Ϣ
	my_rio_readinitb(&rio, connfd);


	//��ʱ�����Ϊ���ͻ��˷�����Ϣ��͸��ͻ��˻ظ�һ����Ϣ
	//��ȡ�ͻ��˷�������Ϣ(��ʱ�Ѿ���connfd�Ķ�ȡת��Ϊ ��rio�Ķ�ȡ������������ǿ׳)
	
	
	while ((n = my_rio_readlineb(&rio,buf, MAXLINE )) != 0)
	{
		printf("server received %d bytes \n", n);
		//��ջ�����
		sprintf(send_buf,"you send: %s", buf);
		//���ͻ��˷�����Ϣ
		my_writen(connfd, send_buf,strlen(send_buf));
		//my_writen(connfd, buf, count);
		
	}
	
	//int i = 0;

	/**
	while (1)
	{
		//���ͻ��������Ϸ����ʱ���������Ϣ
		//printf("i am sleep\n");
		//�ַ�����ĸ�ֵ����
		sprintf(send_buf, "\nbye ~~~~");
		my_writen(connfd, send_buf, strlen(send_buf));
		//	sleep(1);
		//	i++;
		//	exit(0);
		//sleep(3);
	}	
	*/
}

/*
//�����д������accept()
int Accept(int listenfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int rc;
	char *err = "unix_error";
	if ((rc = accept(listenfd, addr, addrlen)) < 0)
	{
		fprintf(stderr, "%s : %s\n", err, strerror(errno));
		exit(0);
	}
	return rc;
}
*/

//�źŴ������
void sigchld_handler(int sig)
{

	//���ն���������ӽ���
	while (waitpid(-1, 0, WNOHANG) > 0)
		;
	return;
}

int main()
{	
	int clientfd,listenfd,connfd; //connfd ������������
	char *hostname, *port, client_port[MAXLINE], client_hostname[MAXLINE];	

	//�������Ҫ�Ĳ���
	socklen_t clientlen; //�ͻ����׽��ֳ���
	struct sockaddr_storage clientaddr;//û������Ϊsockaddr_in ��Ϊsockaddr_storage��һ������ͨ�õ��׽��ֽṹ
		
	
	//hostname = "www.baidu.com";
	//���õĴ����ǽ�portת��Ϊ���֣��ַ������׳���bug
	port = "8088";
	//�ͻ���ʹ�õ�clientfd
	//clientfd = open_clientfd(hostname, port);

	//----------------- ���Է����� ---------------
	//����������
	listenfd = Open_listenfd(port);

	//----------------------------------------------
	//	����Ϊ�����
	//----------------------------------------------
	
	//�źŴ������
	signal(SIGCHLD, sigchld_handler);	

	while (1)
	{
		clientlen = sizeof(struct sockaddr_storage); 
		//------------------------------ ע��struct sockaddr * ---------------------------
		//connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
		
		//��ʾ������ʾ��Ϣ
		printf("Listen port: %s \n",port);

		//�����д�����ĺ���(����80�˿ڲ���)
		connfd = Accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
		//printf("%d", connfd);
		//exit(1);

		if (fork() == 0)
		{
			//�ӽ��̹رռ���������
			close(listenfd);
			//��ÿͻ������ӵ��׽�����Ϣ
			//int res = getnameinfo((struct sockaddr *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
			//�������ʾ������Ϣ
			//printf("getnameinfo_id :%d client: %s, port: %s connected \n",res, client_hostname, client_port);			
		
			
			//����˴����߼�
			dothing(connfd);
			close(connfd);
			exit(0);
		}
		
			close(connfd);//�����ڴ�й¶
		
	}
	//printf("clientfd :%d\n", listenfd);
	return 0;

}