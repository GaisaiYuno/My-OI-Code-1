//醫嗷 譫о腔籟騷
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 20
using namespace std;
int a,b,c;
bool used[maxn][maxn][maxn];
int ans[maxn];
int cnt=0; 
void dfs(int x,int y,int z) {
	if(used[x][y][z]) return;
	if(x==0) ans[cnt++]=z;
	used[x][y][z]=true;
	if(y+z>b) dfs(x,b,y+z-b);//c給b 
	else dfs(x,y+z,0);
	if(x+z>a) dfs(a,y,x+z-a);//c給a 
	else dfs(x+z,y,0);
	if(z+y>c) dfs(x,z+y-c,c);//b給c 
	else dfs(x,0,z+y);
	if(x+y>a) dfs(a,x+y-a,z);//b給a 
	else dfs(x+y,0,z);
	if(y+x>b) dfs(y+x-b,b,z);//a給b 
	else dfs(0,y+x,z);
	if(x+z>c) dfs(x+z-c,y,c);//a給c 
	else dfs(0,y,x+z);
	return;
}
int main() {
	memset(used,false,sizeof(used));
	cin>>a>>b>>c;
	dfs(0,0,c);
    sort(ans,ans+cnt);	
    for(int i=0;i<cnt;i++) cout<<ans[i]<<' ';
    return 0;
}
