#include<iostream>
using namespace std;
int n,x[26]= {0};//数字
int m[26]= {0};//进位
bool usednum[26]= {0};//记录某个数字是否用过
bool usedlet[26]= {0};//记录某个字母是否访问过
int ans=0;
char s1[26],s2[26],s3[26],sums[78];
bool backok(int now) {//判断now之后每一列的数是否合法，重要剪枝！
	bool right=1;
	for(int i=3*n-1; i>now; i-=3) {
		if((usedlet[sums[i]-65]&&usedlet[sums[i-1]-65]&&usedlet[sums[i-2]-65])&&
		        (x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65])%n
		         &&x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65]+1)%n)) {
			/*如果之后某一列的字母都已经算出（知道字母对应的数）：   (usedlet[sums[i]-65]&&usedlet[sums[i-1]-65]&&usedlet[sums[i-2]-65])
			   判断那一位的和是否正确  x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65])%n （不考虑之前有进位）
			                        x[sums[i]-65]!=(x[sums[i-1]-65]+x[sums[i-2]-65]+1)%n （考虑之前有进位）
			*/
			right=0;
			break;//不正确就break
		}
	}
	return right;
}
bool ok(int now) {//判断now之前每一行的数字加起来是否合法
	if(now%3!=2) return true;//如果没有算完一整行，直接返回，继续算
	int cons=now/3*3,sum=x[sums[cons]-65]+x[sums[cons+1]-65]+m[now/3];//类似高精度加法
	int temp=sum;
	sum=sum%n;
	if(sum==x[sums[cons+2]-65]) {
		m[now/3+1]=temp/n;
		return true;
	} else return false;
}
void dfs(int now) { //now为目前sums数组下标，即目前算出的列数 
	if(ans) return;
	if(!ok(now-1)) return;//如果now之前的数 不行，返回 
	if(!backok(now-1)) return; //如果now之后的数 不行，返回 
	if(now==3*n) {
		ans=1;
		for(int i=0; i<n; i++) cout<<x[i]<<" ";
		return;
	}
	if(!usedlet[sums[now]-65]) {
		for(int i=n-1; i>=0; i--) {//枚举i 
			if(!usednum[i]) {
				int tempm=m[now/3];//防止进位状况在下一次dfs中被改变 
				x[sums[now]-65]=i;
				usednum[i]=1;
				usedlet[sums[now]-65]=1;
				dfs(now+1);
				m[now/3]=tempm;//恢复变量 
				usednum[i]=0;
				usedlet[sums[now]-65]=0;
			}
		}
	} else dfs(now+1);
	return;
}
int main() {
	cin>>n;
	//预处理sums
	for(int i=0; i<n; i++) {
		cin>>s1[i];
		sums[3*(n-1-i)]=s1[i];
	}
	for(int i=0; i<n; i++) {
		cin>>s2[i];
		sums[3*(n-1-i)+1]=s2[i];
	}
	for(int i=0; i<n; i++) {
		cin>>s3[i];
		sums[3*(n-1-i)+2]=s3[i];
		/*
		4
		ABCD
		EFGH
		IJKL
		sums-->DHLCGKBFJAEI
		搜索sums[0~3*n-1]
		*/
	}
	dfs(0);
	return 0;
}
