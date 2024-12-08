#include<bits/stdc++.h>
using namespace std;
#define nl "\n";

void solve(){
	vector<string> g;
	string s;
	while(cin>>s){
		g.push_back(s);
	}
	map<char,vector<array<int,2>>> pos;
	int n = (int)g.size();
	int m = (int)g[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]!='.'){
				pos[g[i][j]].push_back({i,j});
			}
		}
	}
	vector<vector<bool>> used(n,vector<bool>(m));
	for(auto [c,v] : pos){
		for(auto pos1 : v){
			for(auto pos2 : v){
				if(pos1[0]==pos2[0] && pos1[1]==pos2[1]){
					continue;
				}
				int x=2*pos1[0] - pos2[0];
				int y=2*pos1[1] - pos2[1];
				if(x>=0 && x<n && y>=0 && y<m){
					used[x][y]=true;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans+=used[i][j];
		}
	}
	cout<<ans<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<setprecision(9);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
}

