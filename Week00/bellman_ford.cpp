#include<bits/stdc++.h>

using namespace std;

priority_queue < pair <int,int> , vector< pair <int,int> > , greater<pair<int,int> > > q; //weight,vertex
vector <int> dist(10000,INT_MAX);
int n;
vector< vector <pair<int,int> > > graph;
void shortestPath(int a)
{
    dist[a] = 0;
    int i,j;
    for(i = 1;i <= n-1; i++)
    {
        for(j = 0;j<graph[i].size();j++)
        {
            int v = graph[i][j].first;
            int weight = graph[i][j].second;
            if(dist[v] > dist[i] + weight)
            {
                dist[v] = dist[i] + weight;
            }
        }
    }
    for(i = 1 ;i <= n ; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
}
int main(void)
{
    int i,m;
    cin>>n>>m;
    graph.resize(n+1);
    for(i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    shortestPath(1);
    return 0;
}
