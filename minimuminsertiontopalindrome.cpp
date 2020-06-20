/*

Minimum Insertion Steps to Make a String Palindrome
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:

Input: s = "g"
Output: 0
Example 5:

Input: s = "no"
Output: 1
 

Constraints:

1 <= s.length <= 500
All characters of s are lower case English letters.

*/


class Solution {
    
public:
    int lcs(string s1,string s2)
    {
        int ss1=s1.size();
        int ss2=s2.size();
        vector<vector<int>> dp(ss1+1,vector<int>(ss2+1));
        for(int i=1;i<=ss1;i++)
        {
            for(int j=1;j<=ss2;j++)
            {
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=max(1+dp[i-1][j-1],dp[i-1][j]);
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[ss1][ss2];
    }
    int minInsertions(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s.size()-lcs(s,s1);
        
    }
};
