bool fillSudoku(char** board, bool rows[][9], bool cols[][9], bool subboxes[][9], int filled) {
    if (filled == 81) return true;
    int row = filled / 9, col = filled % 9, subbox = row / 3 * 3 + col / 3;
    if (board[row][col] != '.') return fillSudoku(board, rows, cols, subboxes, filled + 1);
    for (int val = 0; val < 9; val++) {
        if (!(rows[row][val] || cols[col][val] || subboxes[subbox][val])) {
            rows[row][val] = cols[col][val] = subboxes[subbox][val] = true;
            board[row][col] = val + '1';
            if (fillSudoku(board, rows, cols, subboxes, filled + 1)) return true;
            board[row][col] = '.';
            rows[row][val] = cols[col][val] = subboxes[subbox][val] = false;
        }
    }
    return false;
}
void solveSudoku(char** board, int boardSize, int* boardColSize) {
    bool rows[9][9] = {false}, cols[9][9] = {false}, subboxes[9][9] = {false};
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') continue;
            int val = board[row][col] - '1', subbox = row / 3 * 3 + col / 3;
            rows[row][val] = cols[col][val] = subboxes[subbox][val] = true;
        }
    }
    fillSudoku(board, rows, cols, subboxes, 0);
}