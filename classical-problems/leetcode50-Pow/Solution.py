class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        p = n
        if p < 0: p = -p
        ans = 1.
        while p:
            if p & 1: ans *= x
            x *= x
            p >>= 1
        if n < 0: return 1 / ans
        return ans
