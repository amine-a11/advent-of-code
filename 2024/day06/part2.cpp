#include<bits/stdc++.h>
using namespace std;
#define nl "\n";
vector<string> g;
int n,m,xg,yg;
bool check(int xx,int yy){
	vector<string> gg=g;
	gg[yy][xx]='#';
	vector<vector<set<pair<int,int>>>> used(n,vector<set<pair<int,int>>>(m));
	int x=xg,y=yg;
	int dx=0,dy=-1;
	while(x!=0 && x!=m-1 && y!=0 && y!=n-1){
		if(used[y][x].find({dx,dy})!=used[y][x].end()){
			return true;
		}
		int nx=x+dx,ny=y+dy;
		if(gg[ny][nx]=='#'){
		    used[y][x].insert({dx,dy});
			dy*=-1;
			swap(dx,dy);
		}else{
			x=nx;
			y=ny;
		}
	}
	return false;
}
void solve(){
	string s;
	while(cin>>s){
		g.push_back(s);
	}
	n = (int)g.size();
	m = (int)g[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='^'){
				xg=j;
				yg=i;
				break;
			}
		}
	}
	int dx=0,dy=-1;
	int x=xg,y=yg;
	int ans=0;
	bool sk=false;
	vector<vector<bool>> used(n,vector<bool>(m,0));
	while(x!=0 && x!=m-1 && y!=0 && y!=n-1){
		if(!used[y][x]){
			if(check(x,y))ans++;
		}
		used[y][x]=true;
		int nx=x+dx,ny=y+dy;
		if(g[ny][nx]=='#'){
			dy*=-1;
			swap(dx,dy);
		}else{
			x=nx;y=ny;
		}
	}
	cout<<ans+check(x,y)<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<setprecision(9);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
}

