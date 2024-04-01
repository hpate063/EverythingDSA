class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else if (n == -1)
            return 1 / x;

        double ans = 1;
        long long n_copy = n;

        if (n_copy < 0)
        {
            n_copy = -1 * n_copy;
        }

        while(n_copy)
        {
            if(n_copy % 2)
            {
                ans = ans * x;
                n_copy -= 1;
            }
            else
            {
                x *= x;
                n_copy /= 2;
            }
        }

        if(n < 0)
        {
            ans = 1 / ans;
        }

        return ans;
    }
};

// Had to check solution; had intuition for the optimal solution but could not code it
// No need to convert int into bool; just use power properties
// If power is odd; adjust and make it even
// If power is even; you can reduce it by half and square the base