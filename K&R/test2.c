#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char line[],int maxline);
void copy(char to[], char from[]);

//��extern ���ȫ�ֱ���
char test[] = "this is my life";

int main()
{
//    extern char test[];
//    printf("this is test extern :%s\n", test);
//    return 0;n

    int len;
    int max;
    char line[MAXLINE];//��ǰ������
    char longest[MAXLINE];//��������

    max = 0;
    printf("please input lines(ctrl+z will be end) : \n");
    while ((len = getline(line, MAXLINE)) > 0)
    {
            //��õ�ǰ���Ƿ���ں�������
            if (len > max) {
                max = len;
                copy(longest, line);
            }
    }

    //��������������
    if (max > 0)
    {
        printf("the longest line is : %s",longest);
    }

//    char from[] = "hello";
//    char to[100];
//    copy(to,from);
//    printf("%s", to);
    return 0;
}

int getline(char s[], int lim)
{
    int i = 0;
    char c;

    //��ΪҪ��ȡһ�У����Զ������з� ��Ҫֹͣ��
    for (i; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    //�洢���з�
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;//�α�����
    }
    s[i] = '\0';//�洢��������
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
//    while (from[i] != '\0')
//    {
//        to[i] = from[i];
//        i++;
//    }
    //���ַ����Ὣfrom[i]�е�\0 ���Ƶ�������
    while ((to[i] = from[i]) != '\0')
        i++;
}


