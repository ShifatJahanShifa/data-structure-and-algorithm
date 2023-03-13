#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N];
int Size[N];

void make(int v)
{
    parent[v]=v;
    Size[v]=1;
}

int Find(int v)
{
    if(v==parent[v])
        return v;

    return parent[v]=Find(parent[v]);
}

void Union(int a,int b)
{
    a=Find(parent[a]);
    b=Find(parent[b]);

    if(a!=b)
    {
        if(Size[a]<Size[b])
            swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
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

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cout<<parent[i]<<" ";
        if(parent[i]==i)
            cnt++;
    }

    cout<<"\ncomponent "<<cnt;
}
