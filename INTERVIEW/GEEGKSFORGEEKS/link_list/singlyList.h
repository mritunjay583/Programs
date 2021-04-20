#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
    node(int a)
    {
        data=a;
        next=NULL;
    }
};

class SL_list
{
    public:
    struct node* head;
    int size;
    SL_list()
    {
        head=NULL;
        size=0;
    }
    void make_list(int a[],int n)
    {
        for(int i=n-1;i>=0;i--)
        {
            struct node* temp=new struct node(a[i]);
            temp->next=head;
            head=temp;
            size++;
        }
    }
    void print()
    {
        struct node* cur=head;
        while(cur!=NULL)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    int len(){return size;}
    struct node* get_tail()
    {
        struct node* cur=head;
        while(cur->next!=NULL)cur=cur->next;
        return cur;
    }

};

void print(struct node* head,struct node* tail=NULL)
{
    struct node* cur=head;
    while(cur!=tail)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

// int main()
// {
//     SL_list l1;
//     int arr[]={4,22,5,6,2,4,6,2,3};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     l1.make_list(arr,size);
//     l1.print();

// }