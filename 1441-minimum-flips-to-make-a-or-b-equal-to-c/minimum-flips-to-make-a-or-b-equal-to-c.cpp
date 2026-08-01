class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        for (int i = 0; i < 31; i++) {
            int abit = (a >> i) & 1;
            int bbit = (b >> i) & 1;
            int cbit = (c >> i) & 1;

            if (cbit == 1) {
                if (abit == 0 && bbit == 0)
                    ans++;
            } else {
                ans += abit + bbit;
            }
        }

        return ans;
    }
};