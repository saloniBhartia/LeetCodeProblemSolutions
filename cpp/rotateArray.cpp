class Solution {
    void rotateMat(vector<vector<int>> &matrix, int row, int rows, int col, int cols) {
        if (row >= rows || col >= cols) {
            return;
        }
        
        int temp;
        for (int i = 0; i<(cols-col); i++) {
                temp = matrix[row][col+i];
                matrix[row][col+i] = matrix[rows-i][col];
                matrix[rows-i][col] = matrix[rows][cols-i];
                matrix[rows][cols-i] = matrix[row+i][cols];
                matrix[row+i][cols] = temp;
        }
        
        rotateMat(matrix, row+1, rows-1, col+1, cols-1);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = 0, rows = matrix.size()-1, col = 0, cols = matrix[0].size()-1;
        rotateMat(matrix, row, rows, col, cols);
        return;
    }
};