/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
   
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode == NULL) {
                s += "#,";
            } else {
                s += to_string(currNode->val) + ",";
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }

        return s;
    }

   
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream s(data);
        string str;

       
        getline(s, str, ',');
        if (str == "#" || str.empty()) return NULL;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

         
            if (!getline(s, str, ',')) break;
            if (str == "#" || str.empty()) {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

          
            if (!getline(s, str, ',')) break;
            if (str == "#" || str.empty()) {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));