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
class Solution {
public:
vector <int>rightSideView(TreeNode* root) {
vector<int>ans;
if(!root) 
    return ans;

queue<TreeNode*> q;
q.push(root);

while(!q.empty()){
    int n = q.size(),x=0;

for(int i=0; i<n; i++){

    TreeNode *node = q.front();
    q.pop();

    x = node->val;

    if(i == n-1) //current value of element is the value of last visited element in the level of stack
    ans.push_back(x);

if(node->left) q.push(node->left);
if(node->right) q.push(node->right);

}

// ans.push_back(x);
}

return ans;
}
};