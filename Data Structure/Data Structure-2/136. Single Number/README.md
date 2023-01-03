
# [136. Single Number](https://leetcode.com/problems/single-number/?envType=study-plan&id=data-structure-ii)

<p>
Given a <strong>non-empty</strong> array of integers <code>nums</code>, every element appears <em>twice</em> except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,1,2,1,2]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= nums.length <= 3 * 10<sup>4</sup></code></li>
    <li><code>-3 * 10<sup>4</sup> <= nums[i] <= 3 * 10<sup>4</sup></code></li>
    <li>Each element in the array appears twice except for one element which appears only once.</li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// USING BITWISE XOR OPERATOR (USING CONSTANT SPACE )
// To use this approach you first need to understand about Bitwise XOR operator.
// Most of us who have a background in physics ( highschool level ) , are aware of the LOGIC GATES.
// One of such gates is the XOR Gate :
// According to this gate , the output is true , only if both the inputs are of opposite kind .
// That is ,
// A B Y
// 0 0 0
// 0 1 1
// 1 0 1
// 1 1 0

// We apply the extended version of this gate in our bitwise XOR operator.
// If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion ( on each of the corresponding bits of the numbers).
// Similarly , if we observe ,

// A^A=0
// A^B^A=B
// (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
// Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
// Google It for more details.

// We apply the above observations :

// Traverse the array and take the Bitwise XOR of each element.
// Return the value.
// Why does this work ??
// Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
	    for(auto x:nums)
	        ans^=x;
	   return ans;
    }
};
```