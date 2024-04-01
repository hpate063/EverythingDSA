class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m * n;

        int low = 0;
        int high = size - 1;
        int mid = low + (high - low) / 2;

        while(low <= high)
        {
            int result = 0;
            int t_m = mid / n;
            int t_n = mid % n;
            int check = matrix[t_m][t_n];
            if(check == target)
                result = 0;
            else if(target > check)
                result = 1;
            else
                result = -1;

            if(result == 0)
                return true;
            else if(result == 1)
            {
                low = mid + 1;
                mid = low + (high - low) / 2;
            }
            else
            {
                high = mid - 1;
                mid = low + (high - low) / 2;
            }
        }

        return false;
    }
};

// Simple solution: got it by myself
// Represent 2D Array as 1D (as it is sorted) and apply Binary search