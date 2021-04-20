/*

    deque<int> q;   ///deque
    deque<int> q(4);  /// deque of size 4
    q.pop_back();  ///removing rear element
    q.size();   /// size of deque
    q.pop_front();  ///  removing front element
    q.push_back();  /// inserting in rear
    q.push_front(); /// inserting in front
    q.empty();   /// return true if deque is empty 
    q.front();   //// returns front element
    q.back();  //// return back element
*/




#include<bits/stdc++.h>

using namespace std;

void print(deque<int> &q)
{
    deque<int> temp=q;
    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop_front();
    }
    cout<<endl;
}
int main()
{
    deque<int> q;
    q.push_front(12);
    q.push_front(23);
    q.push_front(1);
    q.push_front(2);
    print(q);
}