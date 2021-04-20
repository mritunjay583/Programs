#include<bits/stdc++.h>

using namespace std;

int pivot(int a[],int start,int end)
{
    srand(time(0));
    int random=rand()%(end-start+1)+start;
    swap(a[random],a[end]);

    int i=start-1;
    int j=start;
    int piv=end;
    while(j<=piv)
    {
        if(a[j]<a[piv])
        {
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    swap(a[i+1],a[piv]);
    return i+1;
}

int K_th_smallest_4_util(int a[],int start,int end,int k)
{
    if(start>end)
        return -1;
    int id=pivot(a,start,end);
    // for(int i=start;i<=end;i++)cout<<a[i]<<" ";cout<<endl;
    // cout<<id<<" "<<a[id]<<endl;
    if(id==k)
        return a[id];
    else if(id<k)
        return K_th_smallest_4_util(a,id+1,end,k);
    else   
        return K_th_smallest_4_util(a,start,id-1,k);
}

// over all complexity will be theta(n) best one
int K_th_smallest_4(int a[],int size,int k)
{   
    if(k>size)
        return -1;
    return K_th_smallest_4_util(a,0,size-1,k);
    
}
//////////////////////////////////////////////////////


// overall complexity will be O(n+klongn)
int K_th_smallest_3(int a[],int size,int k)
{   
    if(k>size)
        return -1;
    
    // modified priority queue (min head) (root is smallest)
    auto cmp=[](int x,int y)->bool{return x>y;};
    priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);

    //this takes O(n) to build heap of n elements
    for(int i=0;i<size;i++)
    {
        pq.push(a[i]);
    }
    int i=0;
    // this takes O((k-1)logn)
    while(i<k-1)
    {
        pq.pop();
        i++;
    }
    // cout<<pq.top()<<endl;
    return pq.top();
    
}



// overall complexity is O(k+(n-k)logk)
int K_th_smallest_2(int a[],int size,int k)
{   
    if(k>size)
        return -1;
    
    // this is by default max heap (root is largest)
    priority_queue<int> pq;

    // building heap of n elemnts takes O(k) time
    for(int i=0;i<k;i++)
    {
        pq.push(a[i]);
    }
    
    //this takes O(n-k)logk in worst case
    for(int j=k;j<size;j++)
    {
        if(a[j]<pq.top())
        {
            pq.pop();
            pq.push(a[j]);
        }
    }

    // cout<<pq.top()<<endl;

    return pq.top();

}

//time O(NlogN)
int K_th_smallest_1(int a[],int size,int k)
{
    if(k>size)
        return -1;
    sort(a,a+size);
    return a[k-1];
}

int main()
{
    int a[]={5,2,6,3,3,5,3,22,1,9,10};
    int size=sizeof(a)/sizeof(a[0]);
    int k=4;
    // int res=K_th_smallest_1(a,size,k);  //O(nlogn)
    // int res=K_th_smallest_2(a,size,k);  //O(n+klongn)
    // int res=K_th_smallest_3(a,size,k);  //O(k+(n-k)logk)
    int res=K_th_smallest_4(a,size,k-1);   //theta(n) , 
                                           // O(n*n) when pivot is bad
    if(res==-1)
        cout<<k<<" is bigger than "<<size<<endl;
    else
        cout<<k<<"th smallest element is : "<<res<<endl;
    
} 