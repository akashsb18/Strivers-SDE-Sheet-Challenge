#include <bits/stdc++.h>
class Queue
{
    // Define the data members(if any) here.

public:
    stack<int> st1, st2;
    Queue()
    {
    }

    void enQueue(int val)
    {
        st1.push(val);
    }

    int deQueue()
    {
        if (st1.size() == 0)
        {
            return -1;
        }
        while (st1.size() > 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        st1.pop();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    int peek()
    {
        if (st1.size() == 0)
        {
            return -1;
        }
        while (st1.size() > 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    bool isEmpty()
    {
        if (st1.size() == 0)
        {
            return true;
        }
        return false;
    }
};
