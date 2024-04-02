class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int reference = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                count++;
                reference = nums[i];
            }
            else if(nums[i] == reference)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return reference;
    }
};

// Simple and effective problem - had to look up solution
// Use Moore's Voting Algorithm (2 variables: one counter, one element)