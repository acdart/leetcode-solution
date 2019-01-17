class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> mp;
        int cc = 1;
        int n = findNums.size(), m = nums.size();
        for (int i = 0; i < n; i++) {
            mp[findNums[i]] = cc++;
        }
        vector<int> ans(n, -1);
        stack<int> s;
        for (int i = 0; i < m; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                int tmp = mp[nums[s.top()]];
                if (tmp) ans[tmp - 1] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        return ans;
    }
};
