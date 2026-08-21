class Solution {
public:
    long long countMultiples(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = std::gcd(lcm, (long long)coins[i]);

                    // Avoid overflow
                    lcm = lcm / g * coins[i];

                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid || lcm > x)
                continue;

            long long multiples = x / lcm;

            if (bits % 2 == 1)
                count += multiples;
            else
                count -= multiples;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (countMultiples(mid, coins) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};