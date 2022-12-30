
# [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)

<p>
Given two strings <code>s</code> and <code>t</code>, return <code>true</code> if <code>t</code> is an anagram of <code>s</code>, and <code>false</code> otherwise.

An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "anagram", t = "nagaram"
<strong>Output:</strong> true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "rat", t = "car"
<strong>Output:</strong> false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= s.length, t.length <= 5 * 10<sup>4</sup></code></li>
    <li><code>s</code> and <code>t</code> consist of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p>
<strong>Follow up:</strong> What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
</p>
<p>&nbsp;</p>

**Related Topics**:  
[Hash table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/),
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// Check the length
// add to map s[i]
// remove from map using t[i]
// if any extra element is there then the value at counter[s[i]] >=1
// then it is not an ANAGRAM;
class StringOp
{
public:
    bool isAnagram(string s, string t)
    {
        int sLength = s.length();
        int tLength = t.length();

        int count[100000] = {0};

        int i = 0, j = 0;

        if (sLength != tLength)
            return false;
        else
        {
            while (s[i] != '\0')
            {
                count[s[i]]++;
                count[t[i]]--;
                i++;
            }

            for (i = 0; i < sLength; i++)
            {
                if (count[s[i]])
                    return false;
            }
            return true;
        }
    }
};
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        return StringOp().isAnagram(s, t);
    }
};
```