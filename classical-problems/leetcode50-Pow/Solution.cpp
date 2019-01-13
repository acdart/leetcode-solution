class Solution {
public:
	double myPow(double x, int n) {
		long long p = abs(1ll * n); // if n < 0, then the ans is 1/(x^p), and keep in mind n can be -2147483648 (in which case -n will be large than the biggest int value) 
		double ans = 1;
		while (p != 0) {
			if (p & 1) ans = ans * x;
			x *= x;
			p >>= 1;
		}
		return n < 0? 1 / ans : ans;
	}
}
