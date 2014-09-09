/*
	UVA 12086 Solution Written By DemoVersion in 20140907.
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define Author "DemoVersion"

const int MaxN = 200000+10;
const int MaxST = 4 * MaxN;

void build(int arL,int arR,int SI,int st[],int ar[]){
	if(arL==arR){
		st[SI]=ar[arL];
		return;
	}
	int m=(arL+arR)/2;
	build(arL,m,SI*2,st,ar);
    build(m+1,arR,SI*2+1,st,ar);
	st[SI]=st[SI*2]+st[SI*2+1];
}
void update(int arL,int arR,int i,int oldval,int newval,int SI,int st[]){
	if(i<arL||arR<i)return;
	st[SI]=st[SI]-oldval+newval;
	if(arL==arR)return;
	int m=(arL+arR)/2;
	update(arL,m,i,oldval,newval,SI*2,st);
    update(m+1,arR,i,oldval,newval,SI*2+1,st);

}
int getVal(int arL,int arR,int L,int R,int SI,int st[]){
    if(arR<L||arL>R)return 0;
    if(L<=arL&&arR<=R){
        return st[SI];
    }
    int m=(arL+arR)/2;
    if(arL==arR)return 0;
    return getVal(arL,m,L,R,SI*2,st)+getVal(m+1,arR,L,R,SI*2+1,st);
}

int main(){
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
    #endif
	string s;
	int Ar[MaxN],st[MaxST],n,i,u,v,t=0;
	while(cin>>n&&n){
		if(t++)cout<<endl;
		cout<<"Case "<<t<<":"<<endl;
		for(i=0;i<n;i++)
			cin>>Ar[i];
		build(0,n-1,1,st,Ar);
		while(cin>>s&&s!="END"){
			if(s=="S"){
				cin>>u>>v;
				update(0,n-1,u-1,Ar[u-1],v,1,st);
				Ar[u-1]=v;
			}else{
				cin>>u>>v;
				cout<<getVal(0,n-1,u-1,v-1,1,st)<<endl;
			}
		}
	}
    return 0;
}
