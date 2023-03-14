#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>graph[N];
set<pair<int,int>>st;
long long int cost=0;
bool visited[N]={false};
int dist[N];

void dijkstra(int s)
{
    for(int i=0;i<N;i++)
        dist[i]=INT_MAX;

    dist[s]=0;
    st.insert({0,s});

    while(st.size())
    {
        auto it=*st.begin();
        int u=it.second;
        st.erase(st.begin());
        if(visited[u]) continue;
        visited[u]=true;

        for(auto a:graph[u])
        {
            int v=a.first;
            int c=a.second;

            if(dist[u]+c<dist[v])
            {
                dist[v]=dist[u]+c;
                st.insert({dist[v],v});
            }
        }
    }
}

int main()
{
    freopen("dijkstra.txt","r",stdin);
    int n,k;
    cin>>n>>k;

    for(int i=0;i<k;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int s;
    cin>>s;
    dijkstra(s);

   for(int i=0;i<n;i++)
    {
        cout<<i<<" = "<<dist[i]<<"\n";
    }
}




