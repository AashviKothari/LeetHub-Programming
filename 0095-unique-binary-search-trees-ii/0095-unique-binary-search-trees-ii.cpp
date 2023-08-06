
class Solution {
    vector<TreeNode*> generateTreesHelp(int l, int r) {
        if( l>r ){
            vector<TreeNode*> ans;
            ans.push_back(nullptr);
            return ans;    
        }

        vector<TreeNode*> ans;

        for(int i=l; i<=r; i++){
            // assume i as root node
            vector<TreeNode*> left = generateTreesHelp(l, i-1);
            vector<TreeNode*> right = generateTreesHelp(i+1, r);

            for(auto ln : left){
                for(auto rn : right){
                    TreeNode *root = new TreeNode(i, ln, rn);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelp(1, n);
    }
};