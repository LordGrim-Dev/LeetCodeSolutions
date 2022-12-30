
# [387. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)

<p>
Given a string <code>s</code>, find the first non-repeating character in it and return its index. If it does not exist, return <code>-1</code>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 0
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "loveleetcode"
<strong>Output:</strong> 2
</pre>

</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aabb"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= s.length <= 10<sup>5</sup></code></li>
    <li><code>s</code> consists of only lowercase English letters.</li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Counting](https://leetcode.com/tag/counting/)
[Queue](https://leetcode.com/tag/queue/),
[String](https://leetcode.com/tag/string/)
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// Keep one Map : Dictionary<int,int>  where
// key = Char
// Val = count (number of occurance)

// Traverse through Map and Check the char count
// return the first index with count ==1
class StringOp
{
public:
    int firstUniqChar(string s)
    {
        int i = s.length();

        map<int, int> counter;
        // int index =0;

        while (i >= 0)
        {
            counter[s[i]]++;

            i--;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (counter[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        return StringOp().firstUniqChar(s);
    }
};
```