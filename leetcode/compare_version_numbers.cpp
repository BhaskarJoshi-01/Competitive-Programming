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

int compareVersion(string version1, string version2) {
    vector<string>s1,s2;
    stringstream check1(version1);
    string intermediate;
    while(getline(check1,intermediate,'.')){
        s1.push_back(intermediate);
    }
    stringstream check2(version2);
    string intermediate2;
    while(getline(check2,intermediate2,'.')){
        s2.push_back(intermediate2);
    }
    deb(version1,version2);
    int a = s1.size(),b = s2.size();
    if(a>b){
        int i=0;
        while(i<(a-b)){
            s2.push_back("0");
            i++;
        }
    }
    if(b>a){
        int i=0;
        while(i<(b-a)){
            s1.push_back("0");
            i++;
        }
    }
    for(int i=0;i<s2.size();i++){
        if(stoi(s1[i]) > stoi(s2[i])){
            return 1;
        }
        if(stoi(s1[i]) < stoi(s2[i])){
            return -1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // double vm, rss;
    // mem_usage(vm, rss);
    // cout << "Virtual Memory: " << vm << "\nResident set size: " << rss << endl;
    string s1,s2;cin>>s1>>s2;
    int temp = compareVersion(s1,s2);
    write("\n",temp);
}