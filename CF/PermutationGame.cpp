/*
B. Permutation Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
n children are standing in a circle and playing a game. Children's numbers in clockwise order form a permutation a1, a2, ..., an of length n. It is an integer sequence such that each integer from 1 to n appears exactly once in it.

The game consists of m steps. On each step the current leader with index i counts out ai people in clockwise order, starting from the next person. The last one to be pointed at by the leader becomes the new leader.

You are given numbers l1, l2, ..., lm — indices of leaders in the beginning of each step. Child with number l1 is the first leader in the game.

Write a program which will restore a possible permutation a1, a2, ..., an. If there are multiple solutions then print any of them. If there is no solution then print -1.

Input
The first line contains two integer numbers n, m (1 ≤ n, m ≤ 100).

The second line contains m integer numbers l1, l2, ..., lm (1 ≤ li ≤ n) — indices of leaders in the beginning of each step.

Output
Print such permutation of n numbers a1, a2, ..., an that leaders in the game will be exactly l1, l2, ..., lm if all the rules are followed. If there are multiple solutions print any of them.

If there is no permutation which satisfies all described conditions print -1.

Examples
inputCopy
4 5
2 3 1 4 4
outputCopy
3 1 2 4 
inputCopy
3 3
3 1 2
outputCopy
-1
Note
Let's follow leadership in the first example:

Child 2 starts.
Leadership goes from 2 to 2 + a2 = 3.
Leadership goes from 3 to 3 + a3 = 5. As it's greater than 4, it's going in a circle to 1.
Leadership goes from 1 to 1 + a1 = 4.
Leadership goes from 4 to 4 + a4 = 8. Thus in circle it still remains at 4.
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


//	ll tc ; cin >> tc;
//	while (tc--)
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
	ll n, m;
	cin >> n >> m;
	ll l[m];
	foi(m)
	cin >> l[i];
	ll a[n] = {};
	for (ll i = 1; i < m; i++) {
		if (a[l[i - 1] - 1] == l[i] - l[i - 1] or a[l[i - 1] - 1] == l[i] - l[i - 1] + n or a[l[i - 1] - 1] == 0)
		{	a[l[i - 1] - 1] = l[i] - l[i - 1];
			if (a[l[i - 1] - 1] <= 0)
				a[l[i - 1] - 1] += n;
		}
		else {
			cout << -1;
			return;
		}
		//cout << a[l[i - 1] - 1] << " ";
	}
	ll ans = -1;
	ll cnt[n] = {};
	foi(n) {
		if (a[i] != 0) {
			cnt[a[i] - 1]++;
		}
	}

	ll x = 0;
	ll value[n] = {};
	foi(n) {
		if (cnt[i] == 0) {
			value[x] = i + 1;
			x++;
		}
	}
	x = 0;
	//sort(cnt, cnt + n);
	foi(n) {
		if (cnt[i] == 2) {
			cout << ans;
			return;
		}
		if (a[i] == 0) {
			a[i] = value[x];
			x++;
		}
		//cout << cnt[i] << " ";
	}
	ll cnt1[n] = {};
	foi(n) {
		cnt1[a[i] - 1]++;
	}
	foi(n) {
		if (cnt1[i] != 1) {
			cout << ans;
			return;
		}
		//cout << cnt1[i] << " ";
	}
	ll f = -1;
	foi(m - 1) {
		if (l[i] == l[i + 1] and f == -1)
			f = l[i];
		else if (f != -1 and l[i] != l[i + 1]) {
			cout << ans;
			return;
		}
	}
	foi(n)
	cout << a[i] << " ";

}

 
