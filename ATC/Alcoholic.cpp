/*
B - Alcoholic  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
Takahashi had 
N
 glasses of liquor.

The amount and alcohol percentage of the 
i
-th liquor were 
V
i
 milliliters and 
P
i
 percent by volume, respectively.

Takahashi gets drunk when his alcohol intake exceeds 
X
 milliliters.

Which of the 
N
 liquors was he drinking when he gets drunk? If he was not drunk even after drinking all the liquors, print -1 instead.

Constraints
All values in input are integers.
1
≤
N
≤
10
3
0
≤
X
≤
10
6
1
≤
V
i
≤
10
3
0
≤
P
i
≤
100
Input
Input is given from Standard Input in the following format:

N
 
X

V
1
 
P
1

⋮

V
N
 
P
N

Output
If Takahashi got drunk when drinking the 
i
-th liquor, print 
i
. If he was not drunk even after drinking all the liquors, print -1 instead.

Sample Input 1 
Copy
2 15
200 5
350 3
Sample Output 1 
Copy
2
The 
1
-st liquor contains 
200
×
5
100
=
10
 milliliters of alcohol.

The 
2
-nd liquor contains 
350
×
3
100
=
10.5
 milliliters of alcohol.

His alcohol intake exceeds 
15
 milliliters for the first time when drinking the 
2
-nd liquor.

Sample Input 2 
Copy
2 10
200 5
350 3
Sample Output 2 
Copy
2
When his alcohol intake is exactly 
X
 milliliters, he is still not drunk.

Sample Input 3 
Copy
3 1000000
1000 100
1000 100
1000 100
Sample Output 3 
Copy
-1
He seems to be immune to alcohol.
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
typedef pair<int, pii>      piii;
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
ll n, x;
	cin >> n >> x;
	vpll xx(n);
	foi(n)
	{
		cin >> xx[i].ff >> xx[i].ss;
	}
	ll cnt = 0, s = 0, f = 0;
	foi(n) {
		s += xx[i].ff * xx[i].ss;
		cnt++;
		if (s > x * 100) {
			f = 1;
			break;
		}
	}
	if (f == 1)
		cout << cnt;
	else


}
