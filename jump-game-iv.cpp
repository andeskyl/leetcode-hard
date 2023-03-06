class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), res = 0;
        unordered_map<int, vector<int>> indices;
        queue<int> toVisit;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) indices[arr[i]].push_back(i);
        for (toVisit.push(0); !toVisit.empty(); res++) {
            int m = toVisit.size();
            for (int i = 0; i < m; i++) {
                int current = toVisit.front();
                toVisit.pop();
                if (current == n - 1) return res;
                indices[arr[current]].push_back(current + 1);
                indices[arr[current]].push_back(current - 1);
                for (int j : indices[arr[current]]) {
                    if(j >= 0 && j < n && !visited[j]){
                        toVisit.push(j);
                        visited[j] = true;
                    }
                }
                indices[arr[current]].clear();
            }
        }
        return res;
    }
};