#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

//max������һ�е��ַ�����(����Ϣ�����line�ַ�������),�����ظ��еĳ���
int getline(char line[], int max);

//��sour�в����Ƿ����search[]�е��ַ�
int strindex(char sour[], char search[]);

char pattern[] = "love";

//�������а���ģʽ����,�����
int main()
{
    char line[MAXLINE];
    int found = 0;

    while ( getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s",line);
            found++;
        }
    }

    return 0;
}

int getline(char str[], int lim)
{
    int i = 0;
    char c;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        str[i] = c;
        i++;
    }
    //׷�ӻ��з�
    if ( c == '\n')
        str[i++] = '\n';
    str[i] = '\0';
    return i;
}

int strindex(char s[], char patt[])
{
    int i,j,k;
    for (i = 0; s[i] != '\0';i++)
    {
        for (j=i,k=0; patt[k] != '\0'; k++,j++)
        {
            if (s[j] != patt[k])
            {
                break;
            }
        }
        if (patt[k] == '\0' && k > 0)
            return i;
    }
    return -1;
}
