#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int xindex[4]={1,0,-1,0};
int yindex[4]={0,1,0,-1};
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int row,col;
        cin >>row >>col;
        pair<int,int> source,dest;
        int x,y;
        int res=0;
        vector<vector<char>> g(row,vector<char>(col));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cin>>g[i][j];
        }
        printf("Enter Source:\n");
        cin >>x >>y;
        source={x,y};
        printf("Enter Destination:\n");
        cin >>x >>y;
        dest={x,y};
        cout<<dest.first<<source.first<<"\n";
        queue<pair<int,int>> q;
        q.push(source);
        while(!q.empty())
        {
            int sz=q.size();
            res++;
            for(int i=0;i<sz;i++)
            {
                    int tx=q.front().first;
                    int ty=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++)
                    {
                        int nx=tx+xindex[i];
                        int ny=ty+yindex[i];
                        if((nx>=0 && nx<row) && (ny>=0 && ny<col) && (g[nx][ny]=='P' || g[nx][ny]=='D'))
                            {
                                //cout<<nx<<ny<<" ";
                                if(g[nx][ny]=='D')
                                {
                                    cout<<"Hai\n";
                                    return res;
                                }
                                q.push({nx,ny});
                                g[nx][ny]='V';
                            }
                    }
                    cout<<"\n";
                    /*for(int i=0;i<row;i++)
                    {
                        for(int j=0;j<col;j++)
                            cout<<g[i][j];
                        cout<<"\n";
                    }
                    cout<<"\n";*/

        }

    }


        return res;
}
}



/*S P B B
P P P P
P P P P
P D B B
*/
