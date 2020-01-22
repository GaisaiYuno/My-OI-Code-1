#include<iostream>
#include<cstdio>
#define maxn 10
using namespace std;
char a[maxn][maxn];
int ans,n;
//int xx[4]= {1,-1,0,0},yy[4]= {0,0,-1,1};
int judge(int x,int y) {
	for(int i=x-1; i>=0; i--) {
		if(a[i][y]=='U') return 0;//如果此行上面有碉堡就返回
		if(a[i][y]=='X')break; //如果在遇到碉堡之前先有了一道墙则继续，可以放置
	}
	for(int i=y-1; i>=0; i--) {
		if(a[x][i]=='U') return 0;//如果此列上面有碉堡就返回
		if(a[x][i]=='X')break;//如果在遇到碉堡之前先有了一道墙则继续，可以放置
	}
	return 1;
}
void dfs(int d,int now_ans) {
	if(d==n*n) {
		ans=max(now_ans,ans);
		return;
	}
	int x=d/n;
	int y=d%n;
	if(a[x][y]=='.'&&judge(x,y)) { //当前位置是空地并且可以放置碉堡
		a[x][y]='U';//放置碉堡
		dfs(d+1,now_ans+1);
		a[x][y]='.';
	}
	dfs(d+1,now_ans);
}
int main() {
	 while(1)  
    {  
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++)  
            for(int j=0;j<n;j++)  cin>>a[i][j];  
        dfs(0,0);  
        cout<<ans<<endl;  
    }  
	return 0;
}
