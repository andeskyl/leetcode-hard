class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> numSet;
        for (int num : nums)
            numSet.insert(num & 1 ? num << 1 : num);
        int res = INT_MAX, maxNum = *numSet.rbegin();
        while (!(maxNum & 1)) {
            numSet.erase(maxNum);
            numSet.insert(maxNum >> 1);
            maxNum = *numSet.rbegin();
            res = min(res, maxNum - *numSet.begin());
        }
        return res;
    }
};