#include<bits/stdc++.h>

using namespace std;

#define ll long long int
void insert(ll n,vector<ll>&h,ll x){
    h[n]=x;
    n++;
    ll i=n-1;
    while(i>0 && h[i]>h[(i-1)/2]){
        swap(h[i],h[(i-1)/2]);
        i=(i-1)/2;
    }
}
vector<ll> Constructmaxheap(vector<ll>a){
    ll n=a.size();
    vector<ll>h(n);
    for(int i=0;i<n;i++){
        insert(i,h,a[i]);
    }
    return h;
}
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<ll>max_h(n);

    max_h=Constructmaxheap(a);
    for(auto x:max_h){
        cout<<x<<" ";
    }
    return 0;
}