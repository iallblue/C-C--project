#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BNode{
    int data;
    struct BNode *lchild, *rchild;
}BNode, *Bitree;

/*  ����ݹ鴴��������   */
int create_Bitree(Bitree &t)
{
    int data;
    cin >> data;

    if (data == 0)  t = NULL;   /*  �ݹ��������Ľ���  */
    else
    {
        if ((t = (Bitree)malloc(sizeof(BNode))))
        {
            t->data = data;
            create_Bitree(t->lchild);
            create_Bitree(t->rchild);
        }
    }
    return 1;
}


/**
 *  ���ʶ�������k��ڵ�
 *
 *  �ݹ���ʣ�������ת��Ϊ����� ���ڵ��Ҷ�ӽڵ�ĵ� k-1 ��Ľڵ�
 *  �Ӷ����ϵݹ���ʡ�
 *  �ݹ�������������� k - 1�˻���0����
 */
void printNodeAtLevel(BNode *root, int level)
{
    if (root == NULL || level < 0)  /*  �����ĺϷ���� */
    {
        return ;
    }

    if (level == 0) /*  �˻�Ϊ���ڵ�  */
    {
        cout << root->data << " ";
    }

    /*  �ݹ���������� */
    printNodeAtLevel(root->lchild, level-1);
    printNodeAtLevel(root->rchild,level-1);
}

int main()
{
    cout << "����������д���������(0:��ʾ�սڵ�):" << endl;
    Bitree t;
    int res;

    res = create_Bitree(t);
    if (res)
    {
        printNodeAtLevel(t, 2);
    } else {
        cout << "����������ʧ�ܣ�" << endl;
    }
    return 0;
}
