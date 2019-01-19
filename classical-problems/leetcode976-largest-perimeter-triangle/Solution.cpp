class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        for (int i = n - 1; i >= 2; i--) {
            if (A[i - 1] + A[i - 2] > A[i]) {
                return A[i - 1] + A[i - 2] + A[i];
            } 
        }
        return 0;
    }
};
