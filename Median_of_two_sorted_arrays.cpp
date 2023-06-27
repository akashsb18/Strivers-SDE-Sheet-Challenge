double median(vector<int> &nums1, vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
        return median(nums2, nums1);
    int n1 = nums1.size();
    int n2 = nums2.size();
    int start = 0;
    int end = n1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int rem = (n1 + n2 + 1) / 2 - mid;
        int left1 = INT_MIN;
        int left2 = INT_MIN;
        int right1 = INT_MAX;
        int right2 = INT_MAX;
        if (mid > 0)
        {
            left1 = nums1[mid - 1];
        }
        if (rem > 0)
        {
            left2 = nums2[rem - 1];
        }
        if (mid < n1)
        {
            right1 = nums1[mid];
        }
        if (rem < n2)
        {
            right2 = nums2[rem];
        }
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0;
}