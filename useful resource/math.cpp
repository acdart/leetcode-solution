// 最大公因子
__gcd(x, y) // built_in function
#define gcd(x, y) __gcd(x, y)
int gcd(int x, int y) {
    int z;
    while (y) {
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}

// 最小公倍数
int lcm(int x, int y) {
    return x / gcd(x, y) * y; // 先除再乘防止中间结果溢出(x整除其因子)
}

// 判断一个数是不是素数
bool isprime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int m = sqrt(n) + 0.5;
    for (int i = 3; i <= m; i += 2) {
        if (n % i == 0) return false;
    } 
    return true;
} 

