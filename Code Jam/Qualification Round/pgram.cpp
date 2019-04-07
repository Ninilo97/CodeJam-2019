#include<bits/stdc++.h>
#define fl(x,s,n) for(int x = s; x < n; ++x)
#define fle(x,s,n) for(int x = s; x <= n; ++x)
using namespace std;
const int N = 101;

vector<int> a,s;
char al[N];

vector<int> uniques(vector<int> m){
  m.emplace_back(0);
  vector<int> mm;
  fl(i,0,m.size()-2){
    if(m.at(i)==m.at(i+1)){
      mm.emplace_back(i+1);
    }
    else if(m.at(i)==m.at(i+2)){
      mm.emplace_back(i+2);
    }
  }
  sort(mm.begin(),mm.end());
  reverse(mm.begin(),mm.end());
  for(auto i:mm) m.erase(m.begin()+i);
  return m;
}

void primeFactors(){
  int n;
  scanf("%d",&n);
  while (n%2 == 0){
    a.emplace_back(2);
    s.emplace_back(2);
    n = n/2;
  }
  for(int i = 3; i <= sqrt(n); i = i+2){
    while(n%i == 0){
      a.emplace_back(i);
      s.emplace_back(i);
      n = n/i;
    }
  }
  if(n > 2){
      a.emplace_back(n);
      s.emplace_back(n);
  }
}

int main(){
  int t;
  scanf("%d",&t);
  fle(cse,1,t){
    s.clear();
    a.clear();
    int n, l;
    scanf("%d%d",&n,&l);
    fle(i,1,l){
      primeFactors();
    }
    sort(a.begin(),a.end());

    set<int> s1;
    unsigned size = a.size();
    for(unsigned i=0;i<size; ++i) s1.insert(a[i]);
    a.assign(s1.begin(),s1.end());
    fle(i,65,90) al[i-65]=i;
    map<int,char> mp;
    fle(i,0,25) mp[a[i]]=al[i];
    vector<int> temp=uniques(uniques(s));
    cout<<"Case #"<<cse<<": ";
    fle(i,0,l+10){
      cout<<mp[temp[i]];
    }
    cout<<"\n";
  }
  return 0;
}
