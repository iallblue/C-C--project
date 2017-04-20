#include <iostream>

using namespace std;
void get_next(string str, int next[])
{
    int i,j;

    i = 0;//��ָ��(����)
    j = -1;//Ĭ�ϵ�ֵnextֵ
    next[0] = -1;//��ʼ��nextֵ

    while (i < str.length())
    {
        //nextֵ�ߵ���ͷ || ���ҵ��Ͷ�Ӧλ��ֵ��ͬ
        if (j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];//��ö�Ӧλ��nextֵ
    }
}
//��ͨ�Ĳ��Һ���:�±��0��ʼ
int comm_index(string S, string T)
{
    int i,j;

    i = j = 0;
    while (i < S.length() && j < T.length())
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
            //cout << "i=" << i << " j=" << j << endl;
        }
        else
        {
            //ָ�����
            i = i - j + 1;
            j = 0;
        }
    }
    //cout << "i=" << i << " j=" << j << endl;
    if (j >= T.length()) return i - T.length();
    else return -1;
}

int kmp(string S, string T, int next[], int pos)
{
    //��S(������)��pos���ַ��� ��ʼ���ҵ�һ��T�����ֵ�λ��
    //T[]�ǿ� 1 <= pos <= strlen(S)
    int i,j;
    i = pos - 1;
    j = 0;
    int s_len = S.length(), t_len = T.length();
    while (i < s_len && j < t_len)
    {
        //ע����j=-1ʱ,��ʱ˵���Ӵ����Ѿ��Ƚϵ���ͷ�ˣ���Ҫi �� jͬʱ��ǰ���� j -> 0 ��ʱ��i�Ѿ��ȽϹ�����Ҫ��ǰ����
        if (S[i] == T[j] || j == -1)
        {
            i++;
            j++;
        }
        else
        {
            //i���ڻ���
            j = next[j];
        }
        //if (j == -1) cout << "hello" << endl;
        cout << "i=" << i << endl;
    }
    if (j >= t_len)
    {
        return i - T.length();
    }
    else return -1;

}

int main()
{
    string str = "abcabaaabaabcac";
    string fin = "abaabcac";
    int i,n = fin.length();
    int next[n];
    int pos;

    get_next(fin, next);
    for (i = 0; i < n; i++)
    {
        cout << next[i];
    }
    cout <<endl;

    //pos = comm_index(str, fin);
    pos = kmp(str, fin, next, 1);
    cout << "find : " << pos << endl;

    return 0;
}
