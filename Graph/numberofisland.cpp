/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


*/


/***
    BFS
    
 ***/
 class Solution {
public:
    int xindex[4]={1,0,-1,0};
    int yindex[4]={0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int row=grid.size(),col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    bfs(grid,i,j,row,col);
                }
            }
        }
        
      return count;  
    }
    void bfs(vector<vector<char>>& grid,int s,int e,int row,int col)
    {
        grid[s][e]='2';
        queue<pair<int,int>>q;
        q.push({s,e});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+xindex[i];
                int ny=y+yindex[i];
                if((nx>=0 && nx<row) && (ny>=0 && ny<col) && grid[nx][ny]=='1')
                {
                    q.push({nx,ny});
                    grid[nx][ny]='2';
                }
            }
        }
        
    }
};


/***
    DFS
    
    ***/
    
    class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int row=grid.size(),col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {

                    count++;
                    dfs(grid,i,j,row,col);
                }
            }
        }
        
      return count;  
    }
    void dfs(vector<vector<char>>& grid,int s,int e,int row,int col)
    {
        if((s>=0 && s<row) && (e>=0 && e<col) && grid[s][e]=='1' )
        {
            grid[s][e]='2';
            dfs(grid,s+1,e,row,col);
            dfs(grid,s,e+1,row,col);
            dfs(grid,s-1,e,row,col);
            dfs(grid,s,e-1,row,col);
        }
    }
};
