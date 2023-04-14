int max(int a, int b) {return a > b ? a : b;}
int longestValidParentheses(char* s){
    int i, len = strlen(s), lvp[len + 1], res = 0;
    for (i = 1, lvp[0] = 0; i < len; i++) {
        if (s[i] == '(') 
            lvp[i] = 0;
        else if (s[i - 1] == '(')
            lvp[i] = (i >= 2 ? lvp[i - 2] : 0) + 2;
        else if (i > lvp[i - 1] && s[i - 1 - lvp[i - 1]] == '(')
            lvp[i] = lvp[i - 1] + (i >= lvp[i - 1] + 2 ? lvp[i - lvp[i - 1] - 2] : 0) + 2;
        else lvp[i] = 0;
        res = max(res, lvp[i]);
    }
    return res;
}