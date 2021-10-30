#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
double PI = acos(-1);
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define alla(arr, sz) arr, arr + sz
#define st(v) sort(all(v))
#define revrs(v) reverse(all(v))
#define sta(arr, sz) sort(alla(arr, sz))
#define revrsa(arr, sz) reverse(alla(arr, sz))
#define tc(t) while (t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout<<"\n";
}
template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}
template <typename... T>
void write(string delimiter, T &&...args) {
    ((cout << args << delimiter), ...);
}
template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}
template <typename T>
void writeContainer(string delimiter, T &t) {
    for (const auto &e : t) {
        write(delimiter, e);
    }
    write("\n");
}

int main(){
    fastio;
    int n,m;cin>>n>>m;
    vector<vector<int>>edges(n*m,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;cin>>temp;
            for(int k=0;k<4;k++){
                if(((temp>>k)&1) !=1){
                    switch (k){
                    case 3:
                        edges[i*m+j].pb(i*m+j-m);
                        break;
                    case 2:
                        edges[i*m+j].pb(i*m+j+1);
                        break;
                    case 1:
                        edges[i*m+j].pb(i*m+j+m);
                        break;
                    case 0:
                        edges[i*m+j].pb(i*m+j-1);
                        break;
                    default:
                        printf("Failure at i:%d, j:%d, k:%d\n",i,j,k);
                        break;
                    }
                }
            }
        }
    }
    vector<int>ans;
    vector<bool>visited(n*m,false);
    for(int i=0;i<n*m;i++){
        if(!visited[i]){
            int temp=0;
            queue<int>qt;
            qt.push(i);
            visited[i] = true;
            while(!qt.empty()){
                int cur = qt.front();
                qt.pop();
                temp++;
                for(int j=0;j<edges[cur].size();j++){
                    if(!visited[edges[cur][j]]){
                        visited[edges[cur][j]]=true;
                        qt.push(edges[cur][j]);
                    }
                }
            }
            ans.pb(temp);
        }
    }
    sort(all(ans),greater<int>());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}