class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, count = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            if ((count += satisfaction[i]) > 0)
                res += count;
            else break;
        }
        return res;
    }
};