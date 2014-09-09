/*
	UVA 12696 Solution Written By DemoVersion in 20140903.
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
    double A[10],B;
    int S=0;
    cin>>T;
    while(T--){
        cin>>A[0]>>A[1]>>A[2]>>B;
        sort(A,A+3);
        if(B>7){
            cout<<'0'<<endl;
            continue;
        }
        if(A[0]<=25&&A[1]<=45&&A[2]<=56){
            cout<<'1'<<endl;
            S++;
            continue;
        }
        if(A[0]+A[1]+A[2]<=125){
            cout<<'1'<<endl;
            S++;
            continue;
        }
        cout<<'0'<<endl;
    }
    cout<<S<<endl;
    return 0;
}