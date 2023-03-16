#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>graph[N];
set<pair<int,int>>st;
long long int cost=0;
bool visited[N]= {false};
int dist[N];
vector<int>vs;


void dijkstra(int s)
{
    for(int i=0; i<N; i++)
        dist[i]=INT_MAX;

    dist[s]=0;
    st.insert({0,s});

    bool r=true;
    while(st.size())
    {
        auto it=*st.begin();
        int u=it.second;
        st.erase(st.begin());
        if(visited[u]) continue;
        visited[u]=true;

        cout<<"proc "<<u<<"\n";
        if(r)
        {
            vs.push_back(u);
            if(u==4) r=false;
        }

        for(auto a:graph[u])
        {
            int v=a.first;
            int c=a.second;

            if(dist[u]+c<dist[v])
            {
                cout<<"t "<<v<<"\n";
                dist[v]=dist[u]+c;
                st.insert({dist[v],v});
            }
         }

 /*        for(auto p=st.begin();p!=st.end();p++)
         {
            int a=p.second;
            cout<<a<<" , ";

         }
         puts("");*/
    }
}

int main()
{
    freopen("dijkstra.txt","r",stdin);
    int n,k;
    cin>>n>>k;

    for(int i=0; i<k; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int s;
    cin>>s;
    dijkstra(s);

    cout<<"ans "<<dist[4]<<"\n";

    for(int i=0; i<vs.size(); i++)
    {
        if(i==3) continue;
        cout<<vs[i]<<"  ";
    }
}

