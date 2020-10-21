#include<bits/stdc++.h>

using namespace std;
queue <int> q;
bool visited[1000];
vector <int> arr;
vector<vector <int> > graph;
void bfs(int a)
{
    visited[a] = true;
    q.push(a);

    int j,i;

    while(!q.empty())
    {
        j = q.front();
        arr.push_back(j);
        cout<<j<<" ";
        q.pop();

        for(i=0;i<graph[a].size();i++)
        {
            if(!visited[graph[a][i]])
            {
                visited[graph[a][i]] = true;
                q.push(graph[a][i]);
            }
        }
    }
}
int main(void)
{
    int n,m,k,l;
    cin>>n>>m;
    graph.resize(n+1);
    for(k=1;k<=n;k++)
    {
        visited[k] = false;
    }
    for(k=0;k<m;k++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(l=1;l<=n;l++){
    if(!visited[l])
    bfs(l);
    }
    cout<<endl;
    for(k=0;k<arr.size();k++)
        cout<<arr[k]<<" ";
    return 0;
}
