#include<bits/stdc++.h>
#define fl(x,s,n) for(int x = s; x < n; ++x)
#define fle(x,s,n) for(int x = s; x <= n; ++x)
#define flem(x,s,n) for(int x = s; x >= n; --x)
#define flc(x,s,n,i) for(int x = s; x <= n; x+i)
using namespace std;
int a[10][1025];

void prep(){
  fle(i,1,10){
    fle(j,1,1024){
      a[i][j]=1;
    }
  }
  int x=0,tm = 1024;
  //+NBnb=
  fle(i,1,10){
    tm>>=1;
    x=0;
    fle(j,1,(int)pow(2,i-1)){
      fle(k,1+x,tm+x) a[i][k]=0;
      x+=tm+tm;
    }
  }
  //+NBnb=
  fle(i,1,10){
    fle(j,1,1024){
      //cout<<a[i][j];
    }
    //cout<<"\n";
  }
}

void solve(){
  int n,b,f;
  scanf("%d%d%d",&n,&b,&f);
  //+NBnb=
  fle(i,n-(int)log2(n),n){
    fle(j,1,n)
      printf("%d",a[i][j]);
    printf("\n");
  }
  //for(int i=0;i<(int)log2(n);i++)
  //+NBnb=
}

int main(){
  prep();
  int t;
  scanf("%d",&t);
  fle(cse,1,t){
    //+NBnb=
    solve();
    printf("Case #%d: ",cse);
  }
  return 0;
}
