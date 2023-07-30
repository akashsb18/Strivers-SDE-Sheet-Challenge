#include <bits/stdc++.h>
long long getInversions(long long *arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j and arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}