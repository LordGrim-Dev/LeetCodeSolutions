// Write an algorithm to determine if a number n is happy.


# [202. Happy Number](https://leetcode.com/problems/happy-number/?envType=study-plan&id=programming-skills-i)

<p>
Write an algorithm to determine if a number <code>n</code> is happy.

A <strong>happy number</strong> is a number defined by the following process:
<ul>
<li>Starting with any positive integer, replace the number by the sum of the squares of its digits.</li>
<li>Repeat the process until the number equals 1 (where it will stay), or it <strong>loops endlessly in a cycle</strong> which does not include 1.</li>
<li>Those numbers for which this process <strong>ends in 1</strong> are happy.</li>
</ul>
Return <code>true</code> <em>if <code>n</code> is a happy number, and <code>false</code> if not</em>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 19
<strong>Output:</strong> true
<strong>Explanation</strong><strong>:</strong>
1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 <= n <= 2<sup>31</sup> - 1</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/math/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// One thing to note here is
    // if we continue the the process
    //      seperate number, find square result
    //      seperate square result find its square result.
    // at one point the same sequence will repeat.
    // i.e, for n = 2
    // 4
    // 16
    // 37
    // 58
    // 89
    // 145
    // 42
    // 20
    // 4
class HappyNumber
{
public:
    bool isHappy(int n)
    {
        map<int, int> counter;

        bool isHappyNumber = true;

        long int sqrResult = 0;

        int reminder = 0;
        while (1 && n != 0)
        {
            while (n > 0)
            {
                reminder = n % 10;
                n = n / 10;
                sqrResult = sqrResult + (reminder * reminder);
            }
            n = sqrResult;
            counter[n]++;

            sqrResult = 0;

            // eventually fell in loop of same number if we seperate and square

            if (counter[n] >= 2)
            {
                break;
            }
        }
        if (n != 1)
            isHappyNumber = false;

        return isHappyNumber;
    }
};

class Solution
{
public:
    bool isHappy(int n)
    {
        return HappyNumber().isHappy(n);
    }
};
```