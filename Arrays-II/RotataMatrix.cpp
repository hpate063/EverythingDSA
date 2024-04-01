class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int base = 0;
        while(rows > 1)
        {
            vector<int> v1, v2, v3;
            // copy top
            for (int i = base; i < base + rows; i++)
            {
                v1.push_back(matrix[base][i]);
            }
            // paste top
            for (int i = base + rows - 1; i >= base; i--)
            {
                matrix[base][i] = matrix[abs(i - (rows - 1) - 2 * base)][base];
            }

            // copy right
            for (int i = base; i < base + rows; i++)
            {
                v2.push_back(matrix[i][base + rows - 1]);
            }
            // paste right
            for (int i = base + 1; i < base + rows; i++)
            {
                matrix[i][base + rows - 1] = v1[i - base];
            }

            // copy bottom
            for (int i = base + rows - 1; i >= base; i--)
            {
                v3.push_back(matrix[base + rows - 1][i]);
            }
            // paste bottom
            for (int i = base + rows - 2; i >= base; i--)
            {
                matrix[base + rows - 1][i] = v2[abs(i - (rows - 1) - base)];
            }

            // paste left
            for (int i = base + rows - 2; i > base; i--)
            {
                matrix[i][base] = v3[abs(i - (rows - 1) - base)];
            }

            rows -= 2;
            base += 1;
        }
    }
};

// Easier Solution: Transpose the Matrix and then Reverse the Rows

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// If solution is too complex, think again! There must be a simpler answer.
// Think if there are built-in function which could be used which you might have forgotten or are unaware of