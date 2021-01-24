//
// 103 二叉树的锯齿遍历
// Created by 师域飞 on 2021/1/20.
//

/**
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 */

//Definition for a binary tree node.
#include "vector"

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        vector<int>temp;
        bool direct= false;
        temp.push_back(root->val);
        result.push_back(temp);

        TreeNode *p=root;
        while (true){
            if (p->left==NULL&&p->right== NULL)
                break;

        }
    }
    void findnext(TreeNode* node,bool direct){
        if (node==NULL)
            return;
        if (direct){
            direct=false;
            node=node->left;
            findnext(node,direct);
        } else{
            direct=true;
            node=node->right;
            findnext(node,direct);

        }
    }
};