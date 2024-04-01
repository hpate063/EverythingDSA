class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;

        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> solution;
        for(int i = 0; i < n; i++)
        {
            if(solution.empty() || intervals[i][0] > solution.back()[1])
            {
                solution.push_back(intervals[i]);
            }
            else
            {
                solution.back()[1] = max(solution.back()[1], intervals[i][1]);
            }
        }

        return solution;
    }
};

// Remeber to not assume that data is sorted (assumed that and made a mistake)