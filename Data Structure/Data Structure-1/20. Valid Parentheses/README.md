
# [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

<p>
Given a string s containing just the characters <code>'('</code>, <code>')'</code>, <code>'{'</code>, <code>'}'</code>, <code>'['</code> and <code>']'</code>, determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.

Open brackets must be closed in the correct order.

Every close bracket has a corresponding open bracket of the same type.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "()"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "()[]{}"
<strong>Output:</strong> true
</pre>


<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong>  s = "(]"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= s.length <= 104</code></li>
    <li><code>s</code> consists of parentheses only '<code>()[]{}'</code>.</li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[String](https://leetcode.com/tag/string/),
[Stack](https://leetcode.com/tag/stack/)

## Solution 1.

```cpp
class StrngOp
{
public:
    bool isValid(string s)
    {
        stack<char> stringStack;
        bool isValid = false;

        if (s.length() <= 1 || s[0] == ')' || s[0] == '}' || s[0] == ']')
            return false;

        int i = 0;
        char top = ' ';

        while (s[i] != '\0')
        {
            switch (s[i])
            {
            case '(':
                stringStack.push(')');
                break;
            case '[':
                stringStack.push(']');
                break;

            case '{':
                stringStack.push('}');
                break;

            case ')':
            case ']':
            case '}':
                if (!stringStack.empty() && i != 0 && stringStack.top() == s[i])
                {
                    stringStack.pop();
                }
                else
                {
                    // PUSH somethimg which has no pair so
                    // stringStack.push('^');

                    // or
                    isValid = false;
                    break;
                }
            }
            i++;
        }

        if (stringStack.empty())
            isValid =  true;
    }
    return isValid;
};

class Solution {
public:
    bool isValid(string s)
    {
        return  StrngOp().isValid(s);
    }
};
```