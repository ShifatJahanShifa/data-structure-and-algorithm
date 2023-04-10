#include<bits/stdc++.h>
using namespace std;

const int n=110;
const int inf=100000;

int main()
{
    freopen("task1.txt","r",stdin);
    int c,s,q,m=1;
    while(scanf("%d%d%d",&c,&s,&q)==3)
    {
        if(c==0 and s==0 and q==0)
            break;

        int g[c+1][c+1];
        for(int i=0;i<=c;i++)
        {
            for(int j=0;j<=c;j++)
            {
                i==j ? g[i][j]=0 : g[i][j]=inf;
            }
        }

        int u,v,w;
        for(int i=0;i<s;i++)
        {
            cin>>u>>v>>w;
            g[u][v]=w;
            g[v][u]=w;
        }

        for(int k=0;k<=c;k++)
        {
            for(int i=0;i<=c;i++)
            {
                for(int j=0;j<=c;j++)
                {
                    g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
                }
            }
        }

        cout<<"Case #"<<m<<"\n";
        m++;
        for(int i=1;i<=q;i++)
        {
            int u,v;
            cin>>u>>v;
            if(g[u][v]==inf) puts("no path");
            else  cout<<g[u][v]<<"\n";
        }
        puts("");
    }
}
