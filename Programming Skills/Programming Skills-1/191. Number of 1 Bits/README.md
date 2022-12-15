
# [191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/?envType=study-plan&id=programming-skills-i)

<p>
Write a function that takes an unsigned integer and returns the number of '1' bits it has ( also known as the <strong>Hamming weight</strong> ).
</p>
<p>&nbsp;</p>
<p>
<strong>Note:</strong>

<ul>
<li>Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.</li>
<li>In Java, the compiler represents the signed integers using <strong> 's complement notation</strong>. Therefore, in Example 3, the input represents the signed integer. <code>-3</code>.</li>
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 00000000000000000000000000001011
<strong>Output:</strong> 3.
<strong>Explanation</strong><strong>:</strong>
<code>The input binary string <strong>00000000000000000000000000001011</strong> has a total of three '1' bits.</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 00000000000000000000000010000000
<strong>Output:</strong> 1.
<strong>Explanation</strong>: 
The input binary string <strong>00000000000000000000000010000000</strong> has a total of one '1' bit.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 11111111111111111111111111111101
<strong>Output:</strong> 31.
<strong>Explanation</strong><strong>:</strong>
<code>The input binary string <strong>11111111111111111111111111111101</strong> has a total of thirty one '1' bits.</code>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The input must be a <strong>binary string<strong> of length <code>32</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If this function is called many times, how would you optimize it?
</p>

**Related Topics**:  
[Devide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// Note that in some languages, such as Java, there is no unsigned integer type. 
//      In this case, the input will be given as a signed integer type. 
//      It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.


class NumberofOneBits
{
    
public:
    int GetHammingWeight(uint32_t n)
    {

        // uint32_t count =0;
        // while(n)
        // {
        //     count+=(n&1);
        //     n = (n>>1);
        // }
        // return count;

        return __builtin_popcount(n);
    }
};

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return NumberofOneBits().GetHammingWeight(n);
    }
};
```