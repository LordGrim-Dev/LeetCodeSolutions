
# [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

<p>
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A <strong>valid BST</strong> is defined as follows:
<ul>
<li>The left subtree of a node contains only nodes with keys less than the node's key.</li>
<li>The right subtree of a node contains only nodes with keys greater than the node's key.</li>
<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)
<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

![ref img](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)
<pre><strong>Input:</strong> root = [5,1,4,null,null,3,6]
<strong>Output:</strong> false
<strong>Explanation:</strong>The root node's value is 5 but its right child's value is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range [1, 104].</li>
    <li><code>-2<sup>31</sup> <= Node.val <= 2<sup>31</sup> -1</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [DFS](https://leetcode.com/tag/depth-first-search/),
[BST](https://leetcode.com/tag/binary-search-tree/),
[Binary Tree](https://leetcode.com/tag/binary-tree/)

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
class TreeTraversal {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {   
        return  TreeTraversal().isValidBST(root);
    }
};
```