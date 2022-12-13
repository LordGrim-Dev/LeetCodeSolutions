# [1523. Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range?envType=study-plan&id=programming-skills-i)

Given two non-negative integers <code>low</code> and <code>high</code>. Return the count of odd numbers between <code>low</code> and <code>high</code> (inclusive).

<p>You are given an m x n</code> integer grid <code>accounts</code> where <code>accounts[i][j]</code> is the amount of money the <code>i​​​​​<sup>​​​​​​th</sup>​​​​</code> customer has in the <code>j​​​​​<sup>​​​​​​th</sup></code>​​​​ bank. Return<em> the <strong>wealth</strong> that the richest customer has.</em></p>

<p>A customer's <strong>wealth</strong> is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum <strong>wealth</strong>.</p>

Explanation: The odd numbers between 8 and 10 are [9].
 
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> low = 3, high = 7
<strong>Output:</strong> 3
<strong>Explanation</strong><strong>:</strong>
<code>The odd numbers between 3 and 7 are [3,5,7].</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> low = 8, high = 10
<strong>Output:</strong> 1
<strong>Explanation</strong>: 
Explanation: The odd numbers between 8 and 10 are [9].</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 <= low <= high <= 10^9</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
class CountOddNumbersinanIntervalRange
{

public:
    int countOdds(int low, int high)
    {
        // Check for last bit 1 or not, if 1 = OddNumber
        //  if 0 = event number;

        // difference = high-low
        // if high is ODD -> then there will be a difference+1 oddNubers

        if (high & 1 == 1 || low & 1 == 1)
            return ((high - low) / 2) + 1;
        else
            return (high - low) / 2;
    }
};
```