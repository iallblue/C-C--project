#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 *  ����ת
 */
typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *Link;

/* ͷ�巨����������(����) */
Link create_Link(Link &l)
{
    //ͷ��� - ��ʼ��
    l = (LNode *)malloc(sizeof(LNode));
    l->next = NULL;
    LNode *p;
    int i;

    while (cin >> i)
    {
        p =  (LNode *)malloc(sizeof(LNode));
        p->data = i;
        p->next = l->next;

        l->next = p;
    }
    return l;
}
//����ͷ������²��� ֱ�����ñ�
Link reverse(Link &l)
{
    LNode *p,*tmp;

    p = l->next;
    l->next = NULL;//Ϊ�����µ�β�ڵ��ָ����Ϊ��
    //ͷ��
    while (p)
    {
        tmp = p->next;
        p->next = l->next;
        l->next = p; //ͷ���ָ�� �µ�"���ɽڵ��"
        p = tmp;//ָ����һ���ڵ�
    }
    return l;
}

void foreach_Link(Link &l)
{
    l = l->next;
    while (l)
    {
        cout << l->data << endl;
        l = l->next;
    }

}

int main()
{
    Link l;
    l = create_Link(l);
    cout << "�����ڵ�:" << endl;
    l = reverse(l);
    cout << "���������ڵ�:" << endl;
    foreach_Link(l);
    return 0;
}
