#include <iostream>
#include <stdio.h>

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c;
	std::cin >> a >> b >> c;
	double ans;
	ans = a * 0.2 + b * 0.3 + c * 0.5;
	ans = (int)(ans);
	std::cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
