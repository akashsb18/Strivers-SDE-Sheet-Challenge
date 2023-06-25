#include <bits/stdc++.h>

string reverseString(string &s)
{
    string temp = "";
    vector<string> v;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (!temp.empty())
            {
                v.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += s[i];
        }
    }

    if (!temp.empty())
    {
        v.push_back(temp);
    }

    reverse(v.begin(), v.end());

    string ans = "";
    for (int i = 0; i < v.size(); i++)
    {
        ans += v[i];
        if (i != v.size() - 1)
        {
            ans += ' ';
        }
    }

    return ans;
}