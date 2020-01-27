#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const double eps=1e-3;
double fun(double a1,double a2,int b) {
	switch(b) {
		case 0:
			return (a1+a2);
		case 1:
			return (a1-a2);
		case 2:
			return (a1*a2);
		case 3:
			return (a1/a2);
	}
}
int equa(double x,double y){
	if(x-y<=eps&&x-y>=-eps) return 1;
	else return 0;
}
int main() {
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout); 
	int ans=0;
	int i,j,k,l,n,m,r,flg=1,num[4],q=0;
	double tem1,tem2,tem3;
	char sign[5]="+-*/";
	for(i=0; i<4; i++) {
		scanf("%d",&num[i]);
	}
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(j!=i) {
				for(k=0; k<4; k++) {
					if(k!=i&&k!=j) {
						for(l=0; l<4; l++)
							if(l!=i&&l!=j&&l!=k) {
								for(n=0; n<4; n++)
									for(m=0; m<4; m++)
										for(r=0; r<4; r++) {
											tem1=fun(num[i],num[j],n);
											tem2=fun(tem1,num[k],m);
											tem3=fun(tem2,num[l],r);
											if(equa(tem3,24.0)) {
													printf("{(%d%c%d)%c%d}%c%d=24\n",save[i],sign[n],save[j],sign[m],save[k],sign[r],save[l]);
												ans++;
											} else if(equa(tem3,-24.0)) {
												if(sign[m]=='-') {
														printf("{%d%c(%d%c%d)}%c%d=24\n",save[k],sign[m],save[i],sign[n],save[j],sign[r],save[l]);
													ans++;
												}
											} else if(equa(tem3,1.0/24.0) ){
												if(sign[r]=='/')

												{
														printf("%d%c{(%d%c%d)%c%d}=24\n",save[l],sign[r],save[i],sign[n],save[j],sign[m],save[k]);
													ans++;
												}
											} else if(equa(tem3,-1.0/24.0)) {
												if(sign[m]=='-'&&sign[r]=='/')

												{
														printf("%d%c{%d%c(%d%c%d)}=24\n",save[l],sign[r],save[k],sign[m],save[i],sign[n],save[j]);
													ans++;
												}
											}

											else {
												tem1=fun(num[i],num[j],n);
												tem2=fun(num[k],num[l],r);
												tem3=fun(tem1,tem2,m);
												if(equa(tem3,24.0)) {
														printf("(%d%c%d)%c(%d%c%d)=24\n",save[i],sign[n],save[j],sign[m],save[k],sign[r],save[l]);
													ans++;
												}
											}
										}
							}

					}

				}
			}
		}
	}

	printf("%d\n",ans);
}
