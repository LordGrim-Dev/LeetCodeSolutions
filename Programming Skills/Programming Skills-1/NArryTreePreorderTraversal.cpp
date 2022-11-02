// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples) -->


// Input: root = [1,null,3,2,4,null,5,6]
// Output: [1,3,5,6,2,4]


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



class NArryTreePreorderTraversal
{
public:
    vector<int> GetPreOrderOfRoot(Node *root)
    {

        vector<int> Preorder = {};

        stack<Node *> trackingStack;
        if (root)
        {
            trackingStack.push(root);
            while (!trackingStack.empty())
            {
                Node *temp = trackingStack.top();
                trackingStack.pop();
                Preorder.push_back(temp->val);
                // cout << "\n";
                for (int i = temp->children.size() - 1; i >= 0; i--)
                {
                    // cout<< " "<<i<<" : "<<temp->children[i]->val;
                    trackingStack.push(temp->children[i]);
                }
            }
        }

        return Preorder;
    }
};

// void dfs(Node* root) {
//     if (root == NULL) return;

//     preOrder.push_back(root->val);
//     for(int i=0;i<root->children.size();i++){
//         dfs(root->children[i]);
//     }
// }

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        return NArryTreePreorderTraversal().GetPreOrderOfRoot(root);
    }
};