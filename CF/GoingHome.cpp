/*
C. Going Home
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
It was the third month of remote learning, Nastya got sick of staying at dormitory, so she decided to return to her hometown. In order to make her trip more entertaining, one of Nastya's friend presented her an integer array a.

Several hours after starting her journey home Nastya remembered about the present. To entertain herself she decided to check, are there four different indices x,y,z,w such that ax+ay=az+aw.

Her train has already arrived the destination, but she still hasn't found the answer. Can you help her unravel the mystery?

Input
The first line contains the single integer n (4≤n≤200000) — the size of the array.

The second line contains n integers a1,a2,…,an (1≤ai≤2.5⋅106).

Output
Print "YES" if there are such four indices, and "NO" otherwise.

If such indices exist, print these indices x, y, z and w (1≤x,y,z,w≤n).

If there are multiple answers, print any of them.

Examples
inputCopy
6
2 1 5 2 7 4
outputCopy
YES
2 3 1 6 
inputCopy
5
1 3 1 9 20
outputCopy
NO
Note
In the first example a2+a3=1+5=2+4=a1+a6. Note that there are other answer, for example, 2 3 4 6.

In the second example, we can't choose four indices. The answer 1 2 2 3 is wrong, because indices should be different, despite that a1+a2=1+3=3+1=a2+a3
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


		solve();


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
void findPairs(int arr[], int n)
{


}
void solve()
{
	ll n;
	cin >> n;
	vll a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	unordered_map<ll, vpii > map;

	for (ll i = 0; i < n - 1; i++) {
		for (ll j = i + 1; j < n; j++) {
			ll  sum = a[i] + a[j];
			if (map.find(sum) != map.end()) {
				for (auto p : map.find(sum)->second) {
					ll m = p.first, n1 = p.second;
					if ((m != i && m != j) && (n1 != i && n1 != j)) {
						cout << "YES" << endl;
						cout << i + 1 << " " << j + 1 << " " << m + 1 << " " << n1 + 1 << " ";
						return;
					}
				}
			}

			else map[sum].pb({ i, j });
		}
	}
	cout << "NO";

}
