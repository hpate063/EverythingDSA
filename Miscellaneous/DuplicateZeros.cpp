class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int limit = n-1;
        int cnt = 0;
        int flag = 0;
        while(i <= limit)
        {
            if(arr[i] == 0 && i < limit)
            {
                cnt++;
                limit--;
                i++;
            }
            else if(i == limit)
            {
                i++;
                limit--;
                flag = 1;
            }
            else
            {
                i++;
            }
        }
        cout << i << limit << cnt;

        i = n - 1 - cnt;
        int index = n - 1;
        while(i >= 0)
        {
            arr[index] = arr[i];
            
            if(flag == 1 && index == n - 1)
            {
                index--;
                i--;
                continue;
            }

            if(arr[index] == 0)
            {
                arr[index - 1] = 0;
                index--;
            }
            
            index--;
            i--;
        }
    }
};

// Problem shared by Douglas
// Simple problem with complex corner cases: Figured out by a bit of trail and error