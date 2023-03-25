#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26]= {NULL};
    bool flag=false;
    bool isContainKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};

Node *root=new Node;

bool insert(string word)
{
    Node *node=root;
    int len=word.size(),track=0;
    for(int i=0; i<word.size(); i++)
    {
        if(node->isContainKey(word[i])==false)
        {
            if(node->isEnd())
            {
                return true;
            }
            node->put(word[i], new Node);
            node=node->get(word[i]);
        }
        else
        {
            node=node->get(word[i]);
            track++;
        }
    }

    if(track==len)
        return true;

    node->setEnd();
    return false;
}

int main()
{
    int n;
    cin>>n;
    string s;
    bool ans=false;

    while(n--)
    {
        cin>>s;

        if(insert(s))
        {
            ans=true;
        }
    }

    ans ? puts("vulnerable") : puts("non vulnerable");
}
