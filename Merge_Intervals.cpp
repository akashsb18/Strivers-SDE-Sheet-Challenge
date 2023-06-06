
vector<vector<int>> mergeIntervals(vector<vector<int>> &x)
{
    vector<vector<int>> v;
    if (x.size() == 0)
    {
        return v;
    }
    sort(x.begin(), x.end());

    vector<int> y = x[0];

    for (auto it : x)
    {
        if (it[0] <= y[1])
        {
            y[1] = max(it[1], y[1]);
        }
        else
        {
            v.push_back(y);
            y = it;
        }
    }

    v.push_back(y);
    return v;
}
