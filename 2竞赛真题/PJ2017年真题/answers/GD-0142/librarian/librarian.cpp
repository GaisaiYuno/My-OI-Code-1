#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1005
using namespace std;

int n,q;
int book[MAXN],reader[MAXN];

int main()
{
	int len,tmp,rnum[20];
	bool flag;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>book[i];
	}
	sort(book+1,book+n+1);
	
	for (int i=1;i<=q;i++){
		memset(rnum,0,sizeof(rnum));
		cin>>len>>tmp;
		for (int j=1;j<=len;j++){
			rnum[j]=tmp%10;
			tmp/=10;
		}
		flag=false;
		for (int j=1;j<=n;j++){
			tmp=book[j];
			for (int k=1;k<=len;k++){
				if (tmp%10!=rnum[k]){
					break;
				}
				if (k==len){
					cout<<book[j]<<endl;
					flag=true;
				}
				tmp/=10;
			}
			if (flag==true){
				break;
			}
			if (j==n&&flag==false){
				cout<<"-1"<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
