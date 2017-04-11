#include "sockethelp.c"

/******
 *
 *	�ͻ������ú� Ҫ���ӵ�������ַ �� ����˿�
 *
 *****/

int main(int argc, char **argv)
{
	//�������
	int clientfd;
	char *hostname, *port;
	char send_buf[MAXLINE],receive_buf[MAXLINE];
	my_rio_t rio;
	
	if (argc != 3)
	{
		fprintf(stderr, "%s : arguments error\n",argv[0]);
		exit(0);
	}

	hostname = argv[1];
	port = argv[2];
	//����Ԥ�ȶ���ķ���������clientfd(������������ʱ��˵�������Ѿ������ɹ�)
	//---------------------Ӧ���ô��д�����ĺ�������Ҫ����----------
	clientfd = Open_clientfd(hostname, port);
	//	printf("clientfd is %d", clientfd);
	//	exit(0);
	//��clietnd ��rio�� ��ʼ��
	my_rio_readinitb(&rio, clientfd);

	//��ȡ�������Ϣ
	while (fgets(send_buf, MAXLINE, stdin) != NULL)
	{
		//��Ϣд�뵽clientfd�����͸�����˵Ĺ���
		my_writen(clientfd,send_buf, strlen(send_buf));
		
		//��ȡ����˷�������Ϣ(��ȡ��receive_buf��)
		my_rio_readlineb(&rio, receive_buf, MAXLINE);
		
		//���յ�����Ϣ�������
		fputs(receive_buf, stdout);
	}
	
	close(clientfd);
	return 0;
}