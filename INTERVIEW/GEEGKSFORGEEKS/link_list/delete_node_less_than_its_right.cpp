#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void compute(struct node *head)
{
    stack<struct node*> st;
    struct node *cur=head;
    while(cur)
    {
        if(st.size()==0)
        {
            st.push(cur);
        }
        else
        {
            while(st.top()->data<cur->data)
            {
                st.pop();
                if(st.size()==0)
                    break;
            }
            st.push(cur);
        }
        cur=cur->next;
    }
    struct node *start=NULL;
    struct node *end=NULL;
    while(st.size()!=0)
    {
        struct node* temp=st.top();
        st.pop();
        if(start==NULL)
        {
            start=temp;
            start->next=NULL;
        }
        else
        {
            temp->next=start;
            start=temp;
        }
    }
    print(start);
}

int main()
{
    int arr[]={3,4,10,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    compute(l1.head);
}