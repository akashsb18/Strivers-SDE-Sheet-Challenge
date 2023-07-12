Count Subarrays with Given XOR #include<bits / stdc++.h> int subarraysXor(vector<int> &arr, int x)
{

    unordered_map<int, int> mp;

    int xorVal = 0;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        xorVal = (xorVal ^ arr[i]);

        if (xorVal == x)
        {
            ans++;
        }

        int req = (xorVal ^ x);

        if (mp.find(req) != mp.end())
        {
            ans += mp[req];
        }

        mp[xorVal]++;
    }

    return ans;
}
