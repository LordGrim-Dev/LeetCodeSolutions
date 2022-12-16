# [1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/?envType=study-plan&id=programming-skills-i)

<p>There is a function <code>signFunc(x)</code> that returns:
<ul>
<li><code>1</code> if <code>x</code> is positive.</li>
<li><code>-1</code> if <code>x</code> is negative.</li>
<li><code>0</code> if <code>x</code> is equal to <code>0</code>.</li>
</ul>
You are given an integer array <code>nums</code>. Let <code>product</code> be the product of all values in the array <code>nums</code>.

Return <code>signFunc(product)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-2,-3,-4,3,2,1]
<strong>Output:</strong> 1
<strong>Explanation</strong><strong>:</strong>
The product of all values in the array is 144, and signFunc(144) = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,5,0,2,-3]
<strong>Output:</strong> 0
<strong>Explanation</strong><strong>:</strong>
The product of all values in the array is -1, and signFunc(-1) = -1
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,1,-1,1,-1]
<strong>Output:</strong> -1
<strong>Explanation</strong>: 
The product of all values in the array is -1, and signFunc(-1) = -1
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
    <li><code>-100 <= nums[i] <= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
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
```