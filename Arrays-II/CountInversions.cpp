#include <bits/stdc++.h> 

long long merge(long long *arr, int l, int m, int r)
{
    vector<long long> temp;
    int i = l;
    int j = m+1;

    int count = 0;

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            count += (m - i + 1);
        }
    }
    while(i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }

    return count;
}

long long mergeSort(long long *arr, int start, int end)
{
    if(start >= end)
        return 0;
    
    int count = 0;
    int mid = start + (end-start) / 2;
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid+1, end);
    count += merge(arr, start, mid, end);

    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n-1);
}

// Learn & remember to implement merge sort properly
// Counting inversions can be just a few lines addition to merge sort where for one of the conditions, we update the counter