#include <bits/stdc++.h>
int atoi(string str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z'))
        {
            continue;
        }
        else
        {
            ans += str[i];
        }
    }
    return stoi(ans);
}