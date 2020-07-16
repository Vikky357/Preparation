#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int xindex[8]={2,1,-1,-2,-2,-1,1,2};
int yindex[8]={1,2,2,1,-1,-2,-2,-1};
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int row,col;
        cin >>row >>col;
        vector<vector<int>> arr(row,vector<int>(col,0));
        pair<int,int> source={7,0};
        pair<int,int> dest={0,7};
        queue<pair<int,int>> q;
        q.push(source);
        arr[source.first][source.second]=1;
        int res=-1;
        while(!q.empty())
        {
            int s=q.size();
            res++;
            for(int i=0;i<s;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==dest.first && y==dest.second)
                    {
                        cout<<"Ans:";
                        return res;
                    }
                for(int i=0;i<8;i++)
                {
                    int nx=x+xindex[i];
                    int ny=y+yindex[i];
                    if((nx>=0 && nx<row)&&(ny>=0 && ny<col) && arr[nx][ny]==0)
                    {
                        arr[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }

        }

    }
    return res;
}
}
