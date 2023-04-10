#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e8+10;
//vector<pair<int,int>>graph[N];

set<pair<int,int>>st;
long long int cost=0;
bool visited[N]= {false};

int dist[N];
void dijkstra(int s,int n,vector<vector<int>>&graph)
{

    for(int i=0; i<n; i++)
        dist[i]=1e8;

    dist[s]=0;
    //st.insert({0,s});
    for(int i=0; i<n-1; i++)
    {
        for(auto a:graph)
        {
            int u=a[0];
            int v=a[1];
            int w=a[2];

            if(dist[u]!=1e8 and dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                //st.insert({dist[v],v});
            }
        }
    }


//st.insert({0,s});


    for(auto a:graph)
    {
            int u=a[0];
            int v=a[1];
            int w=a[2];

            if(dist[u]!=1e8 and dist[u]+w<dist[v])
            {
                cout<<"negative";
            }
    }
}


int main()
{
    freopen("bellmanford.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    vector<vector<int>>graph(k,vector<int>(3));

    for(int i=0; i<k; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[i][0]=u;
        graph[i][1]=v;
        graph[i][2]=w;
        // graph[u].push_back({v,w});
        // graph[v].push_back({u,w});
    }

    int s;
    cin>>s;
    dijkstra(s,n,graph);

    for(int i=0; i<n; i++)
    {
        cout<<i<<" = "<<dist[i]<<"\n";
    }
}





