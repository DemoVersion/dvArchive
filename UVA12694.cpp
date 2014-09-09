/*
	UVA 12694 Solution Written By DemoVersion in 20140903.
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
using namespace std;
int dx[]={0,0,-1,1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main(){

    ios_base::sync_with_stdio(0);
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    int a,b,i;
    cin>>T;
	vector<pii> datas,select;
    while(T--){
		datas.clear();
		select.clear();
		while(cin>>a>>b){
			if(a==0&&b==0)break;
			datas.push_back(pii(b,a));
		}
		sort(datas.begin(),datas.end());
		select.push_back(datas[0]);
		for(auto ev : datas){
			if(ev.second>=select[select.size()-1].first){
				select.push_back(ev);
			}
		}
		cout<<select.size()<<endl;
    }
    return 0;
}