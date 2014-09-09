/*
	UVA 10664 Solution Written By DemoVersion in 20140906.
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
    bool DP1[205],DP2[205];
    int i,sum,t,T;
    string line;
    cin>>T;
    getline(cin,line);
    stringstream ss;
    while(T--){
        getline(cin,line);
        ss.clear();
        sum=0;
        ss.str(line);
        memset(DP1,0,sizeof(DP1));
        memset(DP2,0,sizeof(DP2));
        while(ss>>t){
            sum+=t;
            for(i=t;i<205;i++){
                if(i==t || DP1[i-t]){
                    DP2[i]=1;
                }
            }
            memcpy(DP1,DP2,sizeof(DP2));
        }
        if(sum%2==0 && DP1[sum/2]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}

