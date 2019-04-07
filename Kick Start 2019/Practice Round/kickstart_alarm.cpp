#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10,9)+7;
ll calPow(ll a,ll p){
  ll ret = 1,cp = a;
  while(p){
    if(p&1) ret = (ret*cp)%MOD;
    p >>= 1;
    cp = (cp*cp)%MOD;
  }
  return ret;
}
ll calK(ll i,ll k){
  if(i == 1) return k%MOD;
  ll ret = ((i*(calPow(i,k)-1)%MOD)*calPow(i-1,MOD-2))%MOD;
  return ret;
}
int main(){
  int T;
  cin >> T;
  for(int k = 1; k <= T; ++k){
    ll N,K,x1,y1,C,D,E1,E2,F;
    cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;
    vector<ll> A(N);
    A[0] = (x1+y1)%F;
    ll CD = C+D,E = E1+E2;
    for(ll i = 1; i < N; ++i) A[i] = (CD*A[i-1]+E)%F;
    ll psum = 0,nb = 1,kv = N,ret = 0, temp = 0;
    for(ll i = N-1; i >= 0; --i){
      psum = (psum+nb*A[i])%MOD;
      ++nb;
      temp = ret;
      ret = (ret+psum*calK(kv,K))%MOD;
      --kv;
    }
    cout << "Case #" << k << ": " << ret << "\n";
  }
  return 0;
}
