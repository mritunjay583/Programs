#include<bits/stdc++.h>

using namespace std;

class LRUCache
{
public:
    struct node
    {
        int key;
        int value;
        node *next;
        node *prev;
        node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    node *tail, *head;
    unordered_map<int, node *> m;
    int size;

    LRUCache(int capacity)
    {

        size = capacity;
        tail = new node(0, 0);
        head = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        m.clear();
    }

    void add(node *temp) //adding in front
    {
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
    void remove(node *temp)  //remove from any where
    {
        node *p = temp->prev;
        node *n = temp->next;
        p->next = n;
        n->prev = p;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        node *temp = m[key];
        remove(temp);
        add(temp);
        return temp->value;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            m[key]->value = value;
            remove(m[key]);
            add(m[key]);
        }
        else
        {
            if (size <= m.size())
            {
                node *last = tail->prev;
                remove(last);
                m.erase(last->key);
            }
            node *temp = new node(key, value);
            add(temp);
            m[key] = temp;
        }
    }
};