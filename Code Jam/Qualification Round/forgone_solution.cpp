#include<bits/stdc++.h>
#define fl(x,s,n) for(int x = s; x < n; ++x)
#define fle(x,s,n) for(int x = s; x <= n; ++x)
using namespace std;

const int N = 200;

char s[N];
int d[N],df[N];

int main(){
  int t;
  scanf("%d",&t);
  memset(s,'s',sizeof s);
  memset(df,0,sizeof d);
  fle(i,1,t){
    int len=0;
    scanf("%s",s+1);
    fle(j,1,N){
      if(s[j+1]=='s') break;
      len+=1;
      d[j]=s[j]-'0';
    }
    fle(i,1,N){
      if(d[i]==4) df[i]=1;
    }
    printf("Case #%d: ",t);
    fle(i,1,len){
      if(df[i]!=1) printf("%d",d[i]);
      else printf("%d",d[i]-1);
    }
    printf(" ");
    fle(i,1,len){
      printf("%d",df[i]);
    }
    printf("\n");
  }
  //+NBnb=
  return 0;
}
