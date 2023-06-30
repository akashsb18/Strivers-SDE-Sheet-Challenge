#include <iostream>

int findNthNumberWithDigitSum(int targetSum, int n)
{
    int count = 0;
    int num = 19; // Starting from 19 because the digit sum of 10 starts from 19

    while (count < n)
    {
        int tempNum = num;
        int sum = 0;

        while (tempNum > 0)
        {
            sum += tempNum % 10;
            tempNum /= 10;
        }

        if (sum == targetSum)
        {
            count++;
        }

        if (count == n)
        {
            return num;
        }

        num += 9; // Move to the next number with the same number of digits
    }

    return -1; // If the nth number is not found
}

int main()
{
    int targetSum = 10;
    int n = 5; // Find the 5th number with a digit sum of 10

    int nthNumber = findNthNumberWithDigitSum(targetSum, n);

    if (nthNumber != -1)
    {
        std::cout << "The " << n << "th number with a digit sum of " << targetSum << ": " << nthNumber << std::endl;
    }
    else
    {
        std::cout << "Unable to find the " << n << "th number with a digit sum of " << targetSum << std::endl;
    }

    return 0;
}
