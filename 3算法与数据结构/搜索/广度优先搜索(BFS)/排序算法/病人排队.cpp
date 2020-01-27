#include<iostream>
using namespace std;
struct idandage   //定义结构体
{
	char id[15];
	int age;
};
idandage input,young[110],old[110],u;

void pai2(int n) {

	int x,j,i;
	for(i=1; i<n; i++) {
		u=old[i];
		j=i-1;
		while(u.age>old[j].age&&j>=0) {
			old[j+1]=old[j];
			j--;
		}
		old[j+1]=u;
	}
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
//	pai3(0,o-1);
    pai2(o);
	for(int k=0;k<o;k++) cout<<old[k].id<<'\n';
	for(int k=0;k<y;k++) cout<<young[k].id<<'\n';
	}

