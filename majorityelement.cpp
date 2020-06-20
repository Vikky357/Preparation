/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        int index=0,count=1;
        for(int i=1;i<size;i++)
        {
            if(nums[index]==nums[i])
                count++;
            else
                count--;
            if(!count)
            {
                index=i;
                count=1;
            }
        }
        return nums[index];
        /*count=0;
        for(int i=0;i<size;i++)
            if(nums[index]==nums[i])
                count++;
        if(count>size/2)
            return nums[index];*/
        
    }
};
