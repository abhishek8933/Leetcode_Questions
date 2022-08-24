class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int row=matrix[0].size();
        int column=matrix.size();
        
        int i=0;
        int j=matrix[0].size()-1;
        while(i<column && j>=0 ){
            if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
                i++;
            }else {
                return true;
            }
        }
        return false;
    }
};