#include <iostream>
#include <stdio.h>
using namespace std;

int n,d,k;
int dist[500000];
int value[500000];
int sum[500000];

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","r",stdout);
	std::cin >> n >> d >> k;
	for(int i = 1;i <= n;i++){
		cin >> dist[i] >> value[i];
		if(i != 1){
			dist[i] -= dist[i - 1];
		}
	}
	std::cout << "-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
