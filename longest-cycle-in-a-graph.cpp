class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int res = -1, count = 0, n = edges.size();
        vector<pair<int, int>> dist (n, {-1, -1});
        for (int i = 0; i < n; i++) {
            for (int j = i, count = 0; j >= 0; j = edges[j]) {
                auto [start, pathLen] = dist[j];
                if (pathLen < 0) dist[j] = {i, count++};
                else {
                    res = start == i ? max(res, count - pathLen) : res;
                    break;
                }
            }
        }
        return res;
    }
};