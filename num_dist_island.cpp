// User function Template for C++

class Solution {
  private: void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis , int r,int c ,vector<pair<int,int>>&vec,int drow[],int dcol[],int row0,int col0)
    {   
        vis[r][c]=1;
        vec.push_back({r-row0,c-col0});
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {   
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(grid,vis,nrow,ncol,vec,drow,dcol,row0,col0);
            }
        }

    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(grid,vis,i,j,vec,drow,dcol,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
        
    }
};