/*
B - Sign of Friendship  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
You are now standing under a very high tower, of height 
1000
. At a position whose distance from the tower is 
D
, there is a UFO up in the sky at height 
H
 (see the figure at Sample Input / Output 1), and you want to send it a radio wave.
There are 
N
 obstacles between the tower and the UFO. The 
i
-th obstacle stands at the position 
d
i
 meters from the tower towards the UFO, and has a height of 
h
i
. You want to climb up the tower so that no obstacle crosses the line between you and the UFO. Find the minimum height you need to climb.
We assume that the ground is a flat plane, and the towers and obstacles stand vertically from the ground.
Additionally, if the top of an obstacle lies exactly on the line connecting you and the UFO, we assume that the obstacle does not cross that line.

Constraints
All values in input are integers.
1
≤
N
≤
100
1
≤
d
i
<
D
≤
1000
1
≤
h
i
<
H
≤
1000
Input
Input is given from Standard Input in the following format:

N
 
D
 
H

d
1
 
h
1

d
2
 
h
2

⋮

d
N
 
h
N

*/
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
ll TT = 1;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


	//ll t ; cin >> t;
	//while (t--)
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
void solve()
{
	ll n, d, h;
	cin >> n >> d >> h;
	vpll x;
	foi(n) {
		ll y, z;
		cin >> y >> z;
		x.pb(mp(y, z));
	}
	ld ans = 0;
	foi(n) {
		ans = max(ans, (ld)x[i].ss - ((ld)h - (ld)x[i].ss) / ((ld)d - (ld)x[i].ff) * (ld)x[i].ff);
	}
	cout << fixed << setprecision(10);
	cout << ans;

}


