
# [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

<p>
You are given two integer arrays <code>nums1</code> and <code>nums2</code>, sorted in <strong>non-decreasing order</strong>, and two integers <code>m</code> and <code>n</code>, representing the number of elements in <code>nums1</code> and <code>nums2</code> respectively.

<strong>Merge</strong> <code>nums1</code> and <code>nums2</code> into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, <em>but instead be stored inside the array</em> <code>nums1</code>. To accommodate this, <code>nums1</code> has a length of <code>m + n</code>, where the first <code>m</code> elements denote the elements that should be merged, and the last <code>n</code> elements are set to <code>0</code> and should be ignored. <code>nums2</code> has a length of <code>n</code>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
<strong>Output:</strong> [1,2,2,3,5,6]
<strong>Explanation</strong><strong>:</strong>
The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1], m = 1, nums2 = [], n = 0
<strong>Output:</strong> [1]
<strong>Explanation</strong><strong>:</strong>
The arrays we are merging are [1] and [].
The result of the merge is [1].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [0], m = 0, nums2 = [1], n = 1
<strong>Output:</strong> [1]
<strong>Explanation</strong><strong>:</strong>
The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>nums1.length == m + n</code></li>
    <li><code>nums2.length == n</code></li>
    <li><code>0 <= m, n <= 200</code></li>
    <li><code>1 <= m + n <= 200</code></li>
    <li><code>-109 <= nums1[i], nums2[j] <= 109</code></li>
</ul>

<p>&nbsp;</p>
<p>
<strong>Follow up:</strong> Can you come up with an algorithm that runs in <code>O(m + n)</code> time?
</p>

<p>&nbsp;</p>

**Related Topics**:  
[Two Pointer](https://leetcode.com/tag/two-pointers/), [Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
class MergeTwoArray {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if(m!=0)
                nums1.resize(m);
            else
                nums1.clear();
            
            vector<int> temp((m+n),0);
            
            int k=0;
            int i=0;
            int j =0;
            
            while(i<m && j<n)
            {
                if(nums1[i] < nums2[j])
                {
                    temp[k++] = nums1[i++];
                }
                else
                    temp[k++] = nums2[j++];
            }
            
            while(i<m)
                temp[k++] = nums1[i++];
            
            while(j<n)
                temp[k++] = nums2[j++];
            
            nums1 = temp;
        }
    };
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            return  MergeTwoArray().merge(nums1, m, nums2, n);
    }
};
```