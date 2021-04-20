#include<bits/stdc++.h>
using namespace std;

void printmaxq(priority_queue<int> pq)
{
    priority_queue<int> p=pq;
    while(pq.size()>0)  // gives size of queue
    {
        cout<<pq.top()<<" ";   /// returns top element from queue
        pq.pop(); /// removing top element from queue
    }
    cout<<endl;
}

void printminq(priority_queue<int,vector<int> , greater<int> > pq)
{
    priority_queue<int,vector<int> , greater<int> > p=pq;
    while(pq.size()>0)  // gives size of queue
    {
        cout<<pq.top()<<" ";   /// returns top element from queue
        pq.pop(); /// removing top element from queue
    }
    cout<<endl;
}

int main()
{
    priority_queue<int> pq1; ///max heap priority queue
    priority_queue<int,vector<int> , greater<int> > pq; // min heap priority queue
    pq.push(12);  ///pushing elements in queue
    pq.push(5);
    pq.push(62);
    pq.push(22);
    pq.push(11);
    printminq(pq);
}