/*
C. Multi-judge Solving
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Makes solves problems on Decoforces and lots of other different online judges. Each problem is denoted by its difficulty — a positive integer number. Difficulties are measured the same across all the judges (the problem with difficulty d on Decoforces is as hard as the problem with difficulty d on any other judge).

Makes has chosen n problems to solve on Decoforces with difficulties a1, a2, ..., an. He can solve these problems in arbitrary order. Though he can solve problem i with difficulty ai only if he had already solved some problem with difficulty  (no matter on what online judge was it).

Before starting this chosen list of problems, Makes has already solved problems with maximum difficulty k.

With given conditions it's easy to see that Makes sometimes can't solve all the chosen problems, no matter what order he chooses. So he wants to solve some problems on other judges to finish solving problems from his list.

For every positive integer y there exist some problem with difficulty y on at least one judge besides Decoforces.

Makes can solve problems on any judge at any time, it isn't necessary to do problems from the chosen list one right after another.

Makes doesn't have too much free time, so he asked you to calculate the minimum number of problems he should solve on other judges in order to solve all the chosen problems from Decoforces.

Input
The first line contains two integer numbers n, k (1 ≤ n ≤ 103, 1 ≤ k ≤ 109).

The second line contains n space-separated integer numbers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print minimum number of problems Makes should solve on other judges in order to solve all chosen problems on Decoforces.

Examples
inputCopy
3 3
2 1 9
outputCopy
1
inputCopy
4 20
10 3 6 3
outputCopy
0
Note
In the first example Makes at first solves problems 1 and 2. Then in order to solve the problem with difficulty 9, he should solve problem with difficulty no less than 5. The only available are difficulties 5 and 6 on some other judge. Solving any of these will give Makes opportunity to solve problem 3.

In the second example he can solve every problem right from the start.


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


	
		solve();
	

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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n], s = 0;
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	foi(n) {
		while (k * 2 < a[i]) {
			s++;
			k *= 2;
		}
		k = max(k, a[i]);
	}
	cout << s;


}


