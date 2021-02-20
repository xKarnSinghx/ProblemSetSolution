/*
C - Kaprekar Number  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
For an integer 
x
 not less than 
0
, we define 
g
1
(
x
)
,
g
2
(
x
)
,
f
(
x
)
 as follows:

g
1
(
x
)
=
 the integer obtained by rearranging the digits in the decimal notation of 
x
 in descending order
g
2
(
x
)
=
 the integer obtained by rearranging the digits in the decimal notation of 
x
 in ascending order
f
(
x
)
=
g
1
(
x
)
−
g
2
(
x
)
For example, we have 
g
1
(
314
)
=
431
, 
g
2
(
3021
)
=
123
, 
f
(
271
)
=
721
−
127
=
594
. Note that the leading zeros are ignored.

Given integers 
N
,
K
, find 
a
K
 in the sequence defined by 
a
0
=
N
, 
a
i
+
1
=
f
(
a
i
)
 
(
i
≥
0
)
.

Constraints
0
≤
N
≤
10
9
0
≤
K
≤
10
5
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N
 
K

Output
Print 
a
K
.

Sample Input 1 
Copy
314 2
Sample Output 1 
Copy
693
We have:

a
0
=
314
a
1
=
f
(
314
)
=
431
−
134
=
297
a
2
=
f
(
297
)
=
972
−
279
=
693
Sample Input 2 
Copy
1000000000 100
Sample Output 2 
Copy
0
We have:

a
0
=
1000000000
a
1
=
f
(
1000000000
)
=
1000000000
−
1
=
999999999
a
2
=
f
(
999999999
)
=
999999999
−
999999999
=
0
a
3
=
f
(
0
)
=
0
−
0
=
0
⋮
Sample Input 3 
Copy
6174 100000
Sample Output 3 
Copy
6174
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

	ll n, k;
	cin >> n >> k;
	ll d = n;

	while (k--) {
		ll x = 0, c;
		c = d;
		while (c > 0) {
			ll r = c % 10;
			c = c / 10;
			x++;
		}

		ll a[x], b[x];
		foi(x) {
			a[i] = d % 10;
			b[i] = a[i];
			d = d / 10;
		}
		sort(a, a + x);
		sort(b, b + x, greater<ll>());


		ll x1 = 0, y1 = 0;

		foi(x) {
			x1 += a[i] * int(pow(10, i) + 0.5);

		}

		foi(x) {
			y1 += b[i] * int(pow(10, i) + 0.5);
		}
		d = x1 - y1;
		if (d == 0)
			break;

	}
	cout << d;
}


