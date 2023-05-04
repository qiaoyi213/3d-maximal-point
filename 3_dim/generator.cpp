#include<bits/stdc++.h>
#include<random>
using namespace std;

int main(){
	int n,maxx;
	cout<<"n: ";
	cin>>n;
	cout<<"max: ";
	cin>>maxx;
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> dist(0,maxx);

	for(int i=1;i<=n;i++){
		string f_name = to_string(i) + ".in";
		ofstream f;
		f.open(f_name);
		f<<i<<"\n";
		for(int j=0;j<i;j++){
			f<<dist(rng)<<" "<<dist(rng)<<" "<<dist(rng)<<"\n";
		}
		f.close();
	}	
	return 0;
}

