#include <iostream>

using namespace std;

/**
 *
 *  ð������
 */

void bubble_sort(int arr[], int n)   /* n - ���鳤��,��������Ϊָ�봫��ʱ,�޷��������鳤�� */
{
    int i,j,t;
    int flag;

    for (i = 0; i < n-1; i++)
    {
        flag = 1;
        for (j = n-1; j > i; j--)
        {
            //ֻ�б�ǰһ��С�ŷ�������
            if (arr[j] < arr[j-1])
            {
                t = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = t;
                flag = 0;//û��û�з��ͽ���������˵���Ѿ����򣬲���Ҫ�����Ƚ�������
            }
        }

        //�����������
        if (flag) return;
    }

}

int main()
{
    int i,arr[5];

    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    bubble_sort(arr,5);
    for (i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
