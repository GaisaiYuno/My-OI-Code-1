#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,t;
//int main() {
//	while(scanf("%d %d",&n,&t)!=EOF) {
//		if(t==2) {
//			for(int i=1; i<n; i++) printf("1");
//			printf("2\n");
//		} else if(t==3) {
//			if(n>1){
//			printf("1");
//			for(int i=2; i<n; i++) printf("0");
//			printf("2\n");
//			}else printf("3\n");
//		} else if(t==4) {
//			if(n<=1){
//             	 printf("4\n");
//			 }else if(n<=2){
//			 	 printf("16\n");
//			 }else{
//			 	 printf("1");
//			 	 for(int i=2; i<n; i++) printf("0");
//			     printf("4\n");
//			 }
//		} else if(t==5) {
//			if(n>1)printf("1");
//			for(int i=2; i<n; i++) printf("0");
//			printf("5\n");
//		} else if(t==6) {
//			if(n>1) {
//				printf("2");
//				for(int i=2; i<n; i++) printf("0");
//				printf("4\n");
//			}else  printf("6\n");
//		} else if(t==7) {
//            while(n>2){
//            	printf("777");
//            	n-=3;
//			}
//			if(n==2)printf("77\n");
//			else if(n==1)printf("7\n");
//			else printf("\n");
//		} else if(t==8) {
//             if(n<=1){
//             	 printf("8\n");
//			 }else if(n<=2){
//			 	 printf("16\n");
//			 }else if(n<=3){
//			 	 printf("888\n");
//			 }else{
//			 	printf("1");
//			 	for(int i=1;i<n-3;i++) printf("0");
//			 	printf("888\n");
//			 }
//		} else if(t==9) {
//			if(n>1){
//				printf("1");
//				for(int i=1;i<=n-2;i++) printf("0");
//				printf("8\n");
//			}else printf("9\n");
//		}else if(t==10){
//			if(n>1){
//				printf("1");
//				for(int i=2;i<=n;i++) printf("0");
//				printf("\n");
//			}else printf("-1\n");
//		}
//
//	}
//}
int main() {
	while(scanf("%d %d",&n,&t)!=EOF) {
		if(t<10) {
			for(int i=1; i<=n; i++) printf("%d",t);
			printf("\n");
		}else{
			if(n>1){
				printf("1");
				for(int i=2;i<=n;i++) printf("0");
				printf("\n");
			}else printf("-1\n");
		} 
	}
}
