/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       long long int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto x:nums)
                if(i-x>=0){
                    dp[i]+=dp[i-x],dp[i]%=2147483647;
                }
        }
        return dp[target];
    }
};
