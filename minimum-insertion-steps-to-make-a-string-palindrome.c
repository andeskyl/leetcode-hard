int max(int a, int b) {return a > b ? a : b;}
int minInsertions(char* s) {
    int len = strlen(s), lcs[len + 1][len + 1];
    memset(lcs, 0, sizeof(lcs));
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
            if (s[i - 1] == s[len - j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j]= max(lcs[i - 1][j], lcs[i][j - 1]);
    return len - lcs[len][len];
}