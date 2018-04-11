#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int grundy (int n,int *g,int m){
	if(n>0){
		if(g[n]==-1){
			int t[MAX]={0};
			for(int i=1;i<=m;i++){
				t[grundy(n-i,g,m)]=1;
			}
			for(int i=0;i<n+1;i++){
				if(t[i]==0){
					g[n]=i;
					break;
				}			
			}
		}
	}
	else if(n<=0){
		return 0; 
	}
	return g[n];
}

int main(){
	int n,m;
	// number of coins in the pile 
	//and maximum number of coins that can be removed in one move.
	cin>>n>>m;
	int g[n+1];
	for(int i=0;i<=n;i++){
		g[i]=-1;
	}
	int ans=grundy(n,g,m);
	cout<<"Grundy number of "<<n<<" is "<<ans<<"\n";
	if(ans>0){//If grundy number greater than zero then player one wins
		cout<<"Player one will win when both the players play optimally.";
	}
	else{
		cout<<"Player two will win when both the players play optimally.";
	}
	return 0;
} 