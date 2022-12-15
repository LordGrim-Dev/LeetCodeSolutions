# [1281. Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/?envType=study-plan&id=programming-skills-i)

<p>Given an integer number <code>n</code>, return the difference between the product of its digits and the sum of its digits.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>  n = 234
<strong>Output:</strong> 15 
<strong>Explanation</strong><strong>:</strong>
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4421
<strong>Output:</strong> 21
<strong>Explanation</strong>: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 <= n <= 10^5</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
class SubtracttheProductandSumofDigitsofanInteger
{
    
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0;

        int product = 1;

        while (n != 0)
        {
            int reminder = n % 10;
            n = n / 10;
            sum += reminder;
            product *= reminder;
        }

        return product - sum;
    }
};

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        return SubtracttheProductandSumofDigitsofanInteger().subtractProductAndSum(n);
    }
};
```