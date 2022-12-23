
# [1. Two Sum](https://leetcode.com/problems/two-sum/)

<p>
Given an array of integers <code>nums</code> and an integer <code>target</code>, return indices of the two numbers such that they add up to <code>target</code>.

You may assume that each input would have <strong>exactly one solution</strong>, and you may not use the same element twice.

You can return the answer in any order.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]
<strong>Explanation</strong><strong>:</strong>
Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,4], target = 6
<strong>Output:</strong> [1,2]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>2 <= nums.length <= 10<sup>4</sup></code></li>
    <li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
    <li><code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code></li>
    <li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<p>
<strong>Follow up:</strong> Can you come up with an algorithm that is less than <code>O(n2)</code> time complexity?
</p>

<p>&nbsp;</p>

**Related Topics**:  
[Hash table](https://leetcode.com/tag/hash-table/), [Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
class TwoSumFinder {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j=0;
        int n = nums.size();
        for(int i=0;i< n;i++)
        {
            for(j=i+1;j<n ;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                    break;
                }
            }
        }
        return {0};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return  TwoSumFinder().twoSum(nums,target);
    }
};
```