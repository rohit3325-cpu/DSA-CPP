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
    bool checkPalindrome(int freq[]){
        int odd = 0;
        for(int i=0;i<10;i++){
            if(freq[i] % 2 != 0 ) odd++;
        }
        return odd <= 1;
    }
    void traversal(TreeNode* root,int freq[],int &ans){
        if(!root) return;
        freq[root->val]++;
        if(!root->left && !root->right){
            if(checkPalindrome(freq)) ans++;
        }
        traversal(root->left,freq,ans); 
        traversal(root->right,freq,ans); 
        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int freq[10] = {0};
        int ans = 0;
        traversal(root,freq,ans); 
        return ans;
    }
};