#include<bits/stdc++.h>
// #include<unistd.h>
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

// memory usage
// void mem_usage(double& vm_usage, double& resident_set) {
//    vm_usage = 0.0;
//    resident_set = 0.0;
//    ifstream stat_stream("/proc/self/stat",ios_base::in); //get info from proc directory
//    //create some variables to get info
//    string pid, comm, state, ppid, pgrp, session, tty_nr;
//    string tpgid, flags, minflt, cminflt, majflt, cmajflt;
//    string utime, stime, cutime, cstime, priority, nice;
//    string O, itrealvalue, starttime;
//    unsigned long vsize;
//    long rss;
//    stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
//    >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
//    >> utime >> stime >> cutime >> cstime >> priority >> nice
//    >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest
//    stat_stream.close();
//    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // for x86-64 is configured to use 2MB pages
//    vm_usage = vsize / 1024.0;
//    resident_set = rss * page_size_kb;
// }2 3 1 1 4
// vector<vector<int>> val;
// void permute(vector<int> arr){
//     int n = arr.size();
//     int i=n-1;
//     while(i>0 && arr[i-1]>=arr[i]){
//         i--;
//     }
//     if(i==0) return;
//     else{
//         int temp = INT_MAX,k=i;
//         for(int j=i;j<n;j++){
//             if(arr[j]<arr[k] && arr[j]>arr[i-1]){
//                 k = j;
//             }
//         }
//         swap(arr[i-1],arr[k]);
//         sort(arr.begin()+i,arr.end());
//         val.push_back(arr);
//         permute(arr);
//     }
// }

// int main(){
//     int t;cin>>t;
//     while(t--){
//         int n;cin>>n;
//         vector<int>arr;
//         for(int i=0;i<n;i++){
//             int temp;cin>>temp;
//             arr.push_back(temp);
//         }
//         sort(arr.begin(),arr.end());
//         val.push_back(arr);
//         permute(arr);
//         auto ans = val;
//         for(int i=0;i<ans.size();i++){
//             for(int j=0;j<ans[0].size();j++){
//                 write(" ",ans[i][j]);
//             }
//             write("","\n");
//         }
//     }
// }
vector<vector<int>> ans;
void recurse(vector<int> arr,int st,int cur_siz,vector<int>temp_arr){
    int n = arr.size();
    if(st > n) return;
    if(n<=1) {
        ans.push_back(arr);
        return;
    }
    if(cur_siz == n-1) {
        ans.push_back(temp_arr);
        return;
    }
    int t = arr[st];
    for(int i=st+1;i<n;i++){
        if(arr[i]==t) continue;
        else{
            t = arr[i];
        }
        temp_arr.push_back(arr[i]);
        recurse(arr,i+1,cur_siz+1,temp_arr);
        temp_arr.pop_back();
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        vector<int> temp_arr;
        recurse(arr,0,0,temp_arr);
        write("\n",arr.size());
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                write(" ",ans[i][j]);
            }
            write("","\n");
        }
    }
}