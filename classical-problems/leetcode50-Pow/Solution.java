class Solution {
    public double myPow(double x, int n) {
        long p = 1l * n;
        if (p < 0) p = -p;
        double ans = 1.;
        while (p != 0) {
            if ((p & 1) != 0) ans *= x;
            x *= x;
            p >>= 1;
        }
        return n < 0 ? 1 / ans : ans;
    }
}
