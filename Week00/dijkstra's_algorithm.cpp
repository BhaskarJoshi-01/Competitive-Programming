#include<bits/stdc++.h>

using namespace std;

priority_queue < pair <int,int> , vector< pair <int,int> > , greater<pair<int,int> > > q; //weight,vertex
vector <long long int> dist(100005,INT_MAX);
int n,A,B;
vector< vector <pair<int,int> > > graph;
void shortestPath_phase1(int a)
{
    q.push(make_pair(0,a));
    dist[a] = 0;
    int i;
    while(!q.empty())
    {
        int l = q.top().second;
        q.pop();

        for(i=0;i<graph[l].size();i++)
        {
            int v = graph[l][i].first;
            int weight = graph[l][i].second;
           // cout<<v<<" "<<dist[v]<<" "<<l<<" "<<dist[l]<<" "<<weight<<endl;

            if(dist[v] > dist[l] + weight)
            {
                if(weight <= A)
                {
                    dist[v] = dist[l] + weight;
                    q.push(make_pair(dist[v],v));
                }  //preCalc[v] = true;
            }
       // cout<<dist[v]<<endl;
        }
        //preCalc[l] = true;
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }*/
}
void shortestPath_phase2(int a)
{
    q.push(make_pair(0,a));
    dist[a] = 0;
    int i;
    for(i=1;i<=n;i++)
    {
        q.push(make_pair(dist[i],i));
    }
    while(!q.empty())
    {
        int l = q.top().second;
        q.pop();
        for(i=0;i<graph[l].size();i++)
        {
            int v = graph[l][i].first;
            int weight = graph[l][i].second;

           // if(dist[v] == INT_MAX && dist[l] == INT_MAX);
            //if(!preCalc[v])
            //{
                //cout<<l<<" "<<dist[l]<<" "<<v<<" "<<dist[v]<<" "<<weight<<endl;
                if(dist[v] > dist[l] + weight)
                {
                    if(weight >= B)
                    {
                        dist[v] = dist[l] + weight;
                        q.push(make_pair(dist[v],v));
                    }
                }
                 //cout<<dist[l]<<" "<<dist[v]<<endl;
           // }
        }
    }
    for(i = 1; i <= n ; i++)
    {
        if(dist[i] >= INT_MAX)
        {
            dist[i] = -1;
        }
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }*/
}
int main(void)
{
    int i,m,src,dest;
    cin>>n>>m;
    graph.resize(n+1);
    for(i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    cin>>src>>dest>>A>>B;
    shortestPath_phase1(src);
    shortestPath_phase2(src);
    cout<<dist[dest]<<endl;
    return 0;
}
/*
4 4
1 2 4
2 3 4
3 4 2
1 3 6
1 4 4 6

4 6
1 2 2
2 4 4
2 3 6
3 4 10
1 4 6
1 3 9
1 3 5 6
*/
