#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	printf("%d",(x/5+y*3/10+z/2));
}
