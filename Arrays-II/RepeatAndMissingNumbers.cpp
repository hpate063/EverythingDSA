#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long sn = 0, s2n = 0, snp = 0, s2np = 0;

	for(long long i = 0; i < n; i++)
	{
		sn += (i+1);
		s2n += (i+1) * (i+1);

		snp += arr[i];
		s2np += arr[i] * arr[i];
	} 

	long long diff = snp - sn;  //x-y
	long long diff2 = s2np - s2n;
	long long sum = diff2 / diff; //x+y

	int repeat = (int)((diff + sum)/2);
	int missing = (int)((sum - diff)/2);

	pair<int, int> result (missing, repeat);
	return result;
}


// Needed to check solution
// Think about sum, square of sums (different mathematical formulae) to solve problems where 1 number is missing, etc.
// Another idea was to use XOR (which I did not explore - check solution later) 