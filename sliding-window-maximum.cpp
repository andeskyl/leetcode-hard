class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> window;
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && i >= window.front() + k) window.pop_front();
            while (!window.empty() && nums[i] > nums[window.back()]) window.pop_back();
            window.push_back(i);
            if (i >= k - 1) res.push_back(nums[window.front()]);
        }
        return res;
    }
};