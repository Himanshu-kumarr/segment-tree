#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
using namespace std;

class sgtree{
    vector<int> seg;
    public:
    sgtree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx,int low,int high,int a[]){
    if(low==high){
        seg[idx]=a[low];
    }
    int mid = (low+high)/2;
    build(2*idx+1,low,mid,a);
    build(2*idx+2,mid+1,high,a);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
    return;
}
int query(int idx,int low,int high,int l,int r){
    if(l<=low and r>=high){
        return seg[idx];
    }
    if(high<l || low>r) return INT_MIN;
    int mid = (low+high)/2;
    int left = query(2*idx+1,low,mid,l,r);
    int right = query(2*idx+1,mid+1,high,l,r);
    return max(left,right);
}
void update(int idx,int i,int val,int low,int high){
   if(low==high){
    seg[idx]=val;
    return;
   }
   int mid =(low+high)/2;
   if(i<=mid){
    update(2*idx+1,i,val,low,mid);
   }
   else{
    update(2*idx+2,i,val,mid+1,high);
   }
   seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
   return ;
}

};
// int main() {
    
//     ll n,l,r,m,p,q,x,y,z,sum,as,ans;
//     cin>>n;
//      for(int i=0;i<n;i++){
//         cin>>a[i];
//      }
//      build(0,0,n-1,a);
//     return 0;
// }
