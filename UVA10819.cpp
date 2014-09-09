/*
	UVA 10819 Solution Written By DemoVersion in 20140907.
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
    int DP1[10300],DP2[10300];
    int mymax,i,j,n,cash,t,T,c,f;
	while(cin>>cash>>n){
        memset(DP1,0,sizeof(DP1));
        memset(DP2,0,sizeof(DP2));

		for(j=0;j<n;j++){
            cin>>c>>f;
		    for(i=c;i<10300;i++){
                if(i==c || DP1[i-c]){
                    if(DP1[i-c]+f>DP2[i]){
                        DP2[i]=DP1[i-c]+f;
                    }
                }
            }
            memcpy(DP1,DP2,sizeof(DP2));
        }

        mymax=0;
        for(i=0;i<=cash;i++){
            if(DP1[i]>mymax){
                mymax=DP1[i];
            }
        }
		for(i=2001;i<=cash+200;i++){
            if(DP1[i]>mymax){
                mymax=DP1[i];
            }
        }

        cout<<mymax<<endl;
    }

    return 0;
}

