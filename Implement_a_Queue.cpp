#include <bits/stdc++.h>
class Queue
{
public:
    vector<int> v;
    Queue()
    {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (v.size() == 0)
        {
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        v.push_back(data);
    }

    int dequeue()
    {
        if (v.size() == 0)
        {
            return -1;
        }
        int ans = v[0];
        v.erase(v.begin());
        return ans;
    }

    int front()
    {
        if (v.size() == 0)
        {
            return -1;
        }
        return v[0];
    }
};