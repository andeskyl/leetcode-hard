class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q{{0, 0}};
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        cost[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
                int movecost = grid[x][y] != i + 1, newcost = cost[x][y] + movecost;
                if (cost[newx][newy] > newcost) {
                    cost[newx][newy] = newcost;
                    if (movecost) q.push_back({newx, newy});
                    else q.push_front({newx, newy});
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};