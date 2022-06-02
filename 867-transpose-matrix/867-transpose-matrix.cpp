class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int colm=matrix[0].size();
        int row=matrix.size();
        int j=0;
        for(int i=0;i<colm;i++){
             vector<int> temp;
            for(int j=0;j<row;j++){
                temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        return ans;
      
    }
};