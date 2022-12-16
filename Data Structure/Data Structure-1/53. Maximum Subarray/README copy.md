
# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/?envType=study-plan&id=data-structure-i)

<p>
Given an integer array <code>nums</code>, find the 
<strong>subarray</strong>
which has the largest sum and return its sum.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6.
<strong>Explanation</strong><strong>:</strong>
[4,-1,2,1] has the largest sum = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
    <li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p>
<strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.
</p>

<p>&nbsp;</p>

**Related Topics**:  
[Hash table](https://leetcode.com/tag/hash-table/), [Devide and Conquer](https://leetcode.com/tag/divide-and-conquer/),
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
class MaxSubArraySum {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxHere = 0;
        
        int tempSum = nums[0] ;
        maxHere = tempSum;
        if(n >=2)
        {
            for(int i=1;i<n;i++)
            {
                if(tempSum < 0 )
                    tempSum = 0;
                
                tempSum += nums[i];

                maxHere = max(maxHere, tempSum);

            }
        }
        
        return maxHere;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return  MaxSubArraySum().maxSubArray(nums);
    }
};
```