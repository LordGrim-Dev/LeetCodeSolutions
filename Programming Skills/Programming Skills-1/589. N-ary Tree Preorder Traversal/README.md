# [589. N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/?envType=study-plan&id=programming-skills-i)

<p>
Given the <code>root</code> of an n-ary tree, return <em>the preorder traversal of its nodes' values</em>.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)
<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [1,3,5,6,2,4]
</pre>


<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)
<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
    <li><code>0 <= Node.val <= 104</code></li>
    <li>The height of the n-ary tree is less than or equal to <code>1000</code>.</li>
</ul>


<p>&nbsp;</p>
<strong>Follow up :</strong> Recursive solution is trivial, could you do it iteratively?

<p>&nbsp;</p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [DFS](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

```cpp
// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples) -->

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class NArryTreePreorderTraversal
{
public:
    vector<int> GetPreOrderOfRoot(Node *root)
    {

        vector<int> Preorder = {};

        stack<Node *> trackingStack;
        if (root)
        {
            trackingStack.push(root);
            while (!trackingStack.empty())
            {
                Node *temp = trackingStack.top();
                trackingStack.pop();
                Preorder.push_back(temp-> val);
                // cout << "\n";
                for (int i = temp->children.size() - 1; i >= 0; i--)
                {
                    // cout<< " "<<i<<" : "<<temp->children[i]->val;
                    trackingStack.push(temp->children[i]);
                }
            }
        }

        return Preorder;
    }
};

// void dfs(Node* root) {
//     if (root == NULL) return;

//     preOrder.push_back(root->val);
//     for(int i=0;i<root->children.size();i++){
//         dfs(root->children[i]);
//     }
// }

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        return NArryTreePreorderTraversal().GetPreOrderOfRoot(root);
    }
};
```