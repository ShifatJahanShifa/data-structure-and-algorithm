#include<bits/stdc++.h>
using namespace std;

int const n=110;
int inf=100000;
int g[n][n];
set<int>st;
int cs=1;

void path()
{
    double cost=0;
    for(auto it=st.begin();it!=st.end();it++)
    {
        for(auto it1=st.begin();it1!=st.end();it1++)
        {
            for(auto it2=st.begin();it2!=st.end();it2++)
            {
                int i=*it1;
                int j=*it2;
                int k=*it;

                if(i==j) continue;
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }

    for(auto it=st.begin();it!=st.end();it++)
    {
        for(auto it1=st.begin();it1!=st.end();it1++)
        {
            int i=*it;
            int j=*it1;

            if(g[i][j]==inf or g[i][j]==0) continue ;
            //cout<<"("<<i<<","<<j<<") => "<<g[i][j]<<"\n";
            cost+=g[i][j];
        }
    }

    int v=st.size();
    v*=(v-1);
    cost/=v;

    printf("Case %d: average length between pages = %.3lf clicks\n",cs,cost);
    cs++;
}

int main()
{
    freopen("task2.txt","r",stdin);
    int a,b,k=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) g[i][j]=0;
            else
            g[i][j]=inf;
        }
    }

    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==0 and b==0)
        {
            if(k)
            {
                k=0;
                path();

                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(i==j) g[i][j]=0;
                        else
                        g[i][j]=inf;
                    }
                }
                st.clear();
                continue;
            }
            else
            break;
        }

        g[a][b]=1;
        st.insert(a);
        st.insert(b);
        k=1;
    }
}
