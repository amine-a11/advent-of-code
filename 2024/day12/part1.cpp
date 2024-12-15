#include<bits/stdc++.h>
using namespace std;
#define nl "\n";
vector<string> g;
vector<vector<bool>> vis;
const vector<array<int,2>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
void go(int i,int j,int& ar,int& pr,char c){
	if(!vis[i][j]){
		vis[i][j]=true;
		ar++;
		int ok=0;
		for(auto &[x,y] : dir){
			if(i+x>=0 && i+x<n && j+y>=0 && j+y<m){
				if(g[i+x][j+y]!=c)ok++;
				else go(i+x,j+y,ar,pr,c);
			}else{
				ok++;
			}
		}
		pr+=ok;
	}
}
void solve(){
	string s;
	while(cin>>s){
		g.push_back(s);
	}
	n=(int)g.size();
	m=(int)g[0].length();
	vis.resize(n,vector<bool>(m,false));
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]){
				int ar=0,pr=0;
				go(i,j,ar,pr,g[i][j]);
				ans+=ar*pr;
			}
		}
	}
	cout<<"ans = "<<ans<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt","r",stdin);
	solve();
}

