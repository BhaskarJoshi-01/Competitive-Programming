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

int  remove_duplicates(vector<int>&arr){
    int n =arr.size();
    vector<int>ans;
    if(n<=2) return n;
    int t1=arr[0],t2=1;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        // deb(t1,t2,arr[i],ans.size());
        if(t1!=arr[i]){
            t1 = arr[i];
            t2 = 1;
            ans.push_back(arr[i]);
        }
        else if(t1 == arr[i] && t2<2){
            ans.push_back(arr[i]);
            t2++;
        }
        // deb(t1,t2,arr[i],ans.size());
        // write("\n","----");
    }
    // write("\n",ans.size());
    for(int i=0;i<ans.size();i++) arr[i] = ans[i];
    return ans.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // double vm, rss;
    // mem_usage(vm, rss);
    // cout << "Virtual Memory: " << vm << "\nResident set size: " << rss << endl;
    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int temp; cin>>temp;
        arr.pb(temp);
    }
    int val = remove_duplicates(arr);
    write("\n",val);
    for(int i=0;i<val;i++) write(" ",arr[i]);
    write("","\n");
}