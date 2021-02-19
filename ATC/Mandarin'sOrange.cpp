/*
C - Mandarin Orange  / 
Time Limit: 1.5 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
There are 
N
 dishes arranged in a row in front of Takahashi. The 
i
-th dish from the left has 
A
i
 oranges on it.

Takahashi will choose a triple of integers 
(
l
,
r
,
x
)
 satisfying all of the following conditions:

1
≤
l
≤
r
≤
N
;
1
≤
x
;
for every integer 
i
 between 
l
 and 
r
 (inclusive), 
x
≤
A
i
.
He will then pick up and eat 
x
 oranges from each of the 
l
-th through 
r
-th dishes from the left.

At most how many oranges can he eat by choosing the triple 
(
l
,
r
,
x
)
 to maximize this number?

Constraints
All values in input are integers.
1
≤
N
≤
10
4
1
≤
A
i
≤
10
5
Input
Input is given from Standard Input in the following format:

N

A
1
 
…
 
A
N

Output
Print the maximum number of oranges Takahashi can eat.

Sample Input 1 
Copy
6
2 4 4 9 4 9
Sample Output 1 
Copy
20
By choosing 
(
l
,
r
,
x
)
=
(
2
,
6
,
4
)
, he can eat 
20
 oranges.

Sample Input 2 
Copy
6
200 4 4 9 4 9
Sample Output 2 
Copy
200
By choosing 
(
l
,
r
,
x
)
=
(
1
,
1
,
200
)
, he can eat 
200
 oranges.*/
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
	ll n;
	cin >> n;
	ll a[n];
	ll ans = 0;

	for (ll i = 0; i < n; i++)
		cin >> a[i];

	for (ll i = 0; i < n; i++) {
		ll p = a[i];
		for (ll j = i; j < n; j++) {
			p = min(p, a[j]);
			ans = max(ans, (j - i + 1) * p);

		}
	}
	cout << ans ;


}



