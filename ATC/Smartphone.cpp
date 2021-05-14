/*
B - Smartphone Addiction  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
The battery of Takahashi's smartphone has 
N
 mAh capacity. At time 
0.5
, 
1.5
, 
2.5
, and so on (that is, at time 
n
+
0.5
 for every integer 
n
), the battery charge decreases by 
1
 mAh.
Takahashi will leave his house with his phone fully charged at time 
0
, visit a cafe 
M
 times, and return home at time 
T
.
He will stay at the 
i
-th cafe from time 
A
i
 to time 
B
i
. During this stay, he charges his phone, so the battery charge does not decrease. Instead, at time 
n
+
0.5
 for every integer 
n
, it increases by 
1
. However, if it is already equal to the battery capacity, it does not increase nor decrease.
Determine whether he can return home without the battery charge dropping to 
0
 on the way.

Constraints
1
≤
N
≤
10
9
1
≤
M
≤
1000
1
≤
T
≤
10
9
0
<
A
1
<
B
1
<
A
2
<
B
2
<
A
3
<
B
3
<
⋯
<
A
M
<
B
M
<
T
All values in input are integers.*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
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
typedef pair< ll, pll>      plll;
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
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


//	ll t ; cin >> t;
//	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;

}
void solve() {
	ll n, m, t;
	cin >> n >> m >> t;
	ll b = n, s = 0;
	foi(m) {
		ll a, c;
		cin >> a >> c;
		b -= (a - s);
		if (b <= 0) {
			cout << "No";
			return;
		}
		if (b + c - a <= n)
			b += (c - a);
		else
			b = n;
		s = c;

	}
	b -= (t - s);
	if (b > 0)
		cout << "Yes";
	else
		cout << "No";
}

