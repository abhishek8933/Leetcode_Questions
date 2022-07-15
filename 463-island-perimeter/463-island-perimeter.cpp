class Solution {
public:
    int peri(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size()||j>=grid[0].size()||grid[i][j]==0||i<0||j<0){
            return 1;
        }
        if(grid[i][j]==-1){
            return 0;
        }
        grid[i][j]=-1;
        return peri(grid,i+1,j)+peri(grid,i-1,j)+peri(grid,i,j-1)+peri(grid,i,j+1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    perimeter=peri(grid,i,j);
                }
            }
        }
        return perimeter;
    }
};