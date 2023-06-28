int NthRoot(int n, int m)
{

    if (n == 1 or m == 1)
    {
        return m;
    }
    int l = 0, r = m;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) > m)
        {
            r = mid - 1;
        }
        else if (pow(mid, n) < m)
        {
            l = mid + 1;
        }
    }
    return -1;
}