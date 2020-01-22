#include <cstdio>
#include <algorithm>
using namespace std;
int book[1005];
const int POWTEN[15]={1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
int main(){
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	
	int i, j;
	int n, q;
	int len, x;
	int isok;
	
	scanf("%d %d", &n, &q);
	for(i=1; i<=n; i++)
		scanf("%d", &book[i]);
	sort(book+1, book+1+n);
	for(i=1; i<=q; i++){
		scanf("%d %d", &len, &x);
		len=POWTEN[len];
		isok=0;
		for(j=1; j<=n; j++){
			if(book[j]%len==x){
				isok=1;
				break;
			}
		}
		if(isok)
			printf("%d\n", book[j]);
		else
			printf("-1\n"); 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
