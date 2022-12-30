
# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

<p>
Given the <code>head</code> of a singly linked list, reverse the list, and <em>return the reversed list</em>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)
<pre><strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>


<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
    <li><code>-5000 <= Node.val <= 5000</code></li>
</ul>

<p>&nbsp;</p>

<strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?
<p>&nbsp;</p>

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/),
[Recursion](https://leetcode.com/tag/recursion/)

## Solution 1.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class LinkedList
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = NULL;
        ListNode *temp = NULL;

        while (head != NULL)
        {
            temp = head->next;

            head->next = newHead;

            newHead = head;

            head = temp;
        }
        return newHead;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        return LinkedList().reverseList(head);
    }
};
```