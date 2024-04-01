class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int result = nums[0];
        int temp = nums[0];

        for (int i = 1; i < size; i++)
        {
            if(temp > 0)
            {
                temp = temp + nums[i];
            }
            else
            {
                temp = nums[i];
            }    

            if(temp > result)
            {
                result = temp;
            }
        }

        return result;
    }
};