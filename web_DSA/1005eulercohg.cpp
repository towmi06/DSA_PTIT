#include<bits/stdc++.h>
using namespace std;
main(){
	int t,n,m,x,y;cin>>t;
	vector<int> List[1005];
	while(t--){
		for(int i=1;i<1005;i++) List[i].clear();
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		int count=0;
		for(int i=1;i<=n;i++){
			if(List[i].size()%2==1) count++;
		}
		if(count==0) cout<<"1\n";
		else cout<<"0\n";
	}
}