class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum1 = 0, sum2 = 0, sum = 0;
        int a[] = {INT_MAX, INT_MAX};
        int b[] = {INT_MAX, INT_MAX};
        for (auto c : nums) {
            if (c % 3 == 1) {
                if (a[0] > c) {
                    a[1] = a[0];
                    a[0] = c;
                } else
                    a[1] = min(a[1], c);
                sum1 += c;
            } else if (c % 3 == 2) {
                if (b[0] > c) {
                    b[1] = b[0];
                    b[0] = c;
                } else
                    b[1] = min(b[1], c);
                sum2 += c;
            } else
                sum += c;
        }
        int total = sum + sum1 + sum2;

        if (total % 3 == 0)
            return total;

        else if (total % 3 == 1) {
            int remove1 = (a[0] != INT_MAX) ? a[0] : INT_MAX;
            int remove2 = (b[1] != INT_MAX) ? b[0] + b[1] : INT_MAX;
            int rem = min(remove1, remove2);
            return (rem == INT_MAX) ? 0 : total - rem;
        }

        else {
            int remove1 = (b[0] != INT_MAX) ? b[0] : INT_MAX;
            int remove2 = (a[1] != INT_MAX) ? a[0] + a[1] : INT_MAX;
            int rem = min(remove1, remove2);
            return (rem == INT_MAX) ? 0 : total - rem;
        }
    }
};