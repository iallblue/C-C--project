#include <iostream>

using namespace std;

/*  ȫ�����㷨 */
void swap(char *c1, char *c2)
{
    char t;
    t = *c1;
    *c1 = *c2;
    *c2 = t;
}

/**
 *  �ݹ�������е�ȫ����
 */
 void per(char arr[], int n, int index)
 {
     //�ߵ���ͷ
    if (index >= n)
    {
        for (int i = 0; i < n; ++i)
        {
            //ʼ����һ��arr����,����ÿ�εĵݹ鶼Ҫ����Ԫ��
            cout << arr[i];
        }
        cout << endl;
    }

    //�ݹ����
    for (int i = index;i < n; ++i)
    {
        swap(arr[i], arr[index]);

        per(arr, n, index+1);

        swap(arr[i], arr[index]);
    }
 }

int main()
{
    //cout << "Hello world!" << endl;
    char str[100] = "abc";

    per(str, 3, 0);

    return 0;
}
