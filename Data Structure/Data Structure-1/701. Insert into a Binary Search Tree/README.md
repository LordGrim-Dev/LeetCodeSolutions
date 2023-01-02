
# [701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

<p>
You are given the <code>root</code> node of a binary search tree (BST) and a <code>value</code> to insert into the tree. Return the root node of the BST <em>after the insertion</em>. It is <strong>guaranteed</strong> that the new value does not exist in the original BST.

<strong>Notice</strong> that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return <strong>any of them<strong>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)
<pre><strong>Input:</strong> root = [4,2,7,1,3], val = 5
<strong>Output:</strong> [4,2,7,1,3,5]
<strong>Explanation:</strong>Another accepted tree is:
</pre>
![referance image](https://assets.leetcode.com/uploads/2020/10/05/bst.jpg)


<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
<strong>Output:</strong> [4,2,7,1,3,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>The number of nodes in the tree will be in the range <code>[0, 10<sup>4</sup>]</code>.</li>
    <li><code>10<sup>8</sup> <= Node.val <= 10<sup>8</sup></code></li>
    <li><code>-10<sup>8</sup> <= val <= 10<sup>8</sup></code></li>
    <li>All the values <code>Node.val</code> are unique.</li>
    <li>It's <strong>guaranteed</strong> that <code>val</code> does not exist in the original BST.</li>
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
class TreeOperation {
public:
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if (!node) {
			TreeNode *newNode = new TreeNode(val);
			return newNode;
		}
		if (val < node->val) {
			node->left = insertIntoBST(node->left, val);
		}
		else {
			node->right = insertIntoBST(node->right, val);
		}
		return node;
    }
    
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        return  TreeOperation().insertIntoBST(node,val);
    }
};
```