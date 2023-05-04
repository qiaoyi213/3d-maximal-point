#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y,z;
};

bool cmp(Point i1, Point i2){
	if(i1.x == i2.x){
		if(i1.y == i2.y)
			return i1.z > i2.z;
		return i1.y > i2.y;
	}
	return i1.x > i2.x;
}
int n;
vector<Point> v;
vector<Point> M;
vector<Point> mp;

void get_data(int N){ //read N.in file
	string file_name;
	file_name = to_string(N) + ".in";
	ifstream f(file_name);
	string s;
	stringstream ss;
	getline(f, s);
	ss << s;
	ss >> n;
	for(int i=0;i<n;i++){
		getline(f, s);
		ss.clear();
		ss << s;
		Point tmp;
		ss >> tmp.x;
		ss >> tmp.y;
		ss >> tmp.z;
		v.push_back(tmp);
	}
	f.close();
}


void solve(){
	sort(v.begin(),v.end(),cmp);
        int zmax = v[0].z-1;
        for(int i=0;i<n;i++){
            if(i !=0 && v[i-1].x != v[i].x)zmax = v[i].z-1;
            if(v[i].z > zmax){
                zmax = v[i].z;
                M.push_back(v[i]);
            }
        }
        mp.push_back(M[0]);
        for(int i=1;i<M.size();i++){
            bool flag = 1;
            for(int j=0;j<mp.size();j++){
                if(mp[j].x >= M[i].x && mp[j].y >= M[i].y && mp[j].z >= M[i].z){
                    flag = 0;
                    break;
                }
            }
            if(flag)mp.push_back(M[i]);
        }
}

int main(){
	clock_t t1,t2;
	get_data(1);
	ofstream ans("1.out");
	t1 = clock();
	solve();
	t2 = clock();
	for(int i=0;i<mp.size();i++){
		ans<<mp[i].x<<" "<<mp[i].y<<" "<<mp[i].z<<"\n";
	}
	ans.close();
	cout<<to_string(double(t2-t1)/CLOCKS_PER_SEC)<<"\n";
	return 0;
}
