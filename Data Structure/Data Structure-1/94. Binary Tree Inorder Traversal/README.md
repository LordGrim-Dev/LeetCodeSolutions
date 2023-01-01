
# [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

<p>
Given the <code>root</code> of a binary tree, return the <em>inorder traversal of its nodes'</em> values.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)
<pre><strong>Input:</strong> root = [1,null,2,3]
<strong>Output:</strong> [1,3,2]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
    <li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>
Follow up:</strong> Recursive solution is trivial, could you do it iteratively?
</p>
<p>&nbsp;</p>

**Related Topics**:  
[Binary Tree](https://leetcode.com/tag/binary-tree/), [DFS](https://leetcode.com/tag/depth-first-search/),
[Tree](https://leetcode.com/tag/tree/),
[Stack](https://leetcode.com/tag/stack/)

## Solution 1.

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeTraversal
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        InOrderTravrse(root, result);
        return result;
    }

    void InOrderTravrse(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
            return;

        InOrderTravrse(root->left, result);
        result.push_back(root->val);
        InOrderTravrse(root->right, result);
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root)
    {   
        return  TreeTraversal().inorderTraversal(root);
    }
};
```