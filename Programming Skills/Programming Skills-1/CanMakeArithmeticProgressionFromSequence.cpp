// A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

class CanMakeArithmeticProgressionFromSequence
{
public:
    bool IsApPossible(vector<int> &arr)
    {
        bool isInAP = true;

        sort(arr.begin(), arr.end());

        int n = arr.size(), d = 0;

        // Main condition series in An = a1 + (n-1)d;
        // i.e diffrence between two elements should be same.

        // intial difference;
        if (n >= 2)
            d = arr.at(1) - arr.at(0);

        for (int i = 1; i < n - 1; i++)
        {
            if (d != (arr.at(i + 1) - arr.at(i)))
            {
                isInAP = false;
                break;
            }
        }

        return isInAP;
    }
};

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        return CanMakeArithmeticProgressionFromSequence().IsApPossible(arr);
    }
};