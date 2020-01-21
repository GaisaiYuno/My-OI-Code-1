#include<iostream>
#include<stdlib.h>
#include<time.h>
//#define random(x) (rand()%x)
int temp=0;
int a;
using namespace std;
int my_rand(int in){
	srand((int)time(0));
	int out;
	out=rand()%100;
	while(out>=in||out==0){ 
	out=rand()%100;
    } 
    return out;
} 
bool judg(){

	
}
int  main() {
	while(cin.get()=='\n'){
			a=my_rand(39);
			//cout<<"学号是："<<a;
			while(temp==a){
				a=my_rand(39);
			}
			temp=a;
			cout<<"学号是："<<a;
	}

}





