int min2(int a, int b){return a < b ? a : b;}
int min3(int a, int b, int c){return min2(min2(a, b), c);}
int minDistance(char* word1, char* word2){
    int len1 = (int) strlen(word1), len2 = (int) strlen(word2);
    if (len1 == 0){
        return len2;
    } else if (len2 == 0){
        return len1;
    } else {
        int dist[len1][len2];
        for(int i = 0, tmp = 1; i < len1; i++){
            tmp &= word1[i] != word2[0];
            dist[i][0] = i + tmp;
        }
        for(int j = 0, tmp = 1; j < len2; j++){
            tmp &= word1[0] != word2[j];
            dist[0][j] = j + tmp;
        }
        for(int i = 1; i < len1; i++){
            for(int j = 1; j < len2; j++){
                if (word1[i] == word2[j]){
                    dist[i][j] = dist[i-1][j-1];
                } else {
                    dist[i][j] = min3(dist[i-1][j-1], dist[i-1][j], dist[i][j-1]) + 1;
                }
            }
        }
        return dist[len1-1][len2-1];
    }
}