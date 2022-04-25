#include<bits/stdc++.h>
using namespace std;

int main(){
		int n=8;
        int res=0;
        while(n>0){
            n=(n&(n-1));
            res++;
        }
        cout<<res;
        return 0;
}
/*Logic:: Ex: 40
		101000	(n = 40)
	 	100111	(n-1 = 39)
	______________________
	&	100000	(n = 32)
	
		100000	(n = 32)
		011111	(n = 31)
	______________________
	&	000000

total iterations:	2
total set bits: 	2
Time Complexity = O(no. of set bits) 	

*/
