#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    vector<int> st;
    int size = 0;
    Stack(int capacity)
    {
        size = capacity;
    }

    void push(int num)
    {
        st.push_back(num);
    }

    int pop()
    {

        if (st.size() > 0)
        {
            int ele = st.back();
            st.pop_back();
            return ele;
        }
        return -1;
    }

    int top()
    {
        if (st.size() > 0)
        {
            int ele = st.back();
            return ele;
        }
        return -1;
    }

    int isEmpty()
    {
        if (st.size() == 0)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        if (st.size() == size)
        {
            return 1;
        }
        return 0;
    }
};