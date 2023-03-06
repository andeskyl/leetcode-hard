class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        priority_queue<int> profitsAllowed;
        for (int i = 0; i < n; i++) {
            if (capital[i] <= w)
                profitsAllowed.push(profits[i]);
            else projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        for (int i = 0, j = 0; i < k && !profitsAllowed.empty(); i++) {
            w += profitsAllowed.top();
            profitsAllowed.pop();
            for (; j < projects.size() && projects[j].first <= w; j++)
                profitsAllowed.push(projects[j].second);
        }
        return w;
    }
};