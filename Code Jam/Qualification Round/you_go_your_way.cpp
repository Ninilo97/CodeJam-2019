#include<bits/stdc++.h>
#define fl(x,s,n) for(int x = s; x < n; ++x)
#define fle(x,s,n) for(int x = s; x <= n; ++x)
using namespace std;

const int N = 50010;

char s[N];
//int d[N],df[N];

int main(){
  int t;
  scanf("%d",&t);
  memset(s,'A',sizeof s);
  fle(i,1,t){
    int grd;
    scanf("%d",&grd);
    scanf("%s",s+1);
    printf("Case #%d: ",t);
    fle(j,1,2*grd-2){
      if(s[j]=='E') printf("S");
      else printf("E");
    }
    if(i==t) breakl
    printf("\n");
  }
  //+NBnb=
  return 0;
}
