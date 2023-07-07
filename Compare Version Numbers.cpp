class Solution
{
public:
    int compareVersion(string s, string t)
    {
        int n = s.length(), m = t.length();

        int n1, n2;
        int i = 0, j = 0;

        while (i < n or j < m)
        {
            n1 = 0, n2 = 0;
            while (i < n and s[i] != '.')
            {
                n1 = n1 * 10 + (s[i] - '0');
                i++;
            }
            while (j < m and t[j] != '.')
            {
                n2 = n2 * 10 + (t[j] - '0');
                j++;
            }
            cout << n1 << " " << n2 << endl;
            if (n1 < n2)
            {
                return -1;
            }
            else if (n1 > n2)
            {
                return 1;
            }
            i++;
            j++;
        }

        return 0;
    }
};