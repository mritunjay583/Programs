
// using merge operation of merge_sort
#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

struct node* intersection(struct node* head1,struct node* head2)
{
    struct node* res=NULL;
    struct node* cur=res;
    struct node* cur1=head1;
    struct node* cur2=head2;
    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1->data<cur2->data)
            cur1=cur1->next;
        else  if(cur1->data>cur2->data)
            cur2=cur2->next;
        else 
        {
            if(res==NULL)
            {
                res=new struct node(cur1->data);
                cur=res;
            }
            else
            {
                cur->next=new struct node(cur1->data);
                cur=cur->next;
            }
            cur1=cur1->next;
            cur2=cur2->next;
        }
    }
    return res;
    
}

int main()
{
    int arr1[]={1,2,4,5,6};
    int arr2[]={2,5,7,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    SL_list l1;
    SL_list l2;
    l1.make_list(arr1,n);
    l2.make_list(arr2,m);
    l1.print();
    l2.print();
    struct node* res=intersection(l1.head,l2.head);
    print(res);
}



