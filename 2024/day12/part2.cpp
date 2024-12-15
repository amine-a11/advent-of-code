#include<bits/stdc++.h>
using namespace std;
#define nl "\n";
vector<string> g;
vector<vector<bool>> vis;
const vector<array<int,2>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
map<int,vector<int>> s1,s2;
void go(int i,int j,int& ar,char c){
	if(!vis[i][j]){
		vis[i][j]=true;
		ar++;
		for(auto [x,y] : dir){
			if(i+x>=0 && i+x<n && j+y>=0 && j+y<m){
				if(g[i+x][j+y]!=c){
					if(x==0)s1[(y==1?j+y:-(j+y))].push_back(i);
					else s2[(x==1?i+x:-(i+x))].push_back(j);
				}
				else go(i+x,j+y,ar,c);
			}else{
				if(x==0)s1[(y==1?j+y:-(j+y))].push_back(i);
				else s2[(x==1?i+x:-(i+x))].push_back(j);
			}
		}
	}
}
int calc(vector<int> vv){
	sort(vv.begin(),vv.end());
	int n = (int)vv.size();
	int ans=0;
	vector<bool> used(n,false);
	for(int i=0;i<n;i++){
		if(!used[i]){
			int k = vv[i];
			used[i]=true;
			for(int j=i+1;j<n;j++){
				if(used[j])continue;
				if(abs(vv[j]-k)==1){
					k=vv[j];
					used[j]=true;
				}
			}
			ans++;
		}
	}
	return ans;
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
				go(i,j,ar,g[i][j]);
				for(auto [a,vec] : s1){
					pr+=calc(vec);
				}
				for(auto [a,vec] : s2){
					pr+=calc(vec);
				}
				ans+=pr*ar;
				// cout << g[i][j] << ": " << ar << " " << pr << "\n";
				s1.clear();
				s2.clear();
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

