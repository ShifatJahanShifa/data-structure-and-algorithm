#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>graph[N];
set<pair<int,int>>st;
long long int cost=0;
bool visited[N]={false};
int dist[N];
int parent[N];

void prim(int s)
{
    for(int i=0;i<N;i++){
       dist[i]=INT_MAX;
       parent[i]=-1;
    }

    vector<pair<int,int>>result;
    dist[s]=0;
    st.insert({0,s});

    while(st.size())
    {
        auto it=*st.begin();
        int u=it.second;
        st.erase(st.begin());
        if(visited[u]) continue;
        visited[u]=true;
        result.push_back({u,it.first});
        cost+=it.first;

        for(auto a:graph[u])
        {
            int v=a.first;
            int c=a.second;

            if(c<dist[v])
            {
                dist[v]=c;
                st.insert({dist[v],v});
                parent[v]=u;
            }
        }
    }

    int track=1;

    for(auto it:result)
    {
        if(track)
        {
            track=0;
            continue;
        }
        cout<<"pair("<<parent[it.first]<<","<<it.first<<")=> "<<it.second<<"\n";
    }

    cout<<"Cost : "<<cost;
}

int main()
{
    freopen("prim.txt","r",stdin);
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
    prim(s);
}




