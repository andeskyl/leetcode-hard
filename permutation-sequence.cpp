class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        string res = "";
        vector<char> choices;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            choices.push_back('0' + i);
        }
        for (int i = n; i > 0; i--) {
            factorial /= i;
            int idx = (k - 1) / factorial;
            k -= factorial * idx;
            res += choices[idx];
            choices.erase(choices.begin() + idx);
        }
        return res;
    }
};