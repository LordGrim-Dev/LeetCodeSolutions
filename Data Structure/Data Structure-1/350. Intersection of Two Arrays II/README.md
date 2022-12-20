
# [350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/?envType=study-plan&id=data-structure-i)

<p>
Given two integer arrays <code>nums1</code> and <code>nums2</code>, return an <em>array of their intersection</em>. Each element in the result must appear as many times as it shows in both arrays and you may return the result in <strong>any order</strong>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2,2].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [4,9].
<strong>Explanation</strong><strong>:</strong> [9,4] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= nums1.length, nums2.length <= 1000</code></li>
    <li><code>0 <= nums1[i], nums2[i] <= 1000</code></li>
</ul>


<p>&nbsp;</p>
<p>
<strong>Follow up:</strong> 
<p>
    <ul>
        <li>What if the given array is already sorted? How would you optimize your algorithm?</li>
        <li>What if <code>nums1's</code> size is small compared to <code>nums2's</code> size? Which algorithm is better?</li>
        <li>What if elements of <code>nums2</code> are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?</li>
    </ul>
</p>

<p>&nbsp;</p>

**Related Topics**:  
[Hash table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/),
[Array](https://leetcode.com/tag/array/),
[Two Pointers](https://leetcode.com/tag/two-pointers/),
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1.

```cpp
class ListIntersection {
public:
    vector<int> CheckForDuplicate(vector<int>& nums1, vector<int>& nums2) {
       map<int,int> numberMap;
        
        int i=0;
        for(i=0;i<nums1.size();i++)
        {
            numberMap[nums1[i]]++;
        }
        
        nums1.clear();
        
        for(i =0;i<nums2.size();i++)
        {
            if(numberMap[nums2[i]]>0)
            {
                nums1.push_back(nums2[i]);
                numberMap[nums2[i]]--;
            }
        }
        return nums1;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        return  ListIntersection().CheckForDuplicate(nums1,nums2);
    }
};
```