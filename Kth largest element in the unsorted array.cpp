#include <bits/stdc++.h>
int kthLargest(vector<int> &arr, int size, int K)
{

    sort(arr.rbegin(), arr.rend());
    return arr[K - 1];
}