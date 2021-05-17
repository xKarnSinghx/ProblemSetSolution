/*
C. Boats Competition
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n people who want to participate in a boat competition. The weight of the i-th participant is wi. Only teams consisting of two people can participate in this competition. As an organizer, you think that it's fair to allow only teams with the same total weight.

So, if there are k teams (a1,b1), (a2,b2), …, (ak,bk), where ai is the weight of the first participant of the i-th team and bi is the weight of the second participant of the i-th team, then the condition a1+b1=a2+b2=⋯=ak+bk=s, where s is the total weight of each team, should be satisfied.

Your task is to choose such s that the number of teams people can create is the maximum possible. Note that each participant can be in no more than one team.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤50) — the number of participants. The second line of the test case contains n integers w1,w2,…,wn (1≤wi≤n), where wi is the weight of the i-th participant.

Output
For each test case, print one integer k: the maximum number of teams people can compose with the total weight s, if you choose s optimally.

Example
inputCopy
5
5
1 2 3 4 5
8
6 6 6 6 6 6 8 8
8
1 2 2 1 2 1 1 2
3
1 3 3
6
1 1 3 4 2 2
outputCopy
2
3
4
1
2
Note
In the first test case of the example, we can reach the optimal answer for s=6. Then the first boat is used by participants 1 and 5 and the second boat is used by participants 2 and 4 (indices are the same as weights).

In the second test case of the example, we can reach the optimal answer for s=12. Then first 6 participants can form 3 pairs.

In the third test case of the example, we can reach the optimal answer for s=3. The answer is 4 because we have 4 participants with weight 1 and 4 participants with weight 2.

In the fourth test case of the example, we can reach the optimal answer for s=4 or s=6.

In the fifth test case of the example, we can reach the optimal answer for s=3. Note that participant with weight 3 can't use the boat because there is no suitable pair for him in the list.

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
	ll a[101] = {};
	foi(n) {
		ll x;
		cin >> x;
		a[x]++;
	}
	ll ans = 0;
	for (ll j = 1; j < 101; j++)
	{
		ll c = 0;
		foi(j + 1) {
			c += min(a[i], a[j - i]);
			ans = max(ans, c / 2);
		}
	}
	cout << ans;

}

