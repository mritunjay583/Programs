#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void heapify(int heap[],int start)
{
    int j=start;
    while(1)
    {

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
        print(heap,i+1);     
    }
    print(heap,size);
}

void heap_sort(int arr[],int size)
{
    int heap[size];
    build_heap(heap,arr,size);

    int k=0;
    int l=size-1;
    while(l>=0)
    {
        arr[k++]=heap[0];
        heap[0]=heap[l--];
        heapify(heap,l);
    }
}
int main()
{
    int arr[]={4,2,1,8,6,7,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    heap_sort(arr,size);
    print(arr,size);
}