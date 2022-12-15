
# [976. Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/?envType=study-plan&id=programming-skills-i)

<p>Given an integer array <code>nums</code>, return <em>the largest perimeter of a triangle with a non-zero area, formed from three of these lengths</em>. If it is impossible to form any triangle of a non-zero area, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,2]
<strong>Output:</strong> 5.
<strong>Explanation</strong><strong>:</strong>
You can form a triangle with three side lengths: 1, 2, and 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,1,10]
<strong>Output:</strong> 0.
<strong>Explanation</strong>: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>3 <= nums.length <= 104</code></li>
    <li><code>1 <= nums[i] <= 106</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If this function is called many times, how would you optimize it?
</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// Check choosed side makes triangle are not
    // i.e
    // 1. A < C+B
    // 2. b < A+C
    // 3. C < A+B
    // if these 3 condition satisfies then find max Perimeter;
class LargestPerimeterTriangle
{
    
public:
    int GetLargestPerimeter(vector<int> &nums)
    {
       
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

```