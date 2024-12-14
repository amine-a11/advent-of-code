#include<bits/stdc++.h>
using namespace std;
#define nl "\n";

vector<string> g;
int n,m;
vector<pair<int,int>> vis;
int go(int i,int j,int num){
	if(i>=n || i<0 || j>=m || j<0)return 0;
	if(g[i][j]-'0'==9 && num==9 && find(vis.begin(),vis.end(),make_pair(i,j))==vis.end()){
		vis.push_back({i,j});
		return 1;
	}
	if(g[i][j]-'0'==num){
		return go(i+1,j,num+1)+go(i-1,j,num+1)+go(i,j+1,num+1)+go(i,j-1,num+1);
	}
	return 0;
}

void solve(){
	string s;
	while(cin>>s){
		g.push_back(s);
	}
	n = (int)g.size();
	m = (int)g[0].length();
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans+=go(i,j,0);
			vis.clear();
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

