//20ms, 81.51%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = nums.size();
        int start = 0, end = l-1;
        return  sortedArrayToBST(nums, start, end);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        if(start == end) return new TreeNode(nums[start]);
        
        int mid = (start + end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, end);
        
        return root;
    }
};