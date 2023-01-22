

// 1305. All Elements in Two Binary Search Trees...

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
    void pushToStack(stack<TreeNode*>&st,TreeNode* curr){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }
    void pushToArr(stack<TreeNode*>&st,vector<int>&res){
        res.push_back(st.top()->val);
        auto node=st.top();
        st.pop();
        pushToStack(st,node->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        pushToStack(s1,root1);
        pushToStack(s2,root2);
        while(!s1.empty() || !s2.empty()){
            if(s1.empty())
                pushToArr(s2,res);
            else if(s2.empty())
                pushToArr(s1,res);
            else{
                if(s1.top()->val<s2.top()->val)
                    pushToArr(s1,res);
                else
                    pushToArr(s2,res);
            }
        }
        return res;   
    }    
};
