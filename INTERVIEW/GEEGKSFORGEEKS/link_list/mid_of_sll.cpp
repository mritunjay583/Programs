#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

int get_mid(SL_list &l)
{
    struct node* slow=l.head;
    struct node* fast=slow;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

int main()
{
    int arr[]={1,2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    int mid=get_mid(l1);
    cout<<mid<<endl;
}