// https://www.youtube.com/watch?v=1CxyVdA_654
// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
#include<bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,greater<int> > minHeap;
priority_queue<int> maxHeap;

void balance(){
    if(abs(minHeap.size()-maxHeap.size())<=1)
        return;
    if(minHeap.size()>maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }else{
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
}
void median(){
    if(minHeap.size()==maxHeap.size()){
        cout<<(minHeap.top()+maxHeap.top())/2<<endl;
        return;
    }
    if(minHeap.size()>maxHeap.size())
        cout<<minHeap.top()<<endl;
    else
        cout<<maxHeap.top()<<endl;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cin.ignore();
        if(maxHeap.size()==0){
            maxHeap.push(x);
        }
        else if(x<maxHeap.top()){
            maxHeap.push(x);
        }else{
            minHeap.push(x);
        }
        balance();
        median();
    }
}