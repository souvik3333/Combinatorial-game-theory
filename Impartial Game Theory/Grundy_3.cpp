#include <bits/stdc++.h>
using namespace std;

int grundy (int n,int m){
	return n%(m+1);
}

int main(){
	int n,m;
	// number of coins in the pile 
	//and maximum number of coins that can be removed in one move.
	cin>>n>>m;
	int ans=grundy(n,m);
	cout<<"Grundy number of "<<n<<" is "<<ans<<"\n";
	if(ans>0){//If grundy number greater than zero then player one wins
		cout<<"Player one will win when both the players play optimally.";
	}
	else{
		cout<<"Player two will win when both the players play optimally.";
	}
	return 0;
} 