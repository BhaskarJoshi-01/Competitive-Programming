#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	const int inf = 1e9;
	int n,m;
	cin>>n>>m;
	vector<int> dist(n+1,inf);
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i = 0;i<m;i++){
	    int u,v,w;
	    cin>>u>>v>>w;
	    adj[u].push_back({v,w});
	    adj[v].push_back({u,w});
	    
	}
	int k;
	cin>>k;
	set<pair<int,int>> s;
	dist[k] = 0;
	s.insert({0,k});
	while(!s.empty()){
	    auto x  = *(s.begin());
	    s.erase(x);
	    for(auto it:adj[x.second]){
	        if(dist[it.first]>it.second+dist[x.second]){
	            s.erase({dist[it.first],it.first});
	            
	            dist[it.first]  = it.second+dist[x.second];
	            s.insert({dist[it.first],it.first});
	        }
	    }
	}
	for(int i  =1;i<=n;i++){
	    if(dist[i]<inf){
	        cout<<dist[i]<<" ";
	    }else{
	        cout<<-1<<" ";
	    }
	}
	cout<<endl;
	return 0;
}