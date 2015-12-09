/*
	UVA 11474 Solution Written By DemoVersion in 20151210.
*/

#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>

#define Author "DemoVersion"
#define DBG(x) cout<<#x<<" = "<<x<<";\n"


using namespace std;
int dx[]={0,0,-1,1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long ull;

/// Hey yo man, lets do some contest!
int visited[110];
vector<int> adj[110];
int dist(int x1,int y1,int x2,int y2){
	int dx=x1-x2;
	int dy=y1-y2;
	return dx*dx + dy*dy;
}
int dfs(int v){
	int i;
	visited[v]=1;
	for(i=0;i<adj[v].size();i++){
		if(visited[adj[v][i]])continue;
		dfs(adj[v][i]);
	}
}
int main(){
    ios_base::sync_with_stdio(0);
	int T,n,m,k,d,i,j,K,L,u,v,b,n_f;
	vector<pii> doc;
	vector<pii> tree[110];

	int has_doc[110];
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		memset(has_doc,0,sizeof(has_doc));
		memset(visited,0,sizeof(visited));
		k*=k;d*=d;
		doc.clear();
		for(i=0;i<n;i++){
			tree[i].clear();
			adj[i].clear();
		}
		for(i=0;i<m;i++){
			cin>>u>>v;
			doc.push_back(pii(u,v));
		}
		for(i=0;i<n;i++){
			cin>>b;
			for(j=0;j<b;j++){
				cin>>u>>v;
				tree[i].push_back(pii(u,v));
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				n_f=1;
				for(K=0;K<tree[i].size() && n_f;K++){
					for(L=0;L<tree[j].size() && n_f;L++){
						if(dist(tree[i][K].first,tree[i][K].second,tree[j][L].first,tree[j][L].second) <= k){
							n_f=0;
						}
					}
				}
				if(n_f == 0){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				n_f=1;
				for(K=0;K<tree[i].size() && n_f;K++){
					if(dist(tree[i][K].first,tree[i][K].second,doc[j].first,doc[j].second) <= d){
						n_f=0;
					}
				}
				if(n_f == 0){
					has_doc[i]=1;
				}
			}
		}
		n_f=1;
		dfs(0);
		for(i=0;i<n && n_f;i++){
			if(visited[i] && has_doc[i]){
				n_f=0;
			}
		}
		if(n_f){
			cout<<"Tree can't be saved :(\n";
		}else{
			cout<<"Tree can be saved :)\n";
		}
	}
    return 0;
}
