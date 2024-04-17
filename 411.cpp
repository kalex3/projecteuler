#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};
bool operator<(const Point& l, const Point& r){
    return tie(l.x,l.y)<tie(r.x,r.y);
}
bool operator==(const Point& l, const Point& r){
    return tie(l.x,l.y)==tie(r.x,r.y);
}
Point a[50000000];

int main(){
    int sum=1;
    for(int k=2;k<=30;k++){
        int n=k*k*k*k*k,N=2*n+1; a[0]={1,1};
        for(int i=1;i<N;i++){
            a[i].x=a[i-1].x*2%n;
            a[i].y=a[i-1].y*3%n;
            if(a[i]==Point{0,0}){
                N=i;
                break;
            }
        }
        sort(a,a+N);
        N=unique(a,a+N)-a;
        multiset<int> s;
        for(int i=0;i<N;i++){
            s.insert(a[i].y);
            auto it=s.upper_bound(a[i].y);
            if(it!=s.end()) s.erase(it);
        }
        sum+=s.size();
    }
    cout << sum;
}
//output: 9936352
