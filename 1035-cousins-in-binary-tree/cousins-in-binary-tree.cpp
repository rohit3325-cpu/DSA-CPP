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
  int xd,yd,xp,yp;
    void finddepth(TreeNode* root, int x, int y,int d,int p_val){
        if(root==NULL){
            return;
        }
        if(root->val==x){
            xd=d;
            xp=p_val;
            return;
        }
        if(root->val==y){
            yd=d;
            yp=p_val;
            return;
        }
        finddepth(root->left,x,y,d+1,root->val);
        finddepth(root->right,x,y,d+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y) return false;
        finddepth(root,x,y,0,0);

        if(xd==yd && xp!=yp) return true;
        return false;
    }
};