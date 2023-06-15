#include <bits/stdc++.h>
bool isValidParenthesis(string s)
{
    unordered_map<char, char> mp;
    mp['('] = ')';
    mp['{'] = '}';
    mp['['] = ']';
    string st = "";
    st.push_back(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (mp[st.back()] == s[i])
        {
            st.pop_back();
        }
        else
        {
            st.push_back(s[i]);
        }
    }
    if (st.length() == 0)
    {
        return true;
    }
    return false;
}