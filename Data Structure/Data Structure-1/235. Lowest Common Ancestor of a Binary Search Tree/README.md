
# [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

<p>
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes <code>p</code> and <code>q</code> as the lowest node in <code>T</code> that has both <code>p</code> and <code>q</code> as descendants (where we allow <strong>a node to be a descendant of itself)</strong>.”
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)
<pre><strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>Output:</strong> 6
<strong>Explanation:</strong> The LCA of nodes 2 and 8 is 6.
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)
<pre><strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong>The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [2,1], p = 2, q = 1
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
    <li><code>-10<sup>9</sup> <= Node.val <= 10<sup>9</sup></code></li>
    <li>All <code>Node.val</code> are unique.</li>
    <li><code>p != q</code></li>
    <li><code>p</code> and <code>q</code> will exist in the BST.</li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/),
[BFS](https://leetcode.com/tag/breadth-first-search/)
[DFS](https://leetcode.com/tag/depth-first-search/)
[Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeOperation
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return lca(root, p->val, q->val);
    }
    TreeNode *lca(TreeNode *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->val > n1 && root->val > n2)
            return lca(root->left, n1, n2);

        if (root->val < n1 && root->val < n2)
            return lca(root->right, n1, n2);

        return root;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return TreeOperation().lowestCommonAncestor(root, p, q);
    }
};
```