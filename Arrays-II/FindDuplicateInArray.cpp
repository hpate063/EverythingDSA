class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};

// Needed to check the solution for optimal method
// Use slow and fast pointers to check loop (method learnt before) - can be used for linked list as well
// Anywhere there is a loop; you can use 'similar' method 