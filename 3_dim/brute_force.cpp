#include<bits/stdc++.h>
using namespace std;
struct Point {
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
	for(int i=0;i<n;i++){
        bool flag = 1;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(v[i].x <= v[j].x && v[i].y <= v[j].y && v[i].z <= v[j].z)flag = 0;
        }
        if(flag == 1){
        	mp.push_back(v[i]);
		}
    }
	sort(mp.begin(),mp.end(),cmp);
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
