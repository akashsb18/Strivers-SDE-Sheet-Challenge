#include <bits/stdc++.h>
bool findPattern(string p, string s)
{
    int j = 0;
    if (s.find(p) != string::npos)
    {
        return true;
    }
    return false;
}