
# [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

<p>

Given <code>head</code>, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the <code>next</code> pointer. Internally, <code>pos</code> is used to denote the index of the node that tail's <code>next</code> pointer is connected to.<strong> Note that <code>pos</code> is not passed as a parameter.</strong>

Return <code>true</code> <em>if there is a cycle in the linked list.</em> Otherwise, return <code>false</code>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)
<pre><strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> true.
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
</pre>

<p><strong>Example 2:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

<pre><strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> true.
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 0th node.
</pre>

<p><strong>Example 3:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

<pre><strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> false.
<strong>Explanation:</strong> There is no cycle in the linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>The number of the nodes in the list is in the range [0, 10<sup>4</sup>].</code></li>
    <li><code>-10<sup>5</sup> <= Node.val <= 10<sup>5</sup></code></li>
    <li><code>pos</code> is <code>-1</code> or a valid index in the linked-list.</li>
</ul>

<p>&nbsp;</p>

<p><strong>
Follow up:</strong> Can you solve it using <code>O(1)</code> (i.e. constant) memory?
</p>
<p>&nbsp;</p>

**Related Topics**:  
[Hash table](https://leetcode.com/tag/hash-table/), [Linked List](https://leetcode.com/tag/linked-list/),
[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// have one empty pointer to which all nodes going to point.
//  if for head->next == temp then cycle exist
//  else no cycle;
class LinkedList
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = new ListNode();

        ListNode *next = NULL;

        while (head != NULL)
        {
            if (head->next == NULL)
                return false;

            if (head->next == temp)
                return true;

            next = head->next;

            head->next = temp;

            head = next;
        }
        return false;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head){    
        return  LinkedList().hasCycle(head);
    }
};
```