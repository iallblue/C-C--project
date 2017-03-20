#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

int main()
{
	pid_t pid[2];
	int i = 0;

	for (i; i < 2; i++) {
		if ((pid[i] = fork()==0)) //child
			exit(100+i);
	}
	int status;
	i = 0;
	pid_t retpid;
	//����������ɾ���ӽ��̵��ڴ���Դ
	while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
		if (WIFEXITED(status)) {
			printf("child process:%d normally exited status=%d\n",retpid, WEXITSTATUS(status));
		} else {
			printf("child process:%d abnormally exited", retpid);
		}
	}

	if (errno != ECHILD)
		fprintf(stderr,"waitpid error");
	return 1;
}
