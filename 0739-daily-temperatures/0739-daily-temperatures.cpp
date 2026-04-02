class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        int st[100001], top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && t[i] > t[st[top]]) {
                int idx = st[top--];
                ans[idx] = i - idx;
            }
            st[++top] = i;
        }
        return ans;
    }
};