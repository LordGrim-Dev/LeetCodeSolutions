
// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
// If it is impossible to form any triangle of a non-zero area, return 0

class LargestPerimeterTriangle
{
public:
    int GetLargestPerimeter(vector<int> &nums)
    {
        // Check choosed side makes triangle are not
        // i.e
        // 1. A < C+B
        // 2. b < A+C
        // 3. C < A+B
        // if these 3 condition satisfies then find max Perimeter;

        int a, b, c;
        int i;
        int size = nums.size();
        int maxPerimeter = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++)
        {
            a = nums[i];
            b = nums[i + 1];
            c = nums[i + 2];

            if (a < (b + c) && b < (c + a) && c < (a + b))
            {
                maxPerimeter = max(maxPerimeter, (a + b + c));
            }
        }

        return maxPerimeter;
    }
};

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        return LargestPerimeterTriangle().GetLargestPerimeter(nums);
    }
};
