
# [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/?envType=study-plan&id=data-structure-i)

<p>
Given the <code>root</code> of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)
<pre><strong>Input:</strong>  root = [1,2,2,3,4,4,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)
<pre><strong>Input:</strong> root = [1,2,2,null,3,null,3]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree is in the range<code>[1, 1000]</code>.</li>
    <li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p>&nbsp;</p>

<strong>Follow up:</strong> Could you solve it both recursively and iteratively?

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
class TreeOperation {
public:
    bool isSymmetric(TreeNode* root) {
        bool isSymmetric = true;
        
        if(root==NULL)
            return false;
        else
        {
            
         /*    ITerative Solution
         
         queue<TreeNode*> nodeQueue;
            TreeNode* leftNode, *rightNode;
            
            nodeQueue.push(root);
            
            nodeQueue.push(root);
            
            while(!nodeQueue.empty())
            {
                leftNode = nodeQueue.front();
                nodeQueue.pop();
                
                
                rightNode = nodeQueue.front();
                nodeQueue.pop();
                
                if(leftNode->val != rightNode->val)
                {
                    isSymmetric = false;
                    break;
                }
                
                if(leftNode->left && rightNode->right)
                {
                     nodeQueue.push(leftNode->left);
                     nodeQueue.push(rightNode->right);
                }
                else if(leftNode->left || rightNode->right)
                {
                    isSymmetric= false;
                    break;
                } 
                
                if(leftNode->right && rightNode->left)
                {
                     nodeQueue.push(leftNode->right);
                     nodeQueue.push(rightNode->left);
                }
                else if(leftNode->right || rightNode->left)
                {
                    isSymmetric= false;
                    break;
                } 
            }
        }*/
            //Recusive Solution    
            return IsMirror(root,root);
        }
    }
    
    bool IsMirror(TreeNode* left, TreeNode * right)
    {
    
        if (left == NULL && right == NULL)
        return true;
     
        if (left && right && left->val == right->val)
        return IsMirror(left->left, right->right)
               && IsMirror(left->right, right->left);
 
    return false;
  }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return  TreeOperation().isSymmetric(root);
    }
};
```