#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;


void merge(node* l1, node* l2) {
        
        node *start=NULL;
        node *end=NULL;

        node *cur1=l1;
        node *cur2=l2;
        while(cur1!=NULL &&cur2!=NULL)
        {
            if(cur1->data>cur2->data)
            {
                if(start==NULL)
                {
                    start=cur1;
                    end=start;
                }
                else
                {
                    end->next=cur1;
                    end=end->next;
                }
                cur1=cur1->next;
            }
            else
            {
                if(start==NULL)
                {
                    start=cur2;
                    end=start;
                }
                else
                {
                    end->next=cur2;
                    end=end->next;
                }
                cur2=cur2->next;
            }
        }
        while(cur1)
        {
            if(start==NULL)
                {
                    start=cur1;
                    end=start;
                }
                else
                {
                    end->next=cur1;
                    end=end->next;
                }
                cur1=cur1->next;
        }
        while(cur2)
        {
            if(start==NULL)
                {
                    start=cur2;
                    end=start;
                }
                else
                {
                    end->next=cur2;
                    end=end->next;
                }
                cur2=cur2->next;
        }
        if(end!=NULL)
        end->next=NULL;

            print(start);
    }

int main()
{
    int arr1[]={5,5,2};
    int arr2[]={8,7,6};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    SL_list l1;
    SL_list l2;
    l1.make_list(arr1,n);
    l2.make_list(arr2,m);
    merge(l1.head,l2.head);
}