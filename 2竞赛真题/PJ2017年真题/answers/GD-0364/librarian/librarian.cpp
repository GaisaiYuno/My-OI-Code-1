#include <cstdio>
using namespace std;
int n,q,nu,qu,MI[20];
struct Book{
	int num;
	int length;
}book[2010];
void qs(int x,int y) {
	int i = x,j = y;
	Book m = book[(i+j)/2];
	while (i<j) {
		while (book[i].num<m.num) ++i;
		while (book[j].num>m.num) --j;
		if (i<=j) {
			Book temp = book[i];
			book[i] = book[j];
			book[j] = temp;
			++i; --j;
		} 
	}
	if (i<y) qs(i,y);
	if (x<j) qs(x,j);
}
int cal(int num) {
	int result = 0;
	while (num>0) {
		num /= 10;
		++result;
	}
	return result;
}
void init() {
	int num = 1;
	for (int i = 0;i<10;i++) {
		MI[i] = num;
		num*=10;
	}
}
int main() {
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 0;i<n;i++) {
		scanf("%d",&book[i].num);
		book[i].length = cal(book[i].num);
	}
	qs(0,n-1);
	init();
	int result = -1;
	for (int i = 0;i<q;i++) {
		scanf("%d%d",&nu,&qu);
		result = -1;
		for (int j = 0;j<n;j++) {
			if (book[j].length<nu) continue;
			if (book[j].num%MI[nu]==qu) {
				result = book[j].num;
				break;
			}
		}
		printf("%d\n",result);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
