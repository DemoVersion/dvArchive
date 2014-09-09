/*
	UVA 11292 Solution Written By DemoVersion in 20140908.
*/
#pragma comment(linker, "/STACK:1234567890000")

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
    const int maxN=20*1000 + 10;
    int A[maxN],B[maxN];
    int n,m,i,p;
    ll ans;
    while(cin>>n>>m && n){
        ans=0;
        for(i=0;i<n;i++)cin>>A[i];
        for(i=0;i<m;i++)cin>>B[i];
        sort(A,A+n);
        sort(B,B+m);
        p=0;
        for(i=0;i<n;i++){
            if(p==m)break;
			while(B[p]<A[i]){
                p++;
                if(p==m)break;
            }
            if(p==m)break;
            ans+=B[p];
            p++;
        }
        if(i==n){
            cout<<ans<<endl;
        }else{
            cout<<"Loowater is doomed!"<<endl;
        }
    }


    return 0;
}
