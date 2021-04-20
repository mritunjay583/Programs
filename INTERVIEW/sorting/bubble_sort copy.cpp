#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void heapify(int heap[],int boundry)
{
    int j=0;
    while(j<=boundry)
    {
        int a=2*j+1;
        int b=2*j+1;
        if(a<b)
        {
            if(heap[j]<heap[a])
            swap(heap[j],heap[a]);
            j=a;
        }
        else
        {
            if(heap[j]<heap[b])
            swap(heap[j],heap[b]);
            j=b;
        }
    }
}
void build_heap(int heap[],int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        heap[i]=INT_MIN;
    }
    for(int i=0;i<size;i++)
    {
        heap[i]=arr[i];
        heapify(heap,i);
    }

    int k=0;
    int l=size-1;
    while(l>=0)
    {
        arr[k++]=heap[0];
        heap[0]=heap[l--];
        heapify(heap,l);
    }
}

void heap_sort(int arr[],int size)
{
    int heap[size];
    build_heap(heap,arr,size);
}
int main()
{
    int arr[]={8,4,7,1,6,2,34,6,7,84,345,64,21,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    heap_sort(arr,size);
    print(arr,size);
}