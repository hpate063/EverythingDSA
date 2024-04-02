class Solution {
public:
    int uniquePaths(int m, int n) {
        int arr[101][101] = {{1}};

        if(m == n && m == 1)
        {
            return 1;
        }

        for(int i = 0; i < n - 1; i++)
        {
            arr[m-1][i] = 1;
        }
        for(int i = 0; i < m - 1; i++)
        {
            arr[i][n-1] = 1;
        }

        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = n - 2; j >= 0; j--)
            {
                arr[i][j] = arr[i+1][j] + arr[i][j+1];
            }
        }

        return arr[0][0];
    }
};

// Easy solution - simplest DP-like problem 
// Traverse the matrix and use 2 neighbors to get current's value
// I did it in reverse (m -> 1 and n -> 1) but forward (1 -> m and 1 -> n) will give same result