
# [1502. Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/?envType=study-plan&id=programming-skills-i)

<p>
A sequence of numbers is called an <strong>arithmetic progression</strong> if the difference between any two consecutive elements is the same.

Given an array of numbers <code>arr</code>, return <code>true</code> if <em>the array can be rearranged to form an <strong>arithmetic progression</strong>. Otherwise, return</em> <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,5,1]
<strong>Output:</strong> true
<strong>Explanation</strong><strong>:</strong>
We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 resp
ectively, between each consecutive elements.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4] 
<strong>Output:</strong> false
<strong>Explanation</strong>: 
There is no way to reorder the elements to obtain an arithmetic progression.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 <= arr.length <= 1000</code></li>
	<li><code>-106 <= arr[i] <= 106</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// Main condition series in An = a1 + (n-1)d;
// i.e diffrence between two elements should be same.

// intial difference (d);
class CanMakeArithmeticProgressionFromSequence
{
public:
    bool IsAPPossible(vector<int> &arr)
    {
        bool isInAP = true;

        sort(arr.begin(), arr.end());

        int n = arr.size(), d = 0;

        if (n >= 2)
            d = arr.at(1) - arr.at(0);

        for (int i = 1; i < n - 1; i++)
        {
            if (d != (arr.at(i + 1) - arr.at(i)))
            {
                isInAP = false;
                break;
            }
        }

        return isInAP;
    }
};

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        return CanMakeArithmeticProgressionFromSequence().IsAPPossible(arr);
    }
};
```
