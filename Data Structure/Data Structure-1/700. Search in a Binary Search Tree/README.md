
# [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

<p>
You are given the <code>root</code> of a binary search tree (BST) and an integer <code>val</code>.

Find the node in the BST that the node's value equals <code>val</code> and return the subtree rooted with that node. If such a node does not exist, return <code>null</code>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)
<pre><strong>Input:</strong> root = [4,2,7,1,3], val = 2
<strong>Output:</strong> [2,1,3]
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)
<pre><strong>Input:</strong> root = [4,2,7,1,3], val = 5
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range [1, 5000].</li>
    <li><code>1 <= Node.val <= 10<sup>7</sup></code></li>
    <li><code>root</code> is a binary search tree.</li>
    <li><code>1 <= val <= 10<sup>7</sup></code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/),
[Binary Search tree](https://leetcode.com/tag/binary-tree/),
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
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        return IterativeSearch(root, val); // Iterative
        // or
        // return SearchNode(root, val); // Recurssive
    }

    TreeNode *IterativeSearch(TreeNode *root, int key)
    {
        TreeNode *foundNode = NULL;
        stack<TreeNode *> iterationStack;
        iterationStack.push(root);

        while (!iterationStack.empty())
        {
            TreeNode *temp = iterationStack.top();
            iterationStack.pop();
            if (temp == NULL)
                continue;
                
            if (temp->val == key)
            {
                foundNode = temp;
                break;
            }
            else
            {
                if (key > temp->val)
                {
                    iterationStack.push(root->right);
                    root = root->right;
                }
                else
                {
                    iterationStack.push(root->left);
                    root = root->left;
                }
            }
        }
        return foundNode;
    }

    TreeNode *SearchNode(TreeNode *root, int key)
    {
        if (!root || root->val == key)
            return root;

        if (root->val < key)
            return SearchNode(root->right, key);

        return SearchNode(root->left, key);
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return  TreeOperation().invertTree(root);
    }
};
```