//
// 103 二叉树的锯齿遍历
// Created by 师域飞 on 2021/1/20.
//

/**
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 */

//Definition for a binary tree node.
#include "vector"
#include "stack"

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> zigzag(stack<TreeNode*> &stk,TreeNode *p,int direct){
        vector<int> temp;

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //先push入栈，pop的后加入临时的vector ；当栈为空时，将vector中的元素按方向获取子树并压栈
        vector<vector<int>> res;
        stack<TreeNode*> stk;
        stk.push(root);
        int direct=0;
        while (root != NULL || !stk.empty()) {
            vector<int> temp;
            while (!stk.empty()){
                root = stk.top();
                stk.pop();
                temp.push_back(root->val);
            }
            res.push_back(temp);
            if (direct==0){
                for(auto )
            }
            while (root != NULL) {
                stk.push(root);
                root = root->left;
            }

        }
    }
};