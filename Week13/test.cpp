#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int t=20000;
    cout <<1<<endl;
    cout << t <<endl;
    for(int i=1;i<=t;i++){
        cout << rand()%20000 << " ";
    }
    for(int i=1;i<=t;i++){
        cout << t << " ";
    }
    cout<<"\n";
}