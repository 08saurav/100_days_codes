#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    priority_queue<long long int,vector<long long int>,greater<long long int>>q;
	    for(int i=0;i<n;i++)
	    {
	        int temp;
	        cin >> temp;
	        q.push(temp);
	    }
	    if(n==1){
	        cout << q.top() << endl;
	        continue;
	    }
	    long long int sum=0;
	    while(1)
	    {
	        long long int a=q.top();
	        q.pop();
	        long long int b=q.top();
	        q.pop();
	        sum+=a+b;
	        if(q.empty()){
	           // cout << a+b << endl;
	            break;
	        }
	        q.push(a+b);
	    }
	    cout << sum << endl;
	}
	return 0;
}
