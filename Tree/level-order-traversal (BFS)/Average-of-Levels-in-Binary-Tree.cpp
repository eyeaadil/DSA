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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum = 0;
            int count = n;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            double avg = sum/count;
            ans.push_back(avg);
        }

        return ans;
    }
};