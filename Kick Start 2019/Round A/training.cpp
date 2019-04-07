#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int kk = 1; kk <= T; ++kk){
    int n, p;
    cin >> n >> p;
    int A[n],S[n-p];
    for(int k = 0; k < n; ++k) cin >> A[k];
    sort(A, A+n, greater<>());
    S[0]=0;
    for(int k = 1; k < p; ++k) S[0] += A[k];
    for(int k = 1; k <= n-p; ++k)S[k] = S[k-1]-A[k]+A[k+p-1];
    ll mn=10000000000000006,res=0;
    for(int k = 0; k <= n-p; ++k){
        res = (p-1)*A[k]-S[k];
        if(res<mn) mn=res;
        if(mn==0) break;
    }
    cout << "Case #" <<kk<<": "<< mn << endl;
  }
  return 0;
}
