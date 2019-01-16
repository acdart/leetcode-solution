/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            int x = 0, y = 0, z = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    x++;
                } else if (points[i].x == points[j].x) {
                    y++;
                    z = max(y, z);
                } else {
                    int a = points[i].x - points[j].x;
                    int b = points[i].y - points[j].y;
                    int gcd = __gcd(a, b);
                    a /= gcd, b /= gcd;
                    mp[{a, b}]++;
                    z = max(z, mp[{a, b}]);
                }
            } 
            ans = max(ans, z + x + 1);
        }
        return ans;
    }
};
