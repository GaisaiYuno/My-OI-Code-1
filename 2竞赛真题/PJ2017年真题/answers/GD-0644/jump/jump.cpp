#include <iostream>
#include <fstream>

using namespace std;
int n,d,k;int maxx=0;
short score[50000]={0};
int main() {
	ifstream infile;
	infile.open("jump.in");
	ofstream outfile;
	outfile.open("jump.out");
	infile >> n >> d >> k;
	int countt=0;
	for (int i=1;i<=n;++i)
	{
		int far;
		infile >> far;
		if (far > maxx) maxx=far;
		infile >> score[far];
		if (score[far]>0) countt+=score[far];
	}
	if (countt<k) {
	outfile << -1;
	infile.close();
	outfile.close();
	return 0;
	}
	int i;bool flag=false;
	for (i=1;i<maxx,!flag;++i)
	{
		int step=1,sum=0;
		while (step<=maxx)
		{
			sum+=score[step];
			if (sum>=k) 
			{
			flag=true;
			break;
		    }
			step+=i;
		}
	}
    if (!flag) outfile << -1;
    else if (d<i) outfile << i-d;
    else if (d>i) outfile << d-i;
    else outfile << 0;
	infile.close();
	outfile.close();
	return 0;
}
