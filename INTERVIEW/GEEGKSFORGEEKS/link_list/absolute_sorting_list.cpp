#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void sort_list(struct node* &head)
{
    struct node* pos_s=NULL;
    struct node* pos_e=NULL;
    struct node* neg_s=NULL;
    struct node* neg_e=NULL;
    struct node* cur=head;
    struct node* temp1=NULL;
    struct node* temp2=NULL;
    while(cur)
    {
        int val=cur->data;
        if(val<0)
        {
            if(neg_s==NULL)
            {
                neg_s=cur;
                cur=cur->next;
                temp1=neg_s;
            }
            else
            {
                neg_e=cur;
                cur=cur->next;
                neg_e->next=neg_s;
                neg_s=neg_e;
            }
        }
        else
        {
            if(pos_s==NULL)
            {
                pos_s=cur;
                pos_e=pos_s;
                temp2=pos_s;
            }
            else
            {
                pos_e->next=cur;
                pos_e=pos_e->next;
            }
            cur=cur->next;
        } 
    }
    if(temp1!=NULL)
        temp1->next=temp2;
    if(pos_s!=NULL)
        pos_e->next=NULL;
    else
        temp1->next=NULL;
    if(neg_s!=NULL)
        head=neg_s;
    else
        head=pos_s;

}


int main()
{
    int arr[]={1,-2,-3,-4,-5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    sort_list(l1.head);
    l1.print();
}