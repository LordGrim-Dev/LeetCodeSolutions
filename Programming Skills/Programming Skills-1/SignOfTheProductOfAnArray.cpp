class SignOfTheProductOfAnArray
{
public:
    int IsSignedArray(vector<int> &nums)
    {

        int i = 0;
        int isPositive = 1;

        int n = nums.size();

        int currentNum = 0;
        for (i = 0; i < n; i++)
        {
            currentNum = nums.at(i);
            // product of 0 = result = 0 So break it
            if (currentNum == 0)
            {
                isPositive = 0;
                break;
            }
            // +ve possible positive answer; so +1
            else if (currentNum > 0)
                isPositive *= 1;
            else
                isPositive *= -1; // Negitive might become +ve with one more -ve;
        }

        return isPositive;
    }
};

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        return SignOfTheProductOfAnArray().IsSignedArray(nums);
    }
};