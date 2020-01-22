#include<iostream>
#include<cstdio>
using namespace std;
int m,n,i,j,x,y,z,jb,s[200][200];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		if (z==0) s[x][y]=1;
		if (z==1) s[x][y]=2;
	}
	i=1;j=1;
	while (i!=m||j!=m)
	{
		if (s[i][j]==1)
		{
			if (s[i][j+1]==1) {s[i][j]=0;j++;} else
			if (s[i+1][j]==1) {s[i][j]=0;i++;} else
			if (s[i][j-1]==1) {s[i][j]=0;j--;} else
			if (s[i-1][j]==1) {s[i][j]=0;i--;} else
			if (s[i][j+1]==2) {s[i][j]=0;j++;jb++;} else
			if (s[i+1][j]==2) {s[i][j]=0;i++;jb++;} else
			if (s[i][j-1]==2) {s[i][j]=0;j--;jb++;} else
			if (s[i-1][j]==2) {s[i][j]=0;i--;jb++;} else
			if (s[i+1][j+1]!=0) {if (s[i][j]!=s[i+1][j+1]){s[i][j]=0;i++;j++;jb+=3;}else{s[i][j]=0;i++;j++;jb+=2;}} else
			if (s[i+1][j-1]!=0) {if (s[i][j]!=s[i+1][j-1]){s[i][j]=0;i++;j--;jb+=3;}else{s[i][j]=0;i++;j--;jb+=2;}} else
			if (s[i-1][j+1]!=0) {if (s[i][j]!=s[i-1][j+1]){s[i][j]=0;i--;j++;jb+=3;}else{s[i][j]=0;i--;j++;jb+=2;}} else
			if (s[i-1][j-1]!=0) {if (s[i][j]!=s[i-1][j-1]){s[i][j]=0;i--;j--;jb+=3;}else{s[i][j]=0;i--;j--;jb+=2;}} else
			if (s[i][j+2]!=0) {if (s[i][j]!=s[i][j+2]){s[i][j]=0;j+=2;jb+=3;}else{s[i][j]=0;j+=2;jb+=2;}} else
			if (s[i+2][j]!=0) {if (s[i][j]!=s[i+2][j]){s[i][j]=0;i+=2;jb+=3;}else{s[i][j]=0;i+=2;jb+=2;}} else
			if (s[i][j-2]!=0) {if (s[i][j]!=s[i][j-2]){s[i][j]=0;j-=2;jb+=3;}else{s[i][j]=0;j-=2;jb+=2;}} else
			if (s[i-2][j]!=0) {if (s[i][j]!=s[i-2][j]){s[i][j]=0;i-=2;jb+=3;}else{s[i][j]=0;i-=2;jb+=2;}} else {cout<<-1<<endl;return 0;}
		} else
		if (s[i][j]==2)
		{
			if (s[i][j+1]==2) {s[i][j]=0;j++;} else
			if (s[i+1][j]==2) {s[i][j]=0;i++;} else
			if (s[i][j-1]==2) {s[i][j]=0;j--;} else
			if (s[i-1][j]==2) {s[i][j]=0;i--;} else
			if (s[i][j+1]==1) {s[i][j]=0;j++;jb++;} else
			if (s[i+1][j]==1) {s[i][j]=0;i++;jb++;} else
			if (s[i][j-1]==1) {s[i][j]=0;j--;jb++;} else
			if (s[i-1][j]==1) {s[i][j]=0;i--;jb++;} else
			if (s[i+1][j+1]!=0) {if (s[i][j]!=s[i+1][j+1]){s[i][j]=0;i++;j++;jb+=3;}else{s[i][j]=0;i++;j++;jb+=2;}} else
			if (s[i+1][j-1]!=0) {if (s[i][j]!=s[i+1][j-1]){s[i][j]=0;i++;j--;jb+=3;}else{s[i][j]=0;i++;j--;jb+=2;}} else
			if (s[i-1][j+1]!=0) {if (s[i][j]!=s[i-1][j+1]){s[i][j]=0;i--;j++;jb+=3;}else{s[i][j]=0;i--;j++;jb+=2;}} else
			if (s[i-1][j-1]!=0) {if (s[i][j]!=s[i-1][j-1]){s[i][j]=0;i--;j--;jb+=3;}else{s[i][j]=0;i--;j--;jb+=2;}} else
			if (s[i][j+2]!=0) {if (s[i][j]!=s[i][j+2]){s[i][j]=0;j+=2;jb+=3;}else{s[i][j]=0;j+=2;jb+=2;}} else
			if (s[i+2][j]!=0) {if (s[i][j]!=s[i+2][j]){s[i][j]=0;i+=2;jb+=3;}else{s[i][j]=0;i+=2;jb+=2;}} else
			if (s[i][j-2]!=0) {if (s[i][j]!=s[i][j-2]){s[i][j]=0;j-=2;jb+=3;}else{s[i][j]=0;j-=2;jb+=2;}} else
			if (s[i-2][j]!=0) {if (s[i][j]!=s[i-2][j]){s[i][j]=0;i-=2;jb+=3;}else{s[i][j]=0;i-=2;jb+=2;}} else {cout<<-1<<endl;return 0;}
		}
	}
	cout<<jb<<endl;
	return 0;
}
