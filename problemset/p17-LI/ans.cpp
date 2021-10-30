#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second

int main(){
    int t;cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll delta_x1 = (x1-x2);
        ll delta_y1 = (y1-y2);
        ll delta_x3 = (x3-x4);
        ll delta_y3 = (y3-y4);
        pair<pair<__int128_t,__int128_t>,__int128_t> line1;
        pair<pair<__int128_t,__int128_t>,__int128_t> line2;
        line1 = {{(-1*delta_y1),(delta_x1)},(-1*((y1*(delta_x1) + x1*(-1*delta_y1))))};
        line2 = {{(-1*delta_y3),(delta_x3)},(-1*((y3*(delta_x3) + x3*(-1*delta_y3))))};
        ll term1 = (line1.f.f)*(line2.f.s)-(line1.f.s)*(line2.f.f);
        ll term2 = (line1.s)*(line2.f.s)-(line1.f.s)*(line2.s);
        if(term1 == 0 && term2 == 0) cout<<"Yes\n"; // coinciding
        else if(term1 == 0 && term2 !=0) cout<<"No\n"; // parallel
        else{ // intersecting
            ld denom = (((line1.f.f)*(line2.f.s)-(ld)(line2.f.f)*(line1.f.s)));
            ld point_x = (ld)(((line1.f.s)*(line2.s))-((line2.f.s)*(line1.s)))/denom;
            ld point_y = -(ld)(((line1.f.f)*(line2.s))-((line2.f.f)*(line1.s)))/denom;
            bool t1 = ((point_x-min(x1,x2)>-0.001)&&(point_x-max(x1,x2)<0.001));
            bool t2 = ((point_y-min(y1,y2)>-0.001)&&(point_y-max(y1,y2)<0.001));
            bool t3 = ((point_x-min(x3,x4)>-0.001)&&(point_x-max(x3,x4)<0.001));
            bool t4 = ((point_y-min(y3,y4)>-0.001)&&(point_y-max(y3,y4)<0.001));
            if(t1&t2&t3&t4) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}