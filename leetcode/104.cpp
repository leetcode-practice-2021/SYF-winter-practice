//
// 104. 二叉树的最大深度
// Created by 师域飞 on 2021/1/28.
//

#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void findnext(TreeNode*p,int curdepth,int maxdepth){
        if (p== nullptr){
            if (curdepth>maxdepth)
                maxdepth=curdepth;
            return;
        }
        curdepth++;
        findnext(p->left,curdepth,maxdepth);
        findnext(p->right,curdepth,maxdepth);
    }
    int maxDepth(TreeNode* root) {
        int curdepth=0,maxdepth=0;
        findnext(root,curdepth,maxdepth);
        return maxdepth;
    }
};
/**
 * answer
 * class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
 */