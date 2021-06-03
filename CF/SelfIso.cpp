/*
B. Maria Breaks the Self-isolation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Maria is the most active old lady in her house. She was tired of sitting at home. She decided to organize a ceremony against the coronavirus.

She has n friends who are also grannies (Maria is not included in this number). The i-th granny is ready to attend the ceremony, provided that at the time of her appearance in the courtyard there will be at least ai other grannies there. Note that grannies can come into the courtyard at the same time. Formally, the granny i agrees to come if the number of other grannies who came earlier or at the same time with her is greater than or equal to ai.

Grannies gather in the courtyard like that.

Initially, only Maria is in the courtyard (that is, the initial number of grannies in the courtyard is 1). All the remaining n grannies are still sitting at home.
On each step Maria selects a subset of grannies, none of whom have yet to enter the courtyard. She promises each of them that at the time of her appearance there will be at least ai other grannies (including Maria) in the courtyard. Maria can call several grannies at once. In this case, the selected grannies will go out into the courtyard at the same moment of time.
She cannot deceive grannies, that is, the situation when the i-th granny in the moment of appearing in the courtyard, finds that now there are strictly less than ai other grannies (except herself, but including Maria), is prohibited. Please note that if several grannies appeared in the yard at the same time, then each of them sees others at the time of appearance.
Your task is to find what maximum number of grannies (including herself) Maria can collect in the courtyard for the ceremony. After all, the more people in one place during quarantine, the more effective the ceremony!

Consider an example: if n=6 and a=[1,5,4,5,1,9], then:

at the first step Maria can call grannies with numbers 1 and 5, each of them will see two grannies at the moment of going out into the yard (note that a1=1≤2 and a5=1≤2);
at the second step, Maria can call grannies with numbers 2, 3 and 4, each of them will see five grannies at the moment of going out into the yard (note that a2=5≤5, a3=4≤5 and a4=5≤5);
the 6-th granny cannot be called into the yard  — therefore, the answer is 6 (Maria herself and another 5 grannies).
Input
The first line contains a single integer t (1≤t≤104) — the number of test cases in the input. Then test cases follow.

The first line of a test case contains a single integer n (1≤n≤105) — the number of grannies (Maria is not included in this number).

The second line contains n integers a1,a2,…,an (1≤ai≤2⋅105).

It is guaranteed that the sum of the values n over all test cases of the input does not exceed 105.

Output
For each test case, print a single integer k (1≤k≤n+1) — the maximum possible number of grannies in the courtyard.

Example
inputCopy
4
5
1 1 2 2 1
6
2 3 4 5 6 7
6
1 5 4 5 1 9
5
1 2 3 5 6
outputCopy
6
1
6
4
Note
In the first test case in the example, on the first step Maria can call all the grannies. Then each of them will see five grannies when they come out. Therefore, Maria and five other grannies will be in the yard.

In the second test case in the example, no one can be in the yard, so Maria will remain there alone.

The third test case in the example is described in the details above.

In the fourth test case in the example, on the first step Maria can call grannies with numbers 1, 2 and 3. If on the second step Maria calls 4 or 5 (one of them), then when a granny appears in the yard, she will see only four grannies (but it is forbidden). It means that Maria can't call the 4-th granny or the 5-th granny separately (one of them). If she calls both: 4 and 5, then when they appear, they will see 4+1=5 grannies. Despite the fact that it is enough for the 4-th granny, the 5-th granny is not satisfied. So, Maria cannot call both the 4-th granny and the 5-th granny at the same time. That is, Maria and three grannies from the first step will be in the yard in total.


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
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
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
	vll a(n);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll ans = 0, cnt = 0;
	sort(all(a));
	foi(n) {
		cnt++;
		if (cnt >= a[i]) {
			ans = cnt + 1;
		}
	}
	if (ans == 0)
		cout << 1;
	else
		cout << ans;

}
