#include<bits/stdc++.h>

using namespace std;

#define ll long long int
/*insertion takes O(log(n)) add element at last index and go up till it meet element less than it*/
void insert(ll n,ll x,vector<ll>&h){
    h[n]=x;
    n++;
    ll i=n-1;
    while(i>0 && h[i]<h[(i-1)/2]){
        swap(h[i],h[(i-1)/2]);
        i=(i-1)/2;
    }
}
/*remove_min takes O(log(n)) min element is in root of heap first swap root element with last element
  after check child elements which is minimum value and check that minimum value is greater than parent
  or not if yes break ,else swap and move parent down.
*/
ll remove_min(ll n,vector<ll>&h){
    swap(h[0],h[n]);
    n--;
    ll i=0;
    while((2*i+1)<=n){
        ll j=2*i+1;
        if((2*i+2)<=n && h[2*i+2]<h[j]){
            j=2*i+2;
        }
        if(h[i]<=h[j])break;

        swap(h[i],h[j]);
        i=j;
    }
    return h[n+1];
}
void heapsort(vector<ll>&a){
    ll n=a.size();
   vector<ll>h(n,0);
   for(int i=0;i<n;i++){
    insert(i,a[i],h);
   }
   
   for(int i=0;i<n;i++){
    //we will remove minimum element in heap and assign to array 
    a[i]=remove_min(n-i-1,h);
   }
}
int main(){
   ll n;cin>>n;
   vector<ll>a(n);
   for(int i=0;i<n;i++)cin>>a[i];

   /*heap sort O(n*(logn)) time */
   heapsort(a);
  
   for(auto c:a)cout<<c<<" ";
    cout<<"\n";
   return 0;
}