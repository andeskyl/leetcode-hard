bool isMatch(char* s, char* p) {
    int sLength = strlen(s), pLength = strlen(p);
    bool match[sLength + 1][pLength + 1];
    memset(match, 0, sizeof(match));
    match[0][0] = true;
    for (int j = 2; j <= pLength; j++)
        match[0][j] = p[j - 1] == '*' ? match[0][j - 2] : false;
    for (int i = 1; i <= sLength; i++) {
        for (int j = 1; j <= pLength; j++) {
            if (p[j - 1] == '*') {
                match[i][j] = match[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && match[i - 1][j]);
            } else match[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && match[i - 1][j - 1];
        }
    }
    return match[sLength][pLength];
}