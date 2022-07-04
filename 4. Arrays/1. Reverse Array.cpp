//Reference: https://practice.geeksforgeeks.org/problems/reverse-an-array/0#

#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> v){
    int n=v.size();
    for(int i=0; i<n/2; i++){
        swap(v[i], v[n-i-1]);
    }
    return v;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }
	    
	    vector<int> v=reverse(a);
	    for(int i=0; i<n; i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}