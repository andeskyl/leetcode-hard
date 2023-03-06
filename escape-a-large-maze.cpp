class Solution {
public:
    set<pair<int, int>> blockedSet;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int maxStep = (blocked.size() * (blocked.size() - 1)) / 2;
        for (vector<int> blk : blocked)
            blockedSet.insert({blk[0], blk[1]});
        return checkEscape(source, target, maxStep) && checkEscape(target, source, maxStep);
    }
private:
    bool checkEscape(vector<int> source, vector<int> target, int maxStep) {
        vector<pair<int, int>> visitedList;
        set<pair<int, int>> visitedSet;
        visitedList.push_back({source[0], source[1]});
        visitedSet.insert({source[0], source[1]});
        for (int i = 0; i < visitedList.size(); i++) {
            for (pair<int, int> direction : directions) {
                int x = visitedList[i].first + direction.first, y = visitedList[i].second + direction.second;
                if (isValidPoint(x, y) && !blockedSet.count({x, y}) && !visitedSet.count({x, y})) {
                    visitedList.push_back({x, y});
                    visitedSet.insert({x, y});
                    if (visitedList.size() > maxStep || (target[0] == x && target[1] == y)) return true;
                }
            }
        }
        return false;
    }
    bool isValidPoint(int x, int y) {
        return x >= 0 && x < 1e6 && y >= 0 && y < 1e6;
    }
};