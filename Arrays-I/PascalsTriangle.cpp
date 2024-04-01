class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v {{1}};

        for(int i = 1; i < numRows; i++)
        {
            vector<int> tmp {1};

            int prev_size = v[i-1].size();
            if (prev_size > 1)
            {
                for(int x = 0; x < prev_size - 1; x++)
                {
                    tmp.push_back(v[i-1][x] + v[i-1][x+1]);
                }
            }
            tmp.push_back(1);

            v.push_back(tmp);
        }
        return v;
    }
};