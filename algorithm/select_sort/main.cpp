#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  ѡ������
 *  ���Ӷȣ�o(n^2)
 *  ���ȶ� 2 2 1; ����һ������� ��һ��2��ȥ1����
 */

int main()
{
    int i,j,n,min,t;
    vector<int> arr;

    while (cin >> i)
    {
        arr.push_back(i);
    }

    n = arr.size();
    for (i = 0; i < n-1; i++)   //ֻ��Ҫn-1�˼���
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
