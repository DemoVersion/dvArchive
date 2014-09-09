/*
	UVA 562 Solution Written By DemoVersion in 20140906.
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
    bool DP1[50100],DP2[50100];
    int minm,aa,bb,n,i,u,sum,T,A[111];
    cin>>T;
    while(T--){
        cin>>n;
		sum=0;
        memset(DP1,0,sizeof(DP1));
        memset(DP2,0,sizeof(DP2));
        while(n--){
            cin>>u;
            sum+=u;
            for(i=u;i<50100;i++){
                if(i==u || DP1[i-u]){
                    DP2[i]=1;
                }
            }
            memcpy(DP1,DP2,sizeof(DP1));

        }
        minm=sum;
        for(i=0;i<=sum;i++){
            if(DP1[i]==0)continue;
            minm=min(minm,abs(i*2-sum));
        }
        cout<<minm<<endl;
    }
    return 0;
}

