#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

void print(struct node* &head)
{
    head=NULL;
    
}
int main()
{
    struct node* head=NULL;
    head=new struct node(10);
    head->next=new struct node(20);
    head->next->next=new struct node(30);
    head->next->next->next=new struct node(40);
    print(head);
    if(head!=NULL)
    cout<<head->next->data<<endl;
}