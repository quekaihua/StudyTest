#include <iostream>
using namespace std;

struct monkey
{
 int num;
 monkey *next;
};

int joseph(int sum, int cycle)
{
    int i;
    monkey *p_old, *p_new, *head=NULL;

    head = new monkey; 
//�˴�����һ��ѭ������(create a circular chained table)
    head->num = 1;
    p_old = head;
    for(i=2; i<=sum; i++)
    {
        p_new = new monkey;
        p_new->num = i;
        p_old->next = p_new;
        p_old = p_new;
    }
 	p_new->next = head;

    p_old = head; 
    i = 1;
//ѭ��ɾ��Ԫ��ֱ��ֻʣ�����һ��Ԫ��(delete elements circularly until the last element left)
    while(1)
    {
        p_new = p_old->next;
        i++;
        if(p_new->next == p_old->next)
            break;
        if((i % cycle) == 0)
        {
            p_old->next = p_new->next;
			p_old = p_new->next;
             delete p_new;
             i = 1;
     	}
        else
        {
            p_old = p_new;
        }
    }

    return p_new->num;
}

int main(void)
{
 int n,m;
 cin>>n>>m;
 cout<<joseph(n,m)<<endl;
 return 0;
}
