/*
B. Fridge Lockers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Hanh lives in a shared apartment. There are n people (including Hanh) living there, each has a private fridge.

n fridges are secured by several steel chains. Each steel chain connects two different fridges and is protected by a digital lock. The owner of a fridge knows passcodes of all chains connected to it. A fridge can be open only if all chains connected to it are unlocked. For example, if a fridge has no chains connected to it at all, then any of n people can open it.

For exampe, in the picture there are n=4 people and 5 chains. The first person knows passcodes of two chains: 1−4 and 1−2. The fridge 1 can be open by its owner (the person 1), also two people 2 and 4 (acting together) can open it.
The weights of these fridges are a1,a2,…,an. To make a steel chain connecting fridges u and v, you have to pay au+av dollars. Note that the landlord allows you to create multiple chains connecting the same pair of fridges.

Hanh's apartment landlord asks you to create exactly m steel chains so that all fridges are private. A fridge is private if and only if, among n people living in the apartment, only the owner can open it (i.e. no other person acting alone can do it). In other words, the fridge i is not private if there exists the person j (i≠j) that the person j can open the fridge i.

For example, in the picture all the fridges are private. On the other hand, if there are n=2 fridges and only one chain (which connects them) then both fridges are not private (both fridges can be open not only by its owner but also by another person).

Of course, the landlord wants to minimize the total cost of all steel chains to fulfill his request. Determine whether there exists any way to make exactly m chains, and if yes, output any solution that minimizes the total cost.

Input
Each test contains multiple test cases. The first line contains the number of test cases T (1≤T≤10). Then the descriptions of the test cases follow.

The first line of each test case contains two integers n, m (2≤n≤1000, 1≤m≤n) — the number of people living in Hanh's apartment and the number of steel chains that the landlord requires, respectively.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤104) — weights of all fridges.

Output
For each test case:

If there is no solution, print a single integer −1.
Otherwise, print a single integer c — the minimum total cost. The i-th of the next m lines contains two integers ui and vi (1≤ui,vi≤n, ui≠vi), meaning that the i-th steel chain connects fridges ui and vi. An arbitrary number of chains can be between a pair of fridges.
If there are multiple answers, print any.

Example
inputCopy
3
4 4
1 1 1 1
3 1
1 2 3
3 3
1 2 3
outputCopy
8
1 2
4 3
3 2
4 1
-1
12
3 2
1 2
3 1

*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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
#define MOD  1000000007;
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
		//cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

void solve()
{

	ll n, m;
	cin >> n >> m;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll s = 0;
	foi(n)
	s += a[i];
	if (n == 2 || m < n)
		cout << -1 << endl;
	else {
		cout << 2 * s << endl;
		foi(n)
		cout << i + 1 << " " << (i + 1) % n + 1 << endl;
	}
}



