class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int col=matrix.size();
        int row=matrix[0].size();
        for(int i=0;i<col;i++){
            vector<int> rows(row);
            rows[0]=matrix[i][0];
            for(int j=1;j<row;j++){
                rows[j] = rows[j-1] + matrix[i][j];
            }
            ans.push_back(rows);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0,minus=0;
        for(int i=row1;i<=row2;i++){
            sum += ans[i][col2];
            if(col1 > 0)
                minus += ans[i][col1-1];
        }
        return sum-minus;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */