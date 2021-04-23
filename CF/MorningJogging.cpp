/*
B. Morning Jogging
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The 2050 volunteers are organizing the "Run! Chase the Rising Sun" activity. Starting on Apr 25 at 7:30 am, runners will complete the 6km trail around the Yunqi town.

There are n+1 checkpoints on the trail. They are numbered by 0, 1, ..., n. A runner must start at checkpoint 0 and finish at checkpoint n. No checkpoint is skippable — he must run from checkpoint 0 to checkpoint 1, then from checkpoint 1 to checkpoint 2 and so on. Look at the picture in notes section for clarification.

Between any two adjacent checkpoints, there are m different paths to choose. For any 1≤i≤n, to run from checkpoint i−1 to checkpoint i, a runner can choose exactly one from the m possible paths. The length of the j-th path between checkpoint i−1 and i is bi,j for any 1≤j≤m and 1≤i≤n.

To test the trail, we have m runners. Each runner must run from the checkpoint 0 to the checkpoint n once, visiting all the checkpoints. Every path between every pair of adjacent checkpoints needs to be ran by exactly one runner. If a runner chooses the path of length li between checkpoint i−1 and i (1≤i≤n), his tiredness is
mini=1nli,
i. e. the minimum length of the paths he takes.

Please arrange the paths of the m runners to minimize the sum of tiredness of them.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10000). Description of the test cases follows.

The first line of each test case contains two integers n and m (1≤n,m≤100).

The i-th of the next n lines contains m integers bi,1, bi,2, ..., bi,m (1≤bi,j≤109).

It is guaranteed that the sum of n⋅m over all test cases does not exceed 104.

Output
For each test case, output n lines. The j-th number in the i-th line should contain the length of the path that runner j chooses to run from checkpoint i−1 to checkpoint i. There should be exactly m integers in the i-th line and these integers should form a permuatation of bi,1, ..., bi,m for all 1≤i≤n.

If there are multiple answers, print any.

Example
inputCopy
2
2 3
2 3 4
1 3 5
3 2
2 3
4 1
3 5
outputCopy
2 3 4
5 3 1
2 3
4 1
3 5
Note
In the first case, the sum of tiredness is min(2,5)+min(3,3)+min(4,1)=6.


In the second case, the sum of tiredness is min(2,4,3)+min(3,1,5)=3.
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
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


	ll t ; cin >> t;
	while (t--)
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
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	foi(n) {
		foj(m)
		cin >> a[i][j];
	}
	vplll b;
	foi(n) {
		foj(m)
		b.pb(mp(a[i][j], mp (i, j))) ;
	}
	sort(b.begin(), b.end());
	ll ans[n][m] = {}, k = 0;

	foi(m) {
		ans[b[i].ss.ff][k] = b[i].ff;
		k++;
	}
	k = 0;
	foi(n) {
		ll z[101] = {}, k = 0;
		foj(m) {
			if (ans[i][j] != 0)
				z[k] = ans[i][j], k++;
		}
		ll y[101] = {};
		k = 0;
		foj(m) {
			y[k] = a[i][j], k++;
		}
		sort(y, y + k);
		ll xy[101];
		k = 0;
		ll mx = 0, f = 0;
		foj(m) {
			if (z[k] == y[j] )
				k++;
			else
				xy[mx] = y[j], mx++;

		}
		k = 0;
		foj(m) {
			if (ans[i][j] == 0)
				ans[i][j] = xy[k], k++;
		}


	}
	foi(n) {
		foj(m)
		cout << ans[i][j] << " ";
		cout << "\n";
	}



}


