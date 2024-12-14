#include<bits/stdc++.h>
using namespace std;
#define nl "\n";
void print(vector<array<int,2>> v){
	for(int i=0;i<(int)v.size();i++){
		if(v[i][0]==0)continue;
		for(int j=0;j<v[i][0];j++){
			if(v[i][1]==-1){
				cout<<'.';
			}else{
				cout<<v[i][1];
			}
		}
	}
	cout<<nl;
}
void solve(){
	string s;
	cin>>s;
	vector<array<int,2>> v;
	for(int i=0;i<(int)s.size();i++){
		if(i%2==0){
			v.push_back({s[i]-'0',i/2});
		}else{
			v.push_back({s[i]-'0',-1});
		}
	}
	for(int i=(int)v.size()-1;i>0;i--){
		if(v[i][1]==-1)continue;
		for(int l=0;l<i;l++){
			if(v[l][1]!=-1)continue;
			if(v[l][0]>=v[i][0]){
				v[l][0]-=v[i][0];
				v.insert(v.begin()+l,v[i]);
				v[i+1][1]=-1;
				break;
			}
		}
	}
	long long ans=0;
	int k=0;
	for(int i=0;i<(int)v.size();i++){
		if(v[i][0]==0)continue;
		for(int j=0;j<v[i][0];j++){
			if(v[i][1]!=-1)ans+=v[i][1]*k;
			k++;
		}
	}
	cout<<"ans = "<<ans<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
}

