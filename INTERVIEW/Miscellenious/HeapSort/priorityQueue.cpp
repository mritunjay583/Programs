#include<bits/stdc++.h>

using namespace std;

class priorityQ{
    vector<int> minHeap;
    void hipify(vector<int>&,int,int);
    int n;
    public:
    priorityQ(){
        n=0;
    }
    int size();
    void push(int x);
    void pop();
    int top();
    void deleteKey(int x);
};

int priorityQ::size(){
    return this->n;
}

void priorityQ::deleteKey(int x){
    int id=-1;
    for(int i=0;i<n;i++){
        if(minHeap[i]==x){
            id=i;
            break;
        }
    }
    if(id==-1){
        cout<<"key is not present"<<endl;
        return ;
    }
    swap(minHeap[0],minHeap[n-1]);
    n--;
    for(int i=n/2-1;i>=0;i--){
        hipify(minHeap,n,i);
    }
}

void priorityQ::pop(){
    if(this->n==0){
        cout<<"underflow"<<endl;
        return;
    }
    swap(minHeap[0],minHeap[n-1]);
    minHeap.pop_back();
    n--;
    for(int i=n/2-1;i>=0;i--){
        hipify(minHeap,n,i);
    }
}
int priorityQ::top(){
    if(n==0){
        cout<<"no element in queue"<<endl;
        return INT_MAX;
    }else{
        return minHeap[0];
    }
}

void priorityQ::hipify(vector<int> &minHeap,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && minHeap[left]<minHeap[smallest])
        smallest=left;
    if(right<n && minHeap[right]<minHeap[smallest])
        smallest=right;
    if(smallest!=i){
        swap(minHeap[i],minHeap[smallest]);
        hipify(minHeap,n,smallest);
    }
}

void priorityQ::push(int x){
    if(this->n==0){
        minHeap.push_back(x);
        n++;
    }else{
        minHeap.push_back(x);
        n++;
        for(int i=n/2-1;i>=0;i--)
            hipify(minHeap,n,i);
    }
}

int main(){
    priorityQ pq;
}