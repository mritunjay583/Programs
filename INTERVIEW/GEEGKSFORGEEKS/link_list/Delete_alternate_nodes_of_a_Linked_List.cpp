#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void delete_alternate_nodes(struct node* head)
{
    struct node* cur=head;
    while(cur && cur->next)
    {
        struct node* temp=cur->next;
        cur->next=cur->next->next;
        free(temp);
        cur=cur->next;
    }
    print(head);
}
void rec_delete_alternate_nodes(struct node* head)
{
    if(head==NULL || head->next==NULL)
        return;
    head->next=head->next->next;
    rec_delete_alternate_nodes(head->next);
}



int main()
{
    int arr[]={1};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    // delete_alternate_nodes(l1.head);
    rec_delete_alternate_nodes(l1.head);
    l1.print();
}