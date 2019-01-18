class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= nums[0]) l = mid + 1;
            else r = mid - 1;
        }
        int tmp = r;
        if (target >= nums[0]) {
            l = 0, r = tmp;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (nums[mid] == target) return mid;
                if (nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        } else {
            l = r + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (nums[mid] == target) return mid;
                if (nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};
