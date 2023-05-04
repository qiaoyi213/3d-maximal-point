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
vector<Point> v;
vector<Point> M;
vector<Point> Star;
int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		Point tmp;
		cin>>tmp.x>>tmp.y>>tmp.z;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp);
	int zmax = v[0].z-1;
	for(int i=0;i<n;i++){
		if(i !=0 && v[i-1].x != v[i].x)zmax = v[i].z-1;
		if(v[i].z > zmax){
			zmax = v[i].z;
			M.push_back(v[i]);
		}
	}
	Star.push_back(M[0]);
	for(int i=1;i<M.size();i++){
		bool flag = 1;
		for(int j=0;j<Star.size();j++){
			if(Star[j].x >= M[i].x && Star[j].y >= M[i].y && Star[j].z >= M[i].z){
				flag = 0;
				break;
			}
		}
		if(flag)Star.push_back(M[i]);
	}
//	printf("Maximal Point:\n");
	for(int i=0;i<Star.size();i++){
		printf("%d %d %d\n", Star[i].x, Star[i].y, Star[i].z);
	}
	return 0;
}
