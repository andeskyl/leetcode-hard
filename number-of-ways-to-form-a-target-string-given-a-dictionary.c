int numWays(char** words, int wordsSize, char* target){
    int words_len = strlen(words[0]), target_len = strlen(target), count[26], p = 1e9 + 7;
    long res[target_len + 1];
    memset(res, 0, sizeof(res));
    res[0] = 1;
    for (int i = 0; i < words_len; i++) {
        memset(count, 0, sizeof(count));
        for (int j = 0; j < wordsSize; j++)
            count[words[j][i] - 'a']++;
        for (int j = target_len; j > 0; j--)
            res[j] += res[j - 1] * count[target[j - 1] - 'a'] % p;
    }
    return res[target_len] % p;
}