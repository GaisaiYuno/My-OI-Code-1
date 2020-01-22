#include<cstdio>
#include<cstring>
using namespace std;
bool flag;
int n,q,len[1001],zhi;
char book[1001][8],need[1001][8],last[8];
bool bj(char a[],char b[]){
	int len1=strlen(a),len2=strlen(b);
	if(len1>len2) return true;
	if(len1<len2) return false;
	int l=strlen(a)-1,r=strlen(b)-1;
	while(b[r]==' ') r--;
	while(l>=0&&r>=0){
		if(a[l]>b[r]) return true;
		if(a[l]<b[r]) return false;
		l--;r--;
	}
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",&book[i]);
	}
	for(int i=1;i<=q;i++){
		int x;
		scanf("%d",&x);
		scanf("%s",&need[i]);
		len[i]=x;
	}
	for(int i=1;i<=q;i++){
		for(int l=0;l<=7;l++) last[l]='9';
		zhi=0;
		for(int j=1;j<=n;j++){
			int r=strlen(book[j])-1;
			int r2=len[i]-1;
			flag=true;
			while(r>=0&&r2>=0){
				if(need[i][r2]!=book[j][r]){
					flag=false;break;
				}
				else r2--,r--;
			}
			if(flag&&r>=r2){
				flag=true;
				if(!bj(book[j],last)){
					for(int k=0;k<strlen(last);k++){
						if(k<=strlen(book[j])) last[k]=book[j][k];
						else last[k]=' ';
					}
					zhi=j;
				}
			}
			else flag=true;
		}
		if(zhi!=0) printf("%s\n",book[zhi]);
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
