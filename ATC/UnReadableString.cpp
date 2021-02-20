/*
B - uNrEaDaBlE sTrInG  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
We call a string hard-to-read when its odd-positioned (
1
-st, 
3
-rd, 
5
-th, ... from the beginning) characters are all lowercase English letters and its even-positioned characters (
2
-nd, 
4
-th, 
6
-th, ... from the beginning) are all uppercase English letters.

Determine whether a string 
S
 is hard-to-read.

Constraints
S
 consists of uppercase and lowercase English letters.
The length of 
S
 is between 
1
 and 
1000
 (inclusive).
Input
Input is given from Standard Input in the following format:

S

Output
If 
S
 is hard-to-read, print Yes; otherwise, print No.

Sample Input 1 
Copy
dIfFiCuLt
Sample Output 1 
Copy
Yes
The odd-positioned characters are all lowercase and the even-positioned characters are all uppercase, so it is hard-to-read.

Sample Input 2 
Copy
eASY
Sample Output 2 
Copy
No
The 
3
-rd character is not lowercase, so it is not hard-to-read.

Sample Input 3 
Copy
a
Sample Output 3 
Copy
Yes
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


		solve();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{

	string s;
	cin >> s;
	ll c = 0;
	foi(s.size()) {
		if (i % 2 == 0 && s[i] >= 'a' && s[i] <= 'z') {
			c++;
		}
		else	if (i % 2 == 1 && s[i] >= 'A' && s[i] <= 'Z')
		{c++;}
		

	}
	if (c != s.size())
		cout << "No";
	else
		cout << "Yes";
}


