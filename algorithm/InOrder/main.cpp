#include <iostream>
#include <stack>
using namespace std;
/**
 *  ������� - �ǵݹ�(������)
 *  1.�Ӹ��ڵ㿪ʼ���������ӽ�ջ(���ڵ����Ƚ�ջ)
 *  2.�����ߵ���ͷ,����ջ��,��ʼ��ջ
 *  3.ջ���Һ��ӽ�ջ,�ظ��������
 */
typedef struct BitNode{
    struct BitNode *lchild, *rchild;
    int data;
}BitNode, *BiTree;

void InOrder(BiTree T)
{
    BiTree p = T;
    stack<BiTree>s;

    while (!s.empty() || p)  /*   ջ�ǿ� ���� ���ǿ�*/
    {
        if (p)      /*  �ڵ���� ��ջ*/
        {
            s.push(p->lchild);
            p = p->lchild;
        } else {    /*  �ڵ��ߵ���ͷ����ʼ��ջ�������Һ��ӽڵ�*/
            p = s.top();
            s.pop();/*  ��ջ  */
            cout << p->data << endl;
            p = p->rchild;  /*  ��ʼת�������� */
        }
    }
}

int main()
{

    return 0;
}
