
# [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

<p>
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (<code>push</code>, <code>peek</code>, <code>pop</code>, and <code>empty</code>).

Implement the <code>MyQueue</code> class:
<ul>
<li><code>void push(int x)</code> Pushes element x to the back of the queue.</li>
<li><code>int pop()</code> Removes the element from the front of the queue and returns it.</li>
<li><code>int peek()</code> Returns the element at the front of the queue.</li>
<li><code>boolean empty()</code> Returns <code>true</code> if the queue is empty, <code>false</code> otherwise.</li>
</ul>

<strong>Notes:</strong>
<ul>
<li>You must use <strong>only</strong> standard operations of a stack, which means only <code>push to top, peek/pop from top</code>, <code>size</code>, and <code>is empty</code> operations are valid.</li>
<li>Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.</li>
</ul>
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>Output:</strong> [null, null, null, 1, 1, false]
<strong>Explination:</strong>
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= x <= 9</code></li>
    <li>At most <code>100</code> calls will be made to <code>push</code>, <code>pop</code>, <code>peek</code>, and <code>empty</code>.</li>
    <li>All the calls to <code>pop</code> and <code>peek</code> are valid.</li>
</ul>

<p>&nbsp;</p>

<strong>Follow up:</strong> Can you implement the queue such that each operation is amortized <code>O(1)</code> time complexity? In other words, performing <code>n</code> operations will take overall <code>O(n)</code> time even if one of those operations may take longer.

<p>&nbsp;</p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/),
[Design](https://leetcode.com/tag/design/),
[Queue](https://leetcode.com/tag/queue/)

## Solution 1.

```cpp
// Using 2 stack with Push operation making costly here
// while pushing new element have to pop all and put it back to s1
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int top = -1;

        if (!s1.empty())
        {
            top = s1.top();
            s1.pop();
        }

        return top;
    }

    int peek()
    {
        int top = -1;
        if (!s1.empty())
        {
            top = s1.top();
        }
        return top;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```