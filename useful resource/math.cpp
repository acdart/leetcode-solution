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

// 矩阵 
struct Matric {
    int sz;
    int a[maxn][maxn];
    Matric(int s = 0) {
        sz = s; memset(a, 0, sizeof a);
    }
    void operator = (const Matric& t) {
        sz = t.sz; memcpy(a, t.a, sizeof a);
    }
    Matric operator * (const Matric& t) {
        Matric res = Matric(sz);
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (!a[i][k]) continue;
                for (int j = 0; j < sz; j++) {
                    res.a[i][j] += a[i][k] * t.a[k][j];
                    if (res.a[i][j] >= mod) res.a[i][j] -= mod;
                }
            }
        }
        return res;
    }
}

