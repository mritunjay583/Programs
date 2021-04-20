#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void segregate(struct node *head) {
    
    struct node* _0s=NULL;
    struct node* _0e=NULL;
    struct node* _1s=NULL;
    struct node* _1e=NULL;
    struct node* _2s=NULL;
    struct node* _2e=NULL;
    struct node* cur=head;
    while(cur)
    {
        int val=cur->data;
        if(val==0)
        {
            if(_0s==NULL)
            {
                _0s=cur;
                _0e=_0s;
            }
            else
            {
                _0e->next=cur;
                _0e=_0e->next;
            }
        }
        if(val==1)
        {
            if(_1s==NULL)
            {
                _1s=cur;
                _1e=_1s;
            }
            else
            {
                _1e->next=cur;
                _1e=_1e->next;
            }
        }
        if(val==2)
        {
            if(_2s==NULL)
            {
                _2s=cur;
                _2e=_2s;
            }
            else
            {
                _2e->next=cur;
                _2e=_2e->next;
            }
        }
        cur=cur->next;
    }
    if(_0e!=NULL)
    _0e->next=_1s;
    if(_1s!=NULL)
    _1e->next=_2s;
    else
    _0e->next=_2s;
    if(_2s!=NULL)
    _2e->next=NULL;
    
    print(_0s);
}



int main()
{
    int arr[]={0,0,0,1,2,2,0,1,1,0,2,0,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    segregate(l1.head);
}