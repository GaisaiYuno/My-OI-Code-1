#include<iostream>
using namespace std;

struct idandage   //定义结构体
{
	char id[15];
	int age;
};
idandage input,young[110],old[110],u;




void pai3(int a,int b) {
	int i,j,mid;

	i=a;
	j=b;
	mid=old[(a+b)/2].age;
	do {
		while(old[i].age<mid) i++;
		while(old[j].age>mid) j--;
		if(i<=j) {
	 	//	if(old[i].age!=old[j].age)
			 {
	 				u=old[i];
				old[i]=old[j];
				old[j]=u;
			 }
		
		
			i++;
			j--;
		}
	} while(i<=j);
	if(a<j) pai3(a,j);
	if(i<b) pai3(i,b);
	}




int main() {
	int total;
	cin>>total;


	int t,o,y;
	o=y=0;
	for(int i=0; i<total; i++) {
		cin>>input.id>>input.age;
	
		if(input.age<60) {
			 young[y]=input;
			 y++;
		}
		else{
		  //   old[o].id=input.id;
		      old[o]=input;
			 o++;	
		}
		
	}
	pai3(0,o-2);

	for(int k=o-1;k>=0;k--) cout<<old[k].id<<'\n';
		for(int k=0;k<y;k++) cout<<young[k].id<<'\n';
	}

