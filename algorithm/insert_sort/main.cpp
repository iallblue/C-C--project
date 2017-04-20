#include <iostream>

using namespace std;

void insert_sort(int arr[], int n)
{
    int i,j,t;

    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            //ȡ��������Ԫ��
            t = arr[i];
            //���űȽϣ�Ѱ�Ҳ���λ��(��arr[i]�������ƶ�������λ)
            for (j = i-1; j >= 0; j--)
            {
                if (arr[j] >= t)
                {
                    arr[j+1] = arr[j];//����
                }
                else
                {
                    //�ҵ�������λ��
                    break;
                }
            }
            arr[j+1] = t;
        }
    }
}

void simple_insert(int arr[], int n)
{
    int i,j,t;

    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            //ȡ��������Ԫ��
            t = arr[i];
            //���űȽϣ�Ѱ�Ҳ���λ��(��arr[i]�������ƶ�������λ)
            for (j = i-1; arr[j] >= t && j >= 0; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = t;
        }
    }
}

int main()
{
    int arr[] = {3,1,4,6,2,7,5}, i;
    int len = sizeof(arr)/sizeof(arr[0]);
    simple_insert(arr, len);

    for (i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
