/*
	UVA 10340 Solution Written By DemoVersion in 20140907.
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
	string s,t;
	int i,j;
	while(cin>>s>>t){
		i=0;
		for(j=0;j<t.length();j++){
			if(t[j]==s[i]){
				i++;
				if(i==s.length())break;
			}
		}
		if(i==s.length()){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
    return 0;
}

