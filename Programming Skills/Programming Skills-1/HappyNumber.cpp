// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

class HappyNumber
{
public:
    bool isHappy(int n)
    {
        map<int, int> counter;

        // One thing to note here is
        // if we continue the the process
        //      seperate number, find square result
        //      seperate square result find its square result.
        // at one point the same sequence will repeat.
        // i.e, for n = 2
        // 4
        // 16
        // 37
        // 58
        // 89
        // 145
        // 42
        // 20
        // 4

        bool isHappyNumber = true;

        long int sqrResult = 0;

        int reminder = 0;
        while (1 && n != 0)
        {
            while (n > 0)
            {
                reminder = n % 10;
                n = n / 10;
                sqrResult = sqrResult + (reminder * reminder);
            }
            n = sqrResult;
            counter[n]++;

            sqrResult = 0;

            // eventually fell in loop of same number if we seperate and square

            if (counter[n] >= 2)
            {
                break;
            }
        }
        if (n != 1)
            isHappyNumber = false;

        return isHappyNumber;
    }
};

class Solution
{
public:
    bool isHappy(int n)
    {
        return HappyNumber().isHappy(n);
    }
};