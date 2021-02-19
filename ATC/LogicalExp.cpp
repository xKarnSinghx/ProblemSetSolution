/*
D - Logical Expression  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400
 points

Problem Statement
Given are 
N
 strings 
S
1
,
…
,
S
N
, each of which is AND or OR.

Find the number of tuples of 
N
+
1
 variables 
(
x
0
,
…
,
x
N
)
, where each element is 
True
 or 
False
, such that the following computation results in 
y
N
 being 
True
:

y
0
=
x
0
;
for 
i
≥
1
, 
y
i
=
y
i
−
1
∧
x
i
 if 
S
i
 is AND, and 
y
i
=
y
i
−
1
∨
x
i
 if 
S
i
 is OR.
Here, 
a
∧
b
 and 
a
∨
b
 are logical operators.

Constraints
1
≤
N
≤
60
S
i
 is AND or OR.
Input
Input is given from Standard Input in the following format:

N

S
1

⋮

S
N

Output
Print the answer.

Sample Input 1 
Copy
2
AND
OR
Sample Output 1 
Copy
5
For example, if 
(
x
0
,
x
1
,
x
2
)
=
(
True
,
False
,
True
)
, we have 
y
2
=
True
, as follows:

y
0
=
x
0
=
True
y
1
=
y
0
∧
x
1
=
True
∧
False
=
False
y
2
=
y
1
∨
x
2
=
False
∨
True
=
True
All of the five tuples 
(
x
0
,
x
1
,
x
2
)
 resulting in 
y
2
=
True
 are shown below:

(
True
,
True
,
True
)
(
True
,
True
,
False
)
(
True
,
False
,
True
)
(
False
,
True
,
True
)
(
False
,
False
,
True
)
Sample Input 2 
Copy
5
OR
OR
OR
OR
OR
Sample Output 2 
Copy
63
All tuples except the one filled entirely with 
False
 result in 
y
5
=
True
.*/
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

	ll ans = 1;

	foi(n) {
		string s;
		cin >> s;
		if (s == "AND") {

		}
		else
			ans += 1ll << (i + 1);
	}
	cout << ans;

}




