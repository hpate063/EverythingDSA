class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int element1 = INT_MIN, element2 = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(count1 == 0)
            {
                if(element2 == nums[i])
                    count2++;
                else
                {
                    count1++;
                    element1 = nums[i];
                }
            }
            else if(count2 == 0)
            {
                if(element1 == nums[i])
                    count1++;
                else
                {
                    count2++;
                    element2 = nums[i];
                }
            }
            else
            {
                if(element1 == nums[i])
                {
                    count1++;
                }
                else if(element2 == nums[i])
                {
                    count2++;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
        }

        int final_count1 = 0, final_count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(element1 == nums[i])
                final_count1++;
            if(element2 == nums[i])
                final_count2++;
        }

        vector<int> v;
        if(final_count1 > floor(n/3))
            v.push_back(element1);
        if(element2 != element1 && final_count2 > floor(n/3))
            v.push_back(element2);

        return v;
    }
};

// Similar to other one but requires returning all elements that occure more than (floor (n/3)) times
// Requires modifying Moore's Voting Algorithm from the previous problem to have 2 counters and 2 elements and extra loop for a final check