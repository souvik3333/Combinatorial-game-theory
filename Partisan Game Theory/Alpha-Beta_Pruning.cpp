// **The Nodes are numbered from 0 to n
// **The Edges should be of the format 'parent'+' '+'child' and in ascending order 
// **The Nodes except the leaf nodes should be assigned a value of -1
/* 
Sample Input:
	10 9 //number of nodes and edges
	0 1  //Edge
	0 2  // "
	1 3  // "
	1 4  // "
	1 5  // "
	3 6  // "
	3 7  // "
	4 8  // "
	4 9  // "
	-1 -1 1 -1 -1 3 2 6 10 5  //Node Values  
*/
#include <bits/stdc++.h>
using namespace std;
#define Max 1000
struct Node{
	int value;
	int next[Max];
};

typedef struct Node node;

int minimax(int a[], node b[],int n,int e, bool isMax,int i,int alpha,int beta)
{
    if(b[i].value != -1)
        return b[i].value;
    if(isMax){
    	int ans=-1*Max;
    	for(int j=0;j<a[i];j++){
    		ans=max(ans,minimax(a,b,n,e,0,b[i].next[j],alpha,beta));
            alpha = max(alpha,ans);
            if (beta <= alpha)
                break;
    	}
       	return ans;
    }
    else{
        int ans=Max;
    	for(int j=0;j<a[i];j++){
    		ans=min(ans,minimax(a,b,n,e,1,b[i].next[j],alpha,beta));
    		beta = min(beta, ans);
            if (beta <= alpha)
                break;
    	}
       	return ans;
    }   	
}

int main(){
	int n,e;
	cout<<"Enter the Number Of Nodes and Edges:\n";
	cin>>n>>e;
	cout<<"Enter the Edges:\n";
	int a[n]={0};
	node b[n];
	int edge[e][2];
	for(int i=0;i<e;i++){
		cin>>edge[i][0]>>edge[i][1];
		a[edge[i][0]]++;
	}
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			b[edge[k][0]].next[j]=edge[k][1];
			k++;
		}
	}
	cout<<"Enter Node Values:\n";
	for(int i=0;i<n;i++){
		cin>>b[i].value;
	}
	int alpha=-1*Max;
	int beta=Max;
	int ans=minimax(a,b,n,e,1,0,alpha,beta);
	cout<<ans;
	return 0;
}