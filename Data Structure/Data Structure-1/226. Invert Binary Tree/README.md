
# [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

<p>
Given the <code>root</code> of a binary tree, invert the tree, and <em>return its root</em>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)
<pre><strong>Input:</strong> root = [4,2,7,1,3,6,9]
<strong>Output:</strong> [4,7,2,9,6,3,1]
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)
<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [2,3,1]
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
    <li><code>-100 <= Node.val <= 100</code></li>
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeOperation
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        TreeNode *newRoot = root;

        if (root)
        {
            invertBinaryTree(newRoot);
        }
        return newRoot;
    }

    void invertBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        //Swaps two values 
        swap(root->left, root->right);

        invertBinaryTree(root->left);

        invertBinaryTree(root->right);
    }
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root)
    {
        return  TreeOperation().invertTree(root);
    }
};
```