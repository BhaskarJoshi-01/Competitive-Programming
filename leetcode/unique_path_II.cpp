#include <bits/stdc++.h>
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
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << "\n";
}
template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void write(string delimiter, T &&...args)
{
    ((cout << args << delimiter), ...);
}
template <typename T>
void readContainer(T &t)
{
    for (auto &e : t)
    {
        read(e);
    }
}
template <typename T>
void writeContainer(string delimiter, T &t)
{
    for (const auto &e : t)
    {
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

int dp[101][101];

int uniquePathsWithObstacles(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    if (arr[0][0] == 1 || arr[n - 1][m - 1] == 1)
        return 0;
    int te = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 1)
            te = 0;
        dp[i][0] = te;
    }
    te = 1;
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == 1)
            te = 0;
        dp[0][i] = te;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // double vm, rss;
    // mem_usage(vm, rss);
    // cout << "Virtual Memory: " << vm << "\nResident set size: " << rss << endl;
    int m, n;
    cin >> n >> m;
    vector<vector<int>> obstacleGrid;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            temp.pb(t);
        }
        obstacleGrid.pb(temp);
    }
    int i = 0;
    int t = uniquePathsWithObstacles(obstacleGrid);
    write("\n", i);
    write("\n", t);
    auto ans = dp;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}