#include<bits/stdc++.h>
using namespace std;
#define nl "\n";

void solve(){
	string s;
	cin>>s;
	vector<int> v;
	for(int i=0;i<(int)s.size();i++){
		if(i%2==0){
			for(int j=0;j<s[i]-'0';j++)v.push_back(i/2);
		}else{
			for(int j=0;j<s[i]-'0';j++)v.push_back(-1);
		}
	}
	int n=(int)v.size();
	for(int i=0,j=n-1;i<j;){
		if(v[i]==-1 && v[j]!=-1){
			v[i]=v[j];
			v[j]=-1;
			i++;
			j--;
		}
		else if(v[i]!=-1)i++;
		else if(v[j]==-1)j--;
	}
	long long ans=0;
	for(long long i=0;i<(long long)n;i++){
		if(v[i]==-1)break;
		ans+=v[i]*i;
	}
	cout<<ans<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
}

