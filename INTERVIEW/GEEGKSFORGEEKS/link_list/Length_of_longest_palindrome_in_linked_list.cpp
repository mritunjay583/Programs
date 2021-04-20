#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

int cnt(struct node* a,struct node* b)
{
    int temp=0;
    while(a!=NULL && b!=NULL)
    {
        if(a->data==b->data)
            temp++;
        else 
            break;
        a=a->next;
        b=b->next;
    }
    return temp;
}

int longest_palindrome(struct node* head)
{
    struct node* cur=head;
    struct node* prev=NULL;
    struct node* next=cur->next;
    int res=1;
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        res=max(res,2*cnt(prev,next)+1);
        res=max(res,2*cnt(cur,next));
        prev=cur;
        cur=next;
    }
    head=prev;
    return res;
}

int main()
{
    int arr[]={2,3,7,3,2,12,24};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    int length=longest_palindrome(l1.head);
    cout<<length<<endl;
}