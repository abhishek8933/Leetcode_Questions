class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int &count){
        if(grid[i][j]==1){
            count++;
            grid[i][j]=0;
            
            for(int r=0;r<grid[0].size();r++){
                dfs(grid,i,r,count);
            }
            for(int c=0;c<grid.size();c++){
                dfs(grid,c,j,count);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int comm=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(grid,i,j,count);
                    if(count>1){
                        comm+=count;
                    }
                }
            }
        }
        return comm;
    }
};