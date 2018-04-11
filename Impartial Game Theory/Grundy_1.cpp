#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int mex(int a,int b,int c,int n){
	int t[MAX]={0};
	t[a]=1;t[b]=1;t[c]=1;
	for(int i=0;i<n+1;i++){
		if(t[i]==0){
			a=i;
			break;
		}
	}
	return a;
}

int grundy (int n,int *g){
	if(n>0){
		if(g[n]==-1){
			g[n]=mex(grundy(n-1,g),grundy(n-2,g),grundy(n-3,g),n);
		}
	}
	else if(n<=0){
		return 0; 
	}
	return g[n];
}

int main(){
	int n;
	// number of coins in the pile.
	cin>>n;
	int g[n+1];
	for(int i=0;i<=n;i++){
		g[i]=-1;
	}
	int ans=grundy(n,g);
	cout<<"Grundy number of "<<n<<" is "<<ans<<"\n";
	if(ans>0){//If grundy number greater than zero then player one wins
		cout<<"Player one will win when both the players play optimally.";
	}
	else{
		cout<<"Player two will win when both the players play optimally.";
	}
	return 0;
} 