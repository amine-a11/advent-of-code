#include<bits/stdc++.h>
using namespace std;
#define nl "\n";
void solve(){
    vector<string> g;
	string s;
	while(cin>>s){
		g.push_back(s);
	}
    int x,y;
	int n = (int)g.size();
	int m = (int)g[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='^'){
				x=j;
				y=i;
				break;
			}
		}
	}
	int dx=0,dy=-1;
	vector<vector<bool>> used(n,vector<bool>(m,0));
	int ans=0;
	cout<<x<<" -  "<<y<<nl; 
	while(x!=0 && x!=m-1 && y!=0 && y!=n-1){
		if(!used[y][x])ans++;
		used[y][x]=true;
		int nx=x+dx,ny=y+dy;
		if(g[ny][nx]=='#'){
			dy*=-1;
			swap(dx,dy);
		}else{
			x=nx;y=ny;
		}
	}
	cout<<ans+1<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt=1,tc=1;
	//cout<<setprecision(9);
	freopen("in.txt","r",stdin);
	solve();
}

