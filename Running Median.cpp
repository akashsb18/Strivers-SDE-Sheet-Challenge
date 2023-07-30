#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap to store the larger half of elements
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (maxHeap.empty() || arr[i] <= maxHeap.top())
        {
            maxHeap.push(arr[i]);
        }
        else
        {
            minHeap.push(arr[i]);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (i % 2 == 0)
        {
            res.push_back(maxHeap.top());
        }
        else
        {
            res.push_back((maxHeap.top() + minHeap.top()) / 2);
        }
    }

    for (auto it : res)
    {
        cout << it << " ";
    }
}
