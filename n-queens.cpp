class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols(n);
        placeQueens(n, 0, cols, 0, 0);
        return res;
    }
private:
    int checkBit(int num, int pos) {return num & (1 << pos);}
    int flipBit(int num, int pos) {return num ^ (1 << pos);}
    void placeQueens(int n, int row, vector<int> cols, int diags, int antiDiags) {
        if (row >= n) {
            vector<string> sol;
            for (int row = 0; row < n; row++) {
                string rowStr = "";
                for (int col = 0; col < n; col++)
                    rowStr += cols[row] == col ? "Q" : ".";
                sol.push_back(rowStr);
            }
            res.push_back(sol);
        } else {
            for (int col = 0; col < n; col++) {
                int diag = row - col + n, antiDiag = row + col;
                bool validCol = true;
                for(int i = 0; i < row; i++) {
                    if (cols[i] == col) {
                        validCol = false; 
                        break;
                    }
                }
                cols[row] = col;
                if (validCol && !(checkBit(diags, diag) || checkBit(antiDiags, antiDiag)))
                    placeQueens(n, row + 1, cols, flipBit(diags, diag), flipBit(antiDiags, antiDiag));
            }
        }
    }
};