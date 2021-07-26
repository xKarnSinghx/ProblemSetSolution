/*
B. Running for Gold
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Olympic Games have just started and Federico is eager to watch the marathon race.

There will be n athletes, numbered from 1 to n, competing in the marathon, and all of them have taken part in 5 important marathons, numbered from 1 to 5, in the past. For each 1≤i≤n and 1≤j≤5, Federico remembers that athlete i ranked ri,j-th in marathon j (e.g., r2,4=3 means that athlete 2 was third in marathon 4).

Federico considers athlete x superior to athlete y if athlete x ranked better than athlete y in at least 3 past marathons, i.e., rx,j<ry,j for at least 3 distinct values of j.

Federico believes that an athlete is likely to get the gold medal at the Olympics if he is superior to all other athletes.

Find any athlete who is likely to get the gold medal (that is, an athlete who is superior to all other athletes), or determine that there is no such athlete.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤50000) — the number of athletes.

Then n lines follow, each describing the ranking positions of one athlete.

The i-th of these lines contains the 5 integers ri,1,ri,2,ri,3,ri,4,ri,5 (1≤ri,j≤50000) — the ranking positions of athlete i in the past 5 marathons. It is guaranteed that, in each of the 5 past marathons, the n athletes have distinct ranking positions, i.e., for each 1≤j≤5, the n values r1,j,r2,j,…,rn,j are distinct.

It is guaranteed that the sum of n over all test cases does not exceed 50000.

Output
For each test case, print a single integer — the number of an athlete who is likely to get the gold medal (that is, an athlete who is superior to all other athletes). If there are no such athletes, print −1. If there is more than such one athlete, print any of them.

Example
inputCopy
4
1
50000 1 50000 50000 50000
3
10 10 20 30 30
20 20 30 10 10
30 30 10 20 20
3
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
6
9 5 3 7 1
7 4 1 6 8
5 6 7 3 2
6 7 8 8 6
4 2 2 4 5
8 3 6 9 4
outputCopy
1
-1
1
5
Note
Explanation of the first test case: There is only one athlete, therefore he is superior to everyone else (since there is no one else), and thus he is likely to get the gold medal.

Explanation of the second test case: There are n=3 athletes.

Athlete 1 is superior to athlete 2. Indeed athlete 1 ranks better than athlete 2 in the marathons 1, 2 and 3.
Athlete 2 is superior to athlete 3. Indeed athlete 2 ranks better than athlete 3 in the marathons 1, 2, 4 and 5.
Athlete 3 is superior to athlete 1. Indeed athlete 3 ranks better than athlete 1 in the marathons 3, 4 and 5.
Explanation of the third test case: There are n=3 athletes.

Athlete 1 is superior to athletes 2 and 3. Since he is superior to all other athletes, he is likely to get the gold medal.
Athlete 2 is superior to athlete 3.
Athlete 3 is not superior to any other athlete.
Explanation of the fourth test case: There are n=6 athletes.

Athlete 1 is superior to athletes 3, 4, 6.
Athlete 2 is superior to athletes 1, 4, 6.
Athlete 3 is superior to athletes 2, 4, 6.
Athlete 4 is not superior to any other athlete.
Athlete 5 is superior to athletes 1, 2, 3, 4, 6. Since he is superior to all other athletes, he is likely to get the gold medal.
Athlete 6 is only superior to athlete 4.

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
#define graph          vector<vector<ll>>
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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}

void solve() {
	ll n;
	cin >> n;
	graph g(n + 1, vll(6));
	foi(n) {
		foj(5) {
			ll x;
			cin >> x;
			g[i + 1][j + 1] = x;

		}
	}
	if (n == 1) {
		cout << 1;
		return;
	}
	ll idx = 0, s = 0, s1 = 0;
	foi(6) {
		if (i == 0)
			continue;
		if (g[1][i] <= g[2][i])
			s++;
		else
			s1++;
	}
	if (s >= s1)
		idx = 1;
	else
		idx = 2;
	foi(n + 1) {
		if (i < 3)
			continue;
		ll s2 = 0, s3 = 0;
		foj(6) {
			if (j == 0)
				continue;
			if (g[i][j] <= g[idx][j])
				s2++;
			else
				s3++;
		}
		if (s2 >= s3)
			idx = i;
	}
	foi(n + 1) {
		if (i == 0)
			continue;
		if (i == idx)
			continue;
		ll s4 = 0, s5 = 0;
		foj(6) {
			if (j == 0)
				continue;
			if (g[i][j] <= g[idx][j])
				s4++;
			else
				s5++;
		}
		if (s4 > s5) {
			cout << -1;
			return;
		}
	}
	cout << idx;
}


