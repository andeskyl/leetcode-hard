class Solution {
public:
    int largestRectangleArea(vector<unsigned char>& heights) {
        stack<int> stk;
        int res = 0, n = heights.size();
        for (auto i = 0; i <= n; i++) {
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        unsigned char nRow = matrix.size(), nCol = matrix[0].size();
        vector<vector<unsigned char>> widths(nRow, vector<unsigned char>(nCol));
        for (auto j = 0; j < nCol; j++) {
            widths[0][j] = matrix[0][j] - '0';
            for (auto i = 1; i < nRow; i++)
                widths[i][j] = (matrix[i][j] == '1') ? widths[i - 1][j] + 1 : 0;
        }
        for (auto row : widths)
            res = max(res, largestRectangleArea(row));
        return res;
    }
};