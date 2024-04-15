class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int res = 0, n = heights.size();
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, height * width);
            }
            stk.push(i);
        }
        return res;
    }
};