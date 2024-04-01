class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while(j >= 0)
        {
            if(i >= 0 && nums1[i] > nums2[j])
            {
                nums1[index--] = nums1[i--];
            }
            else
            {
                nums1[index--] = nums2[j--];
            }
        }
    }
};

// Better to add from the end so we do not have to use vector.insert()
// which makes complexity O(m+n)  