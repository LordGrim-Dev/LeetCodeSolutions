// Given an integer number n, return the difference between the product of its digits and the sum of its digits.

class SubtracttheProductandSumofDigitsofanInteger
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0;

        int product = 1;

        while (n != 0)
        {
            int reminder = n % 10;
            n = n / 10;
            sum += reminder;
            product *= reminder;
        }

        return product - sum;
    }
};

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        return SubtracttheProductandSumofDigitsofanInteger().subtractProductAndSum(n);
    }
};