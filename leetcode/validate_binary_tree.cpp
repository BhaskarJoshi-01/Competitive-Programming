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
// }

vector<vector<string>> arr;
bool check_palindrome(string s,int st,int en){
    while(st<en){
        if(s[st]!=s[en]) return false;
        st++;
        en--;
    }
    return true;
}
void check(string s,int st,int en,vector<string>ans){
    if(st>en){
        arr.push_back(ans);
        return;
    }
    int t =st;
    for(int i=st;i<=en;i++){
        if(check_palindrome(s,st,i)){
            ans.push_back(s.substr(st,i-st+1));
            check(s,i+1,en,ans);
            ans.pop_back();
        }
    }
    return;
}
void partition(string s) {
    int n = s.size();
    vector<string>ans;
    check(s,0,n-1,ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // double vm, rss;
    // mem_usage(vm, rss);
    // cout << "Virtual Memory: " << vm << "\nResident set size: " << rss << endl;
    string s;cin>>s;
    partition(s);
    cout<<s.size()<<" : "<< arr.size() <<"\n";
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}