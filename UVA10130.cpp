/*
	UVA 10130 Solution Written By DemoVersion in 20140906.
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
    int DP1[40],DP2[40];
    int i,T,w,p,n,G,out;
    cin>>T;
    while(T--){
        out=0;
        memset(DP1,0,sizeof(DP1));
        memset(DP2,0,sizeof(DP2));
        cin>>n;
        while(n--){
            cin>>p>>w;
            for(i=w;i<40;i++){
                if(i==w || DP1[i-w]){
                    if(DP1[i-w]+p>DP2[i]){
                        DP2[i]=DP1[i-w]+p;
                    }
                }
            }
            memcpy(DP1,DP2,sizeof(DP2));
        }
        for(i=1;i<40;i++){
            DP1[i]=max(DP1[i],DP1[i-1]);
        }
        cin>>G;
        while(G--){
            cin>>p;
            out+=DP1[p];
        }
        cout<<out<<endl;
    }

    return 0;
}

