class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdAns = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++)
            gcdAns = gcd(gcdAns, numsDivide[i]);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            if (gcdAns % nums[i] == 0) return i;
        return -1;  
    }
};