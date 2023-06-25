
string longestPalinSubstring(string s)
{
    string ans = "";
    int ansLength = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // For odd length palindromes
        int l = i, r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            if (r - l + 1 > ansLength)
            {
                ans = s.substr(l, r - l + 1);
                ansLength = r - l + 1;
            }
            l--;
            r++;
        }

        // For even length palindromes
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            if (r - l + 1 > ansLength)
            {
                ans = s.substr(l, r - l + 1);
                ansLength = r - l + 1;
            }
            l--;
            r++;
        }
    }
    return ans;
}