int search(int *arr, int n, int target)
{
    int l = 0, r = n - 1, pivot = -1;
    int last = arr[n - 1];

    if (n == 1)
    {
        if (target == arr[0])
        {
            return 0;
        }
        return -1;
    }

    while (l <= r)
    {

        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[l] <= arr[mid])
        {

            if (arr[l] <= target and target <= arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        else
        {
            if (arr[mid] < arr[r])
            {
                if (target >= arr[mid] and target <= arr[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
    }
    return -1;
}