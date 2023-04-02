#include<bits/stdc++.h>
using namespace std;

struct Rect{
    int x1,y1,x2,y2;//Using a structure reduces number of variables used
};
int ands(Rect p,Rect q){
    //taking the difference between the extreme right x co-ordinate and extreme left x co-ordinate
    int ansx=max(p.x2,q.x2)-min(p.x1,q.x1);
    //taking the difference between the extreme right y co-ordinate and extreme left y co-ordinate
    int ansy=max(p.y2,q.y2)-min(p.y1,q.y1);
    int ans1=max(ansx,ansy);
    return ans1*ans1;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    Rect p,q;
    cin>>p.x1>>p.y1>>p.x2>>p.y2;
    cin>>q.x1>>q.y1>>q.x2>>q.y2;
    cout<<ands(p,q);
    return 0;
}