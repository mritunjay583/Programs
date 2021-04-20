#include<bits/stdc++.h>

using namespace std;

struct node
{

    struct node* link;
    int data;

};

void insert(struct node* arr[],int val,int size)
{
    int key=val%size;
    
    struct node* x=new struct node();   ///allocating memory for node
        x->data=val;
        x->link=NULL;
    
    if(arr[key]==NULL)
    {
        arr[key]=x;
    }
    else
    {
        // inserting at head in link list
        x->link=arr[key];
        arr[key]=x;
    }
    
}

int find(struct node* arr[],int val,int size)
{
    int key=val%size;
    struct node* cur=arr[key];

    while(cur!=NULL)
    {
        if(cur->data==val)
        {
            return 1;   //return 1 if element found
        }
        cur=cur->link;
    }

    return 0;
}

int main()
{
    
    int size=93;
    struct node* arr[size];

    for(int i=0;i<size;i++)
    {
        arr[i]=NULL;
    }
    // inserting in hash
    
    insert(arr,14,size);
    insert(arr,24,size);
    insert(arr,1234,size);
    
    //checking in hash

    cout<<find(arr,24,size)<<endl;  // in hash
    cout<<find(arr,34,size)<<endl; // not in hash
    cout<<find(arr,654754,size)<<endl; // not in hash 
    cout<<find(arr,1234,size)<<endl; // in hash

}