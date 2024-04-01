class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int flag = 0;
        int flag2 = 0;
        for(int i = size - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i-1])
            {
                flag = 1;

                int cur = nums[i-1];
                int cur_index = i-1;

                int new_index = -1;
                int ref_num = -1;
                for(int x = i; x < size; x++)
                {
                    if(ref_num == -1)
                    {
                        new_index = x;
                        ref_num = nums[x];
                    }
                    else 
                    {
                        if(nums[x] <= ref_num && nums[x] > cur)
                        {
                            new_index = x;
                            ref_num = nums[x];
                        }
                    }
                }

                int temp = nums[new_index];
                nums[new_index] = nums[cur_index];
                nums[cur_index] = temp;

                reverse(nums.begin() + i, nums.end());
                break;
            }
        }
        if (flag == 0)
            reverse(nums.begin(), nums.end());
    }
};