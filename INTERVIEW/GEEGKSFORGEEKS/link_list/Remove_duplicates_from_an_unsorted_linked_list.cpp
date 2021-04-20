#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void remove_duplicates(struct node * head)
{
    unordered_set<int> se;
    struct node* cur=head;
    struct node* prev=cur;
    if(cur->next==NULL)return;
    
    se.insert(cur->data);

    while(cur->next!=NULL)
    {
        if(cur->next!=NULL)
        {
            if(se.count(cur->next->data)>0)
            {
                cur->next=cur->next->next;
            }
            else
            {
                se.insert(cur->next->data);
                cur=cur->next;
            }
        }
    }
}


int main()
{
    int arr[]={5,2,2,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    remove_duplicates(l1.head);
    l1.print();
}