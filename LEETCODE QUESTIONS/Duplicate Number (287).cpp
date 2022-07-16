// Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowptr=nums[0];
        int fastptr=nums[0];
        do{
            slowptr=nums[slowptr];
            fastptr=nums[nums[fastptr]];
        }while(slowptr!=fastptr);
            
        fastptr=nums[0];
        while(slowptr!=fastptr)
        {
            slowptr=nums[slowptr];
            fastptr=nums[fastptr];
        }
        return slowptr;
    }
};



// Input: nums = [1,3,4,2,2]
// Output: 2

// Input: nums = [3,1,3,4,2]
// Output: 3