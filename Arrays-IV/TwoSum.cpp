class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            int value = nums[i];
            int missing = target - value;
            if(map.find(missing) != map.end())
            {
                return {map[missing], i};
            }
            map[value] = i;
        }
        return {-1, -1};
    }
};

// Neeed hint to solve
// Came up with one solution myself: Sort the array and search from each end 
// Implemented that but as the answer wanted indices I had to either write my own sort or do another method
// Other method was to use unordered_map : Perform lookup for missing value needed
//                                         insert value in the map when not found. 