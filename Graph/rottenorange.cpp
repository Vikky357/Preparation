/*

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 */
 
 
 class Solution {
public:
    int xindex[4]={1,0,-1,0};
    int yindex[4]={0,1,0,-1};
    int res=-1,tf=0;
    int orangesRotting(vector<vector<int>>& grid) {
        int minute=0,row=grid.size(),col=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]>0)
                    tf++;
                if(grid[i][j]==2)
                    q.push({i,j});
                    
            }
        }
        if(tf==0)
            return 0;
    while(!q.empty())
    {
        res++;
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            tf--;
            for(int i=0;i<4;i++)
            {
                int nx=x+xindex[i];
                int ny=y+yindex[i];
                if(isvalid(nx,ny,row,col) && grid[nx][ny]==1)
                {
                    q.push({nx,ny});
                    grid[nx][ny]=2;
                }
            }
        }
    }
    return (tf==0 ? res :-1);
      
        
    }
    bool isvalid(int x,int y,int row,int col)
    {
        if((x>=0 && x<row) && (y>=0 && y<col))
            return true;
        return false;
    }
    
};
