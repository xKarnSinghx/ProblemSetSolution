/*
C. Dominant Piranha
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n piranhas with sizes a1,a2,…,an in the aquarium. Piranhas are numbered from left to right in order they live in the aquarium.

Scientists of the Berland State University want to find if there is dominant piranha in the aquarium. The piranha is called dominant if it can eat all the other piranhas in the aquarium (except itself, of course). Other piranhas will do nothing while the dominant piranha will eat them.

Because the aquarium is pretty narrow and long, the piranha can eat only one of the adjacent piranhas during one move. Piranha can do as many moves as it needs (or as it can). More precisely:

The piranha i can eat the piranha i−1 if the piranha i−1 exists and ai−1<ai.
The piranha i can eat the piranha i+1 if the piranha i+1 exists and ai+1<ai.
When the piranha i eats some piranha, its size increases by one (ai becomes ai+1).

Your task is to find any dominant piranha in the aquarium or determine if there are no such piranhas.

Note that you have to find any (exactly one) dominant piranha, you don't have to find all of them.

For example, if a=[5,3,4,4,5], then the third piranha can be dominant. Consider the sequence of its moves:

The piranha eats the second piranha and a becomes [5,5–,4,5] (the underlined piranha is our candidate).
The piranha eats the third piranha and a becomes [5,6–,5].
The piranha eats the first piranha and a becomes [7–,5].
The piranha eats the second piranha and a becomes [8–].
You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (2≤n≤3⋅105) — the number of piranhas in the aquarium. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the size of the i-th piranha.

It is guaranteed that the sum of n does not exceed 3⋅105 (∑n≤3⋅105).

Output
For each test case, print the answer: -1 if there are no dominant piranhas in the aquarium or index of any dominant piranha otherwise. If there are several answers, you can print any.

Example
inputCopy
6
5
5 3 4 4 5
3
1 1 1
5
4 4 3 4 4
5
5 5 4 3 2
3
1 1 2
5
5 4 3 5 5
outputCopy
3
-1
4
3
3
1
Note
The first test case of the example is described in the problem statement.

In the second test case of the example, there are no dominant piranhas in the aquarium.

In the third test case of the example, the fourth piranha can firstly eat the piranha to the left and the aquarium becomes [4,4,5,4], then it can eat any other piranha in the aquarium.


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
	ll a[n];
	foi(n)
	cin >> a[i];
	ll f = 0;
	foi(n - 1) {
		if (a[i] != a[i + 1]) {
			f = 1;
			break;
		}
	}
	if (!f) {
		cout << -1;
		return;
	}
	ll ans = -1, mx = -1;
	foi(n) {
		if (a[i] > mx  ) {
			mx = a[i];
			ans = i + 1;
		}
		if (a[i] == mx and a[i + 1] < a[i]  ) {
			mx = a[i];
			ans = i + 1;
		}
	}
	cout << ans;
}
