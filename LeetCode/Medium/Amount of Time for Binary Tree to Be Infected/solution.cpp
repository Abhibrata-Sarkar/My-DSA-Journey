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
    TreeNode* parent(TreeNode*root,map<TreeNode*,TreeNode*>&mpp,int start){
        TreeNode* res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val==start){
                res = node;
            }
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findmax(TreeNode*root,map<TreeNode*,TreeNode*>&mpp, TreeNode* target){
        int maxi=0;
        map<TreeNode*,int>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=1;
        while(!q.empty()){
            int size =q.size();
            int flag =0;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && visited[temp->left]==0){
                    flag=1;
                    visited[temp->left]=1;
                    q.push(temp->left);
                }
                if(temp->right  && visited[temp->right]==0){
                    flag=1;
                    visited[temp->right]=1;
                    q.push(temp->right);
                }
                if(mpp[temp] && visited[mpp[temp]]==0){
                    flag=1;
                    visited[mpp[temp]]=1;
                    q.push(mpp[temp]);
                }
            }
            if(flag==1){
                maxi++;
            }
        }
        return maxi;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        TreeNode* target = parent(root,mpp,start);
        int maxi = findmax(root,mpp, target);
        return maxi;
    }
};