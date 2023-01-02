
# [112. Path Sum](https://leetcode.com/problems/path-sum/)

<p>
Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, return <code>true</code> if the tree has a root-to-leaf path such that adding up all the values along the path equals <code>targetSum</code>.

A <strong>leaf</strong> is a node with no children.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)
<pre><strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
<strong>Output:</strong> true
<strong>Explanation:</strong> The root-to-leaf path with the target sum is shown.
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)
<pre><strong>Input:</strong> root = [1,2,3], targetSum = 5
<strong>Output:</strong> false
<strong>Explanation:</strong>There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
    <li><code>-1000 <= Node.val <= 1000</code></li>
    <li><code>-1000 <= targetSum <= 1000</code></li>
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
class TreeTraversal
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool hasPathSum = false;
        vector<int> pathSum;
        if (root)
        {
            int sum = 0;
            DFS(root, pathSum, sum);
            for (auto i : pathSum)
            {
                if (i == targetSum)
                {
                    hasPathSum = true;
                    break;
                }
            }
        }

        return hasPathSum;
    }

    void DFS(TreeNode *root, vector<int> &pathSum, int sum)
    {
        if (!root)
            return;

        sum = sum + root->val;
        if (!root->left && !root->right)
        {
            pathSum.push_back(sum);
        }

        DFS(root->left, pathSum, sum);
        DFS(root->right, pathSum, sum);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum){
        return  TreeTraversal().hasPathSum(root, targetSum);
    }
};
```