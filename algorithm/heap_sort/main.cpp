#include <iostream>

/**
 *  ������
 *  ���Ӷ�o(nlogn) n-1�� û����Ҫlogn�ĸ��Ӷȵ���,����
 *  ���ȶ�
 */
using namespace std;

/*  ����  */
void adjust(int arr[], int k, int len)
{
    int i,tmp;

    for (i = 2 * k; i <= len; i*=2)
    {
        //�������Һ���Ԫ�أ�ѡ����Ҫ��˫�׽����Ľڵ�
        if (i < len && arr[i] < arr[i+1])
            i++;

        //��˫�׽ڵ�Ƚ�
        if (arr[k] < arr[i])
        {
            /*  ����  */
            tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
            /*  ����ɸѡ  */
            k = i;
        }
        else    return;
    }
}

/*  ����(arr[0] �����ʵ��Ԫ��)  len = ʵ�ʳ���-1 */
void build_heap(int arr[], int len)
{
    int i;

    /* ����-��n/2��ʼ */
    for (i = len/2; i > 0; i--)
    {
        adjust(arr, i, len);
    }
}

/*
 *  �����򣺽��ѵĶ���Ԫ��ȡ��,�ŵ��ѵ������,
 *  ��ʣ��Ԫ�����µ����ɶѼ���,��������,�����������
 */
void HeapSort(int arr[], int len)
{
    int i,tmp;

    /*  ��ʼ������   */
    build_heap(arr, len);
    for (i = len; i > 1; i--)//n-1��
    {
        /*  �Ѷ��Ͷ�β����   */
        tmp = arr[i];
        arr[i] = arr[1];
        arr[1] = tmp;

        /*  ���µ���    */
        adjust(arr,1,i-1);  //ֻ��Ҫ�����Ѷ�����
    }
}



int main()
{
    int i,n;/*  ����  */
    int arr[9];
    cout << "����8��Ԫ�أ�" << endl;

    for (i = 1; i <= 8; i++)
    {
        cin >> arr[i];
    }

    cout << "�������"<< endl;
    HeapSort(arr,8);
    for (i = 1; i <= 8; i++)
    {
        cout << arr[i] << endl;;
    }
    return 0;
}
