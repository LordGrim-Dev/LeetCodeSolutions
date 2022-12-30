
# [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan&id=data-structure-i)

<p>
Given the <code>root</code> of a binary tree, <em>return its maximum depth</em>.

A binary tree's <strong>maximum depth</strong> is the number of nodes along the longest path from the root node down to the farthest leaf node.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)
<pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> root = [1,null,2]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
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
class TreeTraversal {
public:
    int maxDepth(TreeNode* root) {
     
        int count =0;
        if(root == NULL)
            return count;
        else
        {
            queue<TreeNode *> treCountQueue;
            TreeNode *temp = root;
            //USe NULL as indicator for each level seperatio.n
            // If element push it
            // if NULL push one more NULL for lext level;
            treCountQueue.push(root);
            treCountQueue.push(NULL);
            
            while(!treCountQueue.empty())
            {
                temp = treCountQueue.front();
                treCountQueue.pop();
                
                if(temp == NULL)
                    count++;
                
                if(temp!=NULL)
                {
                    if(temp->left) treCountQueue.push(temp->left);
                    if(temp->right) treCountQueue.push(temp->right);
                
                }
                
                else if(!treCountQueue.empty())
                {
                    treCountQueue.push(NULL);
                }
            }
        }
            return count;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return  TreeTraversal().maxDepth(root);
    }
};
```