class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return NULL;
        }
        return fun(0,n-1,nums);
    }
    TreeNode* fun(int s,int e,vector<int>& nums)
    {
        if(s>e)
        {
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left = fun(s,mid-1,nums);
        root->right = fun(mid+1,e,nums);
        return root;
    }
};
