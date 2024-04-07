class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right)
    {
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right)
        {
            if(nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= right)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for(i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }
    }

    int countPairs(vector<int>& nums, int left, int mid, int right)
    {
        int count = 0;

        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right)
        {
            if(nums[i] > 2 * (long)nums[j])
            {
                count += (mid - i + 1);
                j++;
            }
            else
            {
                i++;
            }
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right)
    {
        if(left >= right)
            return 0;

        int count = 0;
        int mid = left + (right - left) / 2;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += countPairs(nums, left, mid, right);
        merge(nums, left, mid, right);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        return mergeSort(nums, left, right);
    }
};

// Tricky question: Similar to count inversions but can not count inversion while merge() in mergeSort()
// Have to add another O(n) fuction inside mergeSort which counts the pairs (i < j & arr[i] > 2 * arr[j]) before calling merge()
// Complexity: O(log(n) * (n + n)) = O(2nlog(n))