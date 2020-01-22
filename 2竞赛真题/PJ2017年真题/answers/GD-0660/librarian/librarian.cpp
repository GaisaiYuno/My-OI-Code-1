#include<cstdio>
#include<algorithm>
using namespace std;
int need,book[1001],N,M,len;
int F();
int F(){
	bool B=true,OK=false;
	int MIN=19883627,Book,Need;
	for(int i=1;i<=N;i++){
		Book=book[i]; Need=need;
		for(int j=1;j<=len;j++){
			if(Book%10!=Need%10){B=false; break;}
			Book/=10; Need/=10;
		}
		if(B){OK=true; MIN=min(MIN,book[i]);}
		B=true;
	}    
	if(OK) return MIN;
	else return -1;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%d",&book[i]);
	for(int i=1;i<=N;i++){
		scanf("%d %d",&len,&need);
		printf("%d\n",F());
	}
	fclose(stdin);
	fclose(stdout);
}
