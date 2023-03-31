int numRows, numCols, numPieces, p = 1e9 + 7;
int getNumCuts(int numCuts[][numCols][numPieces], int numAs[][numCols + 1], int i, int j, int k) {
    if (numCuts[i][j][k] >= 0) return numCuts[i][j][k];
    else if (k == 0) return numAs[i][j] > 0;
    numCuts[i][j][k] = 0;
    for (int l = i + 1; l < numRows; l++)
        if (numAs[i][j] > numAs[l][j])
            numCuts[i][j][k] = (numCuts[i][j][k] + getNumCuts(numCuts, numAs, l, j, k - 1)) % p;
    for (int m = j + 1; m < numCols; m++)
        if (numAs[i][j] > numAs[i][m])
            numCuts[i][j][k] = (numCuts[i][j][k] + getNumCuts(numCuts, numAs, i, m, k - 1)) % p;
    return numCuts[i][j][k];
}
int ways(char** pizza, int pizzaSize, int k){
    numRows = pizzaSize, numCols = strlen(pizza[0]), numPieces = k;
    int numCuts[numRows][numCols][numPieces], numAs[numRows + 1][numCols + 1];
    memset(numCuts, -1, sizeof(numCuts));
    memset(numAs, 0, sizeof(numAs));
    for (int i = numRows - 1; i >= 0; i--)
        for (int j = numCols - 1; j >= 0; j--)
            numAs[i][j] = numAs[i][j + 1] + numAs[i + 1][j] - numAs[i + 1][j + 1] + (pizza[i][j] == 'A');
    return getNumCuts(numCuts, numAs, 0, 0, numPieces - 1);
}