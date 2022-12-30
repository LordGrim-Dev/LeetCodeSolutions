
# [383. Ransom Note](https://leetcode.com/problems/ransom-note/)

<p>
Given two strings <code>ransomNote</code> and <code>magazine</code>, return <code>true</code> if <code>ransomNote</code> can be constructed by using the letters from <code>magazine</code> and <code>false</code> otherwise.

Each letter in <code>magazine</code> can only be used once in <code>ransomNote</code>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ransomNote = "a", magazine = "b"
<strong>Output:</strong> false
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> ransomNote = "aa", magazine = "ab"
<strong>Output:</strong> false
</pre>

</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> ransomNote = "aa", magazine = "aab"
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= ransomNote.length, magazine.length <= 105</code></li>
    <li><code>ransomNote</code> and <code>magazine</code> consist of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Counting](https://leetcode.com/tag/counting/)
[String](https://leetcode.com/tag/string/),
[Counting](https://leetcode.com/tag/counting/)

## Solution 1.

```cpp
// Keep Two Map; key = Char and Value = char Count
// Each Map used count seperate string i.e, for ransomNote and Magazine
// Lop through any one of the Map and Check the count of char in other
// if count is greater increse found element count
// At the end Check for ransomNote Map size and Common element count
// if equal means possible to constuct;
// else Not possible
class StringOp
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int i = 0, j = 0;

        map<char, int> magazineMap;

        map<char, int> ransomNoteMap;

        while (magazine[i] != '\0')
        {
            magazineMap[magazine[i++]]++;
        }

        while (ransomNote[j] != '\0')
        {
            ransomNoteMap[ransomNote[j++]]++;
        }

        int countFoundInBoth = 0;

        for (auto i : ransomNoteMap)
        {
            if (magazineMap[i.first] >= i.second)
            {
                countFoundInBoth++;
            }
            else
                return false;
        }

        // i.e if there is difference count of aa to ab
        // i.e aa, aab is valid
        // aabb and ab is invalid
        if (countFoundInBoth == ransomNoteMap.size())
            return true;
        else
            return false;
    }
};

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine){
        return StringOp().canConstruct(ransomNote, magazine);
    }
};
```