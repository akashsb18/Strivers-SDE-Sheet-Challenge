int longestSubSeg(vector<int> &nums, int n, int k)
{
    int maxi = 0;
    int i = 0, j = 0;
    while (i < nums.size())
    {
        if (nums[i] == 0)
        {
            k--;
        }
        if (k < 0)
        {
            if (nums[j] == 0)
            {
                k++;
            }
            j++;
        }
        i++;
    }
    return i - j;
}