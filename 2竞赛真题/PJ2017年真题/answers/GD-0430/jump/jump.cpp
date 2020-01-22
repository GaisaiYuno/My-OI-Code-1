#include<bits/stdc++.h>
using namespace std;
int n,d,k,s1[500001],s2[500001],ans;
bool ji;
void jump(int x,int li,int he){
	if(he>=k){
	ji=true;return;}
	int l=1;
	if(d-li<=(s1[x+l]-s1[x])<=d+li){
		he+=s2[x+l];
		l++;
		jump(x+1,li,he);
	} 
}
int main(){
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);
  cin>>n>>d>>k;
  for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
  int tak=0;
  for(int i=1;i<=n;i++)if(s2[i]>0)tak+=s2[i];
  if(tak<k){
    cout<<-1; 
    return 0;
  } 
  ans=1;
  while(ji==false){
  	jump(0,ans,0);
  	ans++;
  }
  cout<<ans;
}
