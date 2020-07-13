/*
N-Queen -Using Backtracking

*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        std::vector<std::string> nqueen(n, std::string(n, '.'));
        solvequeen(res,nqueen,0,n);
        return res;
    }
    void solvequeen(vector<vector<string>> &res,vector<string> &nqueen,int row,int n)
    {
       
        if(row==n)
        {
            res.push_back(nqueen);
            return;
        }
        
        for(int i=0;i!=n;i++)
        {
           // cout<<row<<" "<<i<<" ";
            if(isvalid(nqueen,row,i,n))
            {
                nqueen[row][i]='Q';
                //cout<<row<<" "<<i<<" ";
                solvequeen(res,nqueen,row+1,n);
                nqueen[row][i]='.';
            }
        }
    }
    bool isvalid(vector<string> &nqueen,int row,int col,int n)
    {
        for(int i=0;i!=row;i++)
        {
            if(nqueen[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(nqueen[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
        {
            if(nqueen[i][j]=='Q')
                return false;
        }
        return true;
    }
};
