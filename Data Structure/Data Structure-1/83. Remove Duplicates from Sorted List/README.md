
# [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

<p>
Given the <code>head</code> of a sorted linked list, <em>delete all duplicates such that each element appears only once. Return the linked list <strong>sorted</strong> as well</em>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)
<pre><strong>Input:</strong> head = [1,1,2]
<strong>Output:</strong> [1,2]
</pre>

<p><strong>Example 2:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)
<pre><strong>Input:</strong> head = [1,1,2,3,3]
<strong>Output:</strong> [1,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the list is in the range <code>[0, 300]</code>.</li>
    <li><code>-100 <= Node.val <= 100</code></li>
    <li>The list is guaranteed to be <strong>sorted</strong> in ascending order.</li>
</ul>


<p>&nbsp;</p>

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

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
    ListNode *deleteDuplicates(ListNode *head)
    {

        ListNode *current = head;

        ListNode *prev = head;

        head = prev; // Final result can be star from First Node of Prev

        while (current != NULL)
        {
            // Check For same element, if so skip same set PreviousPointer to Currunt->next
            if (prev->val == current->val)
            {
                // Current is not Last Node
                if (current->next != NULL)
                {
                    prev->next = current->next;
                }
                else
                {
                    prev->next = NULL;
                }
            }

            // Move previous only if 2 values are different
            if (prev->val != current->val)
                prev = current;

            current = current->next;
        }

        return head;
    }
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        return LinkedList().deleteDuplicates(head);
    }
};
```