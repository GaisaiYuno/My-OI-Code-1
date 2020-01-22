#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int name[1010],que[1010];

bool pd(int nam,int qu){
	int tmp=qu;
	int qu_len=0;
	while(tmp){
		tmp/=10;
		qu_len++;
	}
	tmp=qu_len;
	int x=1;
	while(tmp--)
		x*=10;
	int namex=nam%x;
	if(namex==qu) return 1;
	else return 0;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,unused;
	bool isok=0;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&name[i]);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&unused,&que[i]);
	sort(name+1,name+1+n);
	for(int i=1;i<=q;i++){
		isok=0;
		for(int j=1;j<=n;j++){
			if(pd(name[j],que[i])){
				printf("%d\n",name[j]);
				isok=1;
				break;
			}
		}
		if(!isok)
			printf("-1\n");
	}
	return 0;
}

