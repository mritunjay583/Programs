// becareful array is sorted take advantage of it

#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void find_pair_1(struct node* head,int k)
{
    struct node* i=head;
    struct node* j=head;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data+j->data==k)
            {
                cout<<"("<<i->data<<","<<j->data<<")"<<endl;
            }
        }
    }
}
void find_pair_2(struct node* head,int k)
{
    struct node* i=head;
    struct node* j=i;
    struct node* t=NULL;
    while(i!=t && i!=NULL)
    {
        j=i;
        while(j!=t && j!=NULL)
        {
            if(i->data+j->data==k)
            {
                cout<<"("<<i->data<<","<<j->data<<")"<<endl;
                t=j;
            }
            j=j->next;
        }
        i=i->next;
    }
}


int main()
{
    int arr[]={1,1,1};
    int k=2;
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    // find_pair_1(l1.head,k);
    find_pair_2(l1.head,k);

}