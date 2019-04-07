#include <bits/stdc++.h>
#define fl(x,s,n) for(int x = s; x < n; ++x)
#define fle(x,s,n) for(int x = s; x <= n; ++x)

using namespace std;

const int N = 512, inf=1e9;

int n,m;
char s[N][N];
int d[N][N];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void dfs(){
  memset(d,-1,sizeof d);
  queue<pair<int,int>> que;
  fle(i,1,n){
    fle(j,1,m){
      if(s[i][j]){
        d[i][j]=0;
        que.emplace(i,j);
      }
    }
  }
  while(!que.empty()){
    int x,y;
    tie(x,y) = que.front();
    que.pop();
    fl(i,0,4){
      int xx=x+dx[i], yy=y+dy[i];
      if(min(xx,yy)<=0 or xx>n or yy>m) continue;
      if(d[xx][yy]!=-1) continue;
      d[xx][yy]=d[x][y]+1;
      que.emplace(xx,yy);
    }
  }
  fle(i,1,n){
    fle(j,1,m){
      if(d[i][j]==-1) d[i][j]=inf;
    }
  }
}

bool can(int x){
  int pmx = inf, pmn = -inf, mmx = inf, mmn = -inf;
  bool ok = 1;
  fle(i,1,n){
    fle(j,1,m){
      if(d[i][j]<=x) continue;
      pmx = min(pmx,i+j+x);
      pmn = max(pmn,i+j-x);
      mmx = min(mmx,i-j+x);
      mmn = max(mmn,i-j-x);
      ok = 0;
    }
  }
  if(ok) return true;
  fle(i,1,n){
    fle(j,1,m){
      int mx = i+j, mn = i-j;
      if(pmn<=mx and mx<=pmx and mmn<=mn and mn<=mmx) return true;
    }
  }
  return false;
}

void solve(int t){
    scanf("%d %d",&n,&m);
    fle(i,1,n){
      scanf("%s",s[i]+1);
      fle(j,1,m){
        s[i][j]-='0';
      }
    }
    dfs();
    int lo=0,hi=inf;
    while(lo<hi){
      int mid = (lo+hi)>>1;
      if(can(mid)) hi=mid;
      else lo = mid+1;
    }
    printf("Case #%d: %d\n",t,hi);
}

int main(){
  int t;
  scanf("%d",&t);
  fle(cs,1,t){
    solve(cs);
  }
  return 0;
}
