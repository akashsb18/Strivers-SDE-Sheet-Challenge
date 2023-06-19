#include <bits/stdc++.h>
class Stack
{
    // Define the data members.

public:
    queue<int> q, q1;
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q.size();
    }

    bool isEmpty()
    {
        if (q.size() == 0)
        {
            return true;
        }
        return false;
    }

    void push(int element)
    {
        q.push(element);
    }

    int pop()
    {
        if (q.size() == 0)
        {
            return -1;
        }
        int ele = q.back();
        while (q.size() > 1)
        {
            q1.push(q.front());
            q.pop();
        }
        q.pop();
        while (!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }

        return ele;
    }

    int top()
    {
        if (q.size() == 0)
        {
            return -1;
        }
        return q.back();
    }
};