/*

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.


*/



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum&1==1)
            return false;
        sum/=2;
        int size=nums.size();
        vector<vector<bool>>dp(size+1,vector<bool>(sum+1,false));
        dp[0][0]=true;
        for(int i=1;i<=sum;i++)
            dp[0][i]=false;
        for(int i=1;i<=size;i++)
            dp[i][0]=true;
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[size][sum]?true:false;
    }
};
