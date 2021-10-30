#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
double PI = acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define st(v) sort(ALL(v))
#define revrs(v) reverse(ALL(v))
#define sta(arr, sz) sort(ALLA(arr, sz))
#define revrsa(arr, sz) reverse(ALLA(arr, sz))
#define TC(t) while (t--)
//  For debug
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

void print_ans(int ans[],int n){
    for(int i=0;i<n;i++) write(" ",++ans[i]);
    write("","\n");
}

int main(){
    int t;cin>>t;
    TC(t){
        int n;cin>>n;
        int ans[n]={0},start[n]={0};
        vector<int>temp1,temp2;
        bool visited[n]={0};
        for(int i=0;i<n;i++){
            int temp;cin>>temp;--temp;
            start[i]=temp;
            if(!visited[temp]){
                visited[temp]=true;
                ans[i]=temp;
            }
            else temp1.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]) temp2.push_back(i);
        }
        int lam = temp1.size();
        if(temp1.size()==0) {
            write("\n",(n-lam));
            print_ans(ans,n);
            continue;
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1.size()==1 && temp1[0]==temp2[0]){
            ans[temp1[0]]=start[temp1[0]];
            // deb(temp1[0],temp2[0]);
            for(int i=0;i<n;i++){
                if(ans[i]==start[temp1[0]]&&i!=temp1[0]){
                    ans[i]=temp2[0];
                    break;
                }
            }
        }
        else{
            if(temp1[0]==temp2[0])swap(temp2[0],temp2[temp2.size()-1]);
            for(int i=1;i<temp2.size();i++){
                if(temp1[i]==temp2[i])swap(temp2[i-1],temp2[i]);
            }
            for(int i=0;i<temp1.size();i++){
                ans[temp1[i]] = temp2[i];
            }
        }
        write("\n",(n-lam));
        print_ans(ans,n);
    }
}