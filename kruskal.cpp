#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N];
int Size[N];
struct Pair
{
    int a;
    int b;
    int cost;
};

int result[N];

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
    freopen("kruskal.txt","r",stdin);
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    struct Pair pairs[k];

    for(int i=0; i<k; i++)
    {
        cin>>pairs[i].a;
        cin>>pairs[i].b;
        cin>>pairs[i].cost;
    }

    for(int i=1; i<k; i++)
    {
        for(int j=k-1; j>=i; j--)
        {
            if(pairs[j].cost<pairs[j-1].cost)
            {
                struct Pair temp;

                temp=pairs[j-1];
                pairs[j-1]=pairs[j];
                pairs[j]=temp;
            }
        }
    }


    int track=0;
    int totalCost=0;

    for(int i=0; i<k; i++)
    {
        int v1,v2;
        v1=pairs[i].a;
        v2=pairs[i].b;

        if(Find(v1)!=Find(v2))
        {
            totalCost+=pairs[i].cost;
            Union(v1,v2);
            track++;
        }
    }

    for(int i=0; i<track; i++)
    {
        cout<<"pair("<<pairs[i].a<<","<<pairs[i].b<<") => "<<pairs[i].cost<<"\n";
    }

    cout<<"total cost: "<<totalCost;

}
