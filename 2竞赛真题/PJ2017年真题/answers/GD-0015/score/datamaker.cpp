#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	freopen("score.in","w",stdout);
	srand(time(0));
	printf("%d %d %d",rand()%10*10,rand()%10*10,rand()%10*10);
}
