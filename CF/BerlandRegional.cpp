/*
C. Berland Regional
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp is an organizer of a Berland ICPC regional event. There are n universities in Berland numbered from 1 to n. Polycarp knows all competitive programmers in the region. There are n students: the i-th student is enrolled at a university ui and has a programming skill si.

Polycarp has to decide on the rules now. In particular, the number of members in the team.

Polycarp knows that if he chooses the size of the team to be some integer k, each university will send their k strongest (with the highest programming skill s) students in the first team, the next k strongest students in the second team and so on. If there are fewer than k students left, then the team can't be formed. Note that there might be universities that send zero teams.

The strength of the region is the total skill of the members of all present teams. If there are no teams present, then the strength is 0.

Help Polycarp to find the strength of the region for each choice of k from 1 to n.

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

The first line of each testcase contains a single integer n (1≤n≤2⋅105) — the number of universities and the number of students.

The second line of each testcase contains n integers u1,u2,…,un (1≤ui≤n) — the university the i-th student is enrolled at.

The third line of each testcase contains n integers s1,s2,…,sn (1≤si≤109) — the programming skill of the i-th student.

The sum of n over all testcases doesn't exceed 2⋅105.

Output
For each testcase print n integers: the strength of the region — the total skill of the members of the present teams — for each choice of team size k.

Example
inputCopy
4
7
1 2 1 2 1 2 1
6 8 3 1 5 1 5
10
1 1 1 2 2 2 2 3 3 3
3435 3014 2241 2233 2893 2102 2286 2175 1961 2567
6
3 3 3 3 3 3
5 9 6 7 9 7
1
1
3083
outputCopy
29 28 26 19 0 0 0 
24907 20705 22805 9514 0 0 0 0 0 0 
43 43 43 32 38 43 
3083 
Note
In the first testcase the teams from each university for each k are:

k=1:
university 1: [6],[5],[5],[3];
university 2: [8],[1],[1];
k=2:
university 1: [6,5],[5,3];
university 2: [8,1];
k=3:
university 1: [6,5,5];
university 2: [8,1,1];
k=4:
university 1: [6,5,5,3];

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
void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> uni(n + 1);
	vll u(n);
	foi(n) {
		cin >> u[i];
	}
	foi(n) {
		ll x;
		cin >> x;
		uni[u[i]].pb(x);
	}
	foi(n + 1) {
		if (uni[i].size() == 0)
			continue;
		sort(uni[i].rbegin(), uni[i].rend());
		for (ll j = 1; j < uni[i].size(); j++)
			uni[i][j] += uni[i][j - 1];
	}
	vll ans(n + 1);
	foi(n + 1) {
		if (uni[i].size() == 0)
			continue;
		for (ll j = 1; j <= uni[i].size(); j++) {
			ll x = uni[i].size();
			x /= j;
			x *= j;
			ans[j] += uni[i][x - 1];
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

}
