/*
	UVA 12697 Solution Written By DemoVersion in 20140904.
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
const int mN=500100;
int good_luck_random(){
    int ret=rand();
	ret^=rand()<<8;
	ret^=rand()<<16;
    return ret;
}
ll A[mN],X;
int n;
bool check(int M){
	int i,lastIn=0;
	ll UlSum=0;
	for(i=0;i<n;i++){
		if(i>M){
			if(A[lastIn]<0){
				UlSum-=A[lastIn];
				lastIn++;
			}
		}
		if(UlSum<0){
			lastIn=i;
			UlSum=0;
		}
		if(i-lastIn>=M){
			UlSum-=A[i-M];
			lastIn++;
		}
		if(UlSum<0){
			lastIn=i;
			UlSum=0;
		}
		UlSum+=A[i];
		if(UlSum>=X){
			return 1;
		}
	}
	return 0;
}
int main(){

    ios_base::sync_with_stdio(0);
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out2.txt","w",stdout);

	#endif

	ll UlSum=0,val;

	int c,T,lastIn,i,minm,L,R,M,found,rM;
	cin>>T;

	while(T--){
        cin>>n>>X;
		minm=1<<28;
		UlSum=0;
		found=0;
		for(i=0;i<n;i++){
			if(UlSum<0)UlSum=0;
			cin>>A[i];
			UlSum+=A[i];
			if(UlSum>=X){
				found=1;
			}
		}
		if(found==0){
			cout<<-1<<endl;
			continue;
		}
		R=n;
		L=1;
		while(L<R){
			M=(L+R)/2;
			rM=(L+R)/2;
			lastIn=0;
			UlSum=0;
			found=0;
			found=check(M);
			for(i=0;i<25;i++){
				if(found)break;
				c=(R-L)/2+(R-L)%2;

				M=rM-good_luck_random()%c;
				found=check(M);
			}
			if(found){
				R=M;
			}else{
				L=M+1;
			}
		}

		cout<<R<<endl;

	}
    return 0;
}