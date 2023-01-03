
# [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

<p>
Given the <code>root</code> of a binary search tree and an integer <code>k</code>, return <code>true</code> <em>if there exist two elements in the BST such that their sum is equal to <code>k</code>, or <code>false</code> otherwise</em>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg)
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 9
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg)
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 28
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range [1, 10<sup>4</sup>].</li>
    <li>-10<sup>4</sup> <= Node.val <= 10<sup>4</sup></li>
    <li><code>root</code> is guaranteed to be a <strong>valid</strong> binary search tree.</li>
    <li>-10<sup>5</sup> <= k <= 10<sup>5</sup></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/),
[Two Pointers](https://leetcode.com/tag/two-pointers/),
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
    bool findTarget(TreeNode *root, int k)
    {
        bool targetFound = false;
        if (!root)
            return targetFound;
        else
        {
            vector<int> list;
            TreeToList(root, list);

            int start = 0, tempSum;
            int end = list.size() - 1;
            while (start < end)
            {
                tempSum = list.at(start) + list.at(end);
                if (tempSum == k)
                {
                    targetFound = true;
                    break;
                }
                if (tempSum < k)
                {
                    start++;
                }
                if (tempSum > k)
                {
                    end--;
                }
            }
        }

        return targetFound;
    }

    void TreeToList(TreeNode *root, vector<int> &inList)
    {
        if (!root)
            return;

        TreeToList(root->left, inList);
        inList.push_back(root->val);
        TreeToList(root->right, inList);
    }
};

class Solution {
public:
    bool findTarget(TreeNode *root, int k)
    {
        return  TreeOperation().findTarget(root,k);
    }
};
```