/*
D - Staircase Sequences  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points

Problem Statement
How many arithmetic progressions consisting of integers with a common difference of 
1
 have a sum of 
N
?

Constraints
1
≤
N
≤
10
12
N
 is an integer.
Input
Input is given from Standard Input in the following format:

N

Output
Print the answer.

Sample Input 1 
Copy
12
Sample Output 1 
Copy
4
We have four such progressions:

[
12
]
[
3
,
4
,
5
]
[
−
2
,
−
1
,
0
,
1
,
2
,
3
,
4
,
5
]
[
−
11
,
−
10
,
−
9
,
…
,
10
,
11
,
12
]
Sample Input 2 
Copy
1
Sample Output 2 
Copy
2
We have two such progressions:

[
1
]
[
0
,
1
]
Sample Input 3 
Copy
963761198400
Sample Output 3 
Copy
1920
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

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()

{

	ll n;
	cin >> n;
	while (n % 2 == 0)
		n /= 2;
	ll r = sqrt(n), ans = 0;
	for (ll i = 1; i <= r; i++)
		if (n % i == 0)
			ans += 2;
	if (r * r == n)
		ans--;
	cout << ans * 2 ;

}
