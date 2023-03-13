#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N];

void make(int v)
{
    parent[v]=v;
}

int Find(int v)
{
    if(v==parent[v])
        return v;

    return Find(parent[v]);
}

void Union(int a,int b)
{
    a=Find(parent[a]);
    b=Find(parent[b]);

    if(a!=b)
    {
        parent[b]=a;
    }
}
int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<parent[i]<<" ";
    }

}
