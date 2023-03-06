int checkBit(int num, int pos) {return num & (1 << pos);}
int flipBit(int num, int pos) {return num ^ (1 << pos);}
int placeQueens(int n, int row, int cols, int diags, int antiDiags) {
    if (row >= n) return 1;
    int numSol = 0;
    for (int col = 0; col < n; col++) {
        int diag = row - col + n, antiDiag = row + col;
        if (!(checkBit(cols, col) || checkBit(diags, diag) || checkBit(antiDiags, antiDiag)))
            numSol += placeQueens(n, row + 1, flipBit(cols, col), flipBit(diags, diag), flipBit(antiDiags, antiDiag));
    }
    return numSol;
}
int totalNQueens(int n) {
    return placeQueens(n, 0, 0, 0, 0);
}