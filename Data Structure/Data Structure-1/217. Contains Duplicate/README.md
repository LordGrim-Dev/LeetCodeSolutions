
# [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/?envType=study-plan&id=data-structure-i)

<p>
Given an integer array <code>nums</code>, return <code>true</code> if any value appears <strong>at least twice</strong> in the array, and return <code>false</code> if every element is distinct.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> false.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,3,3,4,3,2,4,2]
<strong>Output:</strong> true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= nums.length <= 105</code></li>
<li><code>-109 <= nums[i] <= 109</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Hash table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/),
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
class ContainesDuplicateInList {
public:
    bool CheckForDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        for(int i=0;i<n;i++)
        {
            int num =nums[i];
            freq[num] += 1;
            if(freq[num] > 1)
            {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return  ContainesDuplicateInList().CheckForDuplicate(nums);
    }
};
```