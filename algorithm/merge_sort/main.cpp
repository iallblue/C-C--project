#include <iostream>

using namespace std;
/**
 *  �鲢����
 *
 *  �����������飬����������� �鲢��һ�������
 *
 *  ���η����ݹ飺�鲢
 *  ���Ӷ�o(nlogn) ÿһ�˹鲢�ĸ��Ӷ���o(n),����o(logn)��
 */
//int arr_b[]

/*  �鲢����  */
void merge(int arr[], int low, int mid, int high,int n)
{
    /*  ��A[]������,A[low...mid]��A[mid+1...high]���������ϲ�*/
    /*  ��������    */
    int arr2[n];
    int i,j,k;

    /*  ��arr����Ԫ�ظ��Ƶ�����������    */
    for (i = low; i <= high; i++)
    {
        arr2[i] = arr[i];
    }

    //�������бȽ�Ȼ������ԭ������
    for (i = low,j = low,k = mid+1;j <= mid && k <= high; i++)
    {
        if (arr2[j] < arr2[k])
        {
            arr[i] = arr2[j++];
        } else {
            arr[i] = arr2[k++];
        }
    }

    //��ʣ��Ԫ��ֱ�Ӹ��Ƶ�������
    while (j <= mid) /* ��һ������δ�Ƚ����   */
        arr[i++] = arr2[j++];
    while (k <= high) /* �ڶ�������δ�Ƚ����   */
        arr[i++] = arr2[k++];

    /*  ����ֻ��һ��while()�ᱻִ��   */
}

//�ݹ����
 void mergeSort(int arr[], int low, int high, int n)
 {
     /* �ݹ����� */
     if (low < high)
     {
        /*  ���������� */
        int mid = (low + high)/2;
        mergeSort(arr, low, mid, n);
        mergeSort(arr, mid+1, high, n);

        /*  merge   */
        merge(arr, low, mid, high, n);
     }
     //�ݹ����
 }

int main()
{
    int i,arr[10];
    cout << "����10����:" << endl;

    for (i = 0; i < 10; i++)
    {
        cin >>  arr[i];
    }
    mergeSort(arr, 0, 9, 10);
    cout << "�鲢�����:" << endl;

    for (i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
