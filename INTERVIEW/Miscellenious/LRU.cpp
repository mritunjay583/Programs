//LRU cache

#include <bits/stdc++.h>
#include <deque>
using namespace std;

unordered_map<int, int> um; // adddres -> value
deque<int> dq;              //inserting from front and removing from back
int cap;

void size(int capacity)
{
    um.clear();
    dq.clear();
    cap = capacity;
}

int get(int key)
{
    if (um.find(key) == um.end())
        return -1;
    else
    {
        //if key is available then move key to front of dqueue and return um[key]
        auto x = dq.begin();
        while (*x != key)
        {
            x++;
        }
        dq.erase(x);
        dq.push_front(key);
        return um[key];
    }
}

void sets(int key, int value)
{ //if key is not present
    if (um.find(key) == um.end())
    {
        //if capacity is full then remove last element / remove from back from dqueue and push given key to front of dqueue
        if (cap == dq.size())
        {
            int last = dq.back();
            dq.pop_back();
            um.erase(last);
        }
        um[key] = value;
        dq.push_front(key);
    }
    else // if key is present then move key to front of dqeueu and update key
    {
        auto x = dq.begin();
        while (*x != key)
        {
            x++;
        }
        dq.erase(x);
        dq.push_front(key);
        um[key] = value;
    }
}

int main()
{
    size(3);
    sets(1, 2);
    sets(2, 3);
    sets(3, 4);
    sets(4, 5);
    cout << get(2) << endl;
}