
# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/?envType=study-plan&id=data-structure-i)

<p>
Given the <code>root</code> of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
<pre><strong>Input:</strong>  root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[9,20],[15,7]]
</pre>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>


<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
    <li><code>-1000 <= Node.val <= 1000</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/),
[BFS](https://leetcode.com/tag/breadth-first-search/)
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

// -------------------------------------------------------------------------
// Using Queue to push one level. i.e left and right.
// then in next iteration till queue empty pop all and note down.
// And check if it is having left and right Childe
// If there push else continue.
// -------------------------------------------------------------------------

class TreeTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root)
            return result;
        else
        {
            queue<TreeNode*> treeQue;
        
            treeQue.push(root);
            
            vector<int> temp;
            while(!treeQue.empty())
            {
                int n= treeQue.size();
                
                for(int i=0;i<n;i++)
                {
                    TreeNode* trreTop = treeQue.front();
                    treeQue.pop();
                    
                    if(trreTop)
                        temp.push_back(trreTop->val);
                    
                    if(trreTop->left)
                        treeQue.push(trreTop->left);

                    if(trreTop->right)
                        treeQue.push(trreTop->right);
                }
                
                result.push_back(temp);
                
                temp.clear();
            }
            
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return  TreeTraversal().levelOrder(root);
    }
};
```