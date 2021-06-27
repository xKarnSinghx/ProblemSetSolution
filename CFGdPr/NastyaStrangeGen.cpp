/*
C. Nastya and Strange Generator
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Denis was very sad after Nastya rejected him. So he decided to walk through the gateways to have some fun. And luck smiled at him! When he entered the first courtyard, he met a strange man who was selling something.

Denis bought a mysterious item and it was... Random permutation generator! Denis could not believed his luck.

When he arrived home, he began to study how his generator works and learned the algorithm. The process of generating a permutation consists of n steps. At the i-th step, a place is chosen for the number i (1≤i≤n). The position for the number i is defined as follows:

For all j from 1 to n, we calculate rj  — the minimum index such that j≤rj≤n, and the position rj is not yet occupied in the permutation. If there are no such positions, then we assume that the value of rj is not defined.
For all t from 1 to n, we calculate countt  — the number of positions 1≤j≤n such that rj is defined and rj=t.
Consider the positions that are still not occupied by permutation and among those we consider the positions for which the value in the count array is maximum.
The generator selects one of these positions for the number i. The generator can choose any position.
Let's have a look at the operation of the algorithm in the following example:


Let n=5 and the algorithm has already arranged the numbers 1,2,3 in the permutation. Consider how the generator will choose a position for the number 4:

The values of r will be r=[3,3,3,4,×], where × means an indefinite value.
Then the count values will be count=[0,0,3,1,0].
There are only two unoccupied positions in the permutation: 3 and 4. The value in the count array for position 3 is 3, for position 4 it is 1.
The maximum value is reached only for position 3, so the algorithm will uniquely select this position for number 4.
Satisfied with his purchase, Denis went home. For several days without a break, he generated permutations. He believes that he can come up with random permutations no worse than a generator. After that, he wrote out the first permutation that came to mind p1,p2,…,pn and decided to find out if it could be obtained as a result of the generator.

Unfortunately, this task was too difficult for him, and he asked you for help. It is necessary to define whether the written permutation could be obtained using the described algorithm if the generator always selects the position Denis needs.

Input
The first line contains a single integer t (1≤t≤105)  — the number of test cases. Then the descriptions of the test cases follow.

The first line of the test case contains a single integer n (1≤n≤105)  — the size of the permutation.

The second line of the test case contains n different integers p1,p2,…,pn (1≤pi≤n)  — the permutation written by Denis.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
Print "Yes" if this permutation could be obtained as a result of the generator. Otherwise, print "No".

All letters can be displayed in any case.

Example
inputCopy
5
5
2 3 4 5 1
1
1
3
1 3 2
4
4 2 3 1
5
1 5 2 4 3
outputCopy
Yes
Yes
No
Yes
No
Note
Let's simulate the operation of the generator in the first test.

At the 1 step, r=[1,2,3,4,5],count=[1,1,1,1,1]. The maximum value is reached in any free position, so the generator can choose a random position from 1 to 5. In our example, it chose 5.

At the 2 step, r=[1,2,3,4,×],count=[1,1,1,1,0]. The maximum value is reached in positions from 1 to 4, so the generator can choose a random position among them. In our example, it chose 1.

At the 3 step, r=[2,2,3,4,×],count=[0,2,1,1,0]. The maximum value is 2 and is reached only at the 2 position, so the generator will choose this position.

At the 4 step, r=[3,3,3,4,×],count=[0,0,3,1,0]. The maximum value is 3 and is reached only at the 3 position, so the generator will choose this position.

At the 5 step, r=[4,4,4,4,×],count=[0,0,0,4,0]. The maximum value is 4 and is reached only at the 4 position, so the generator will choose this position.

In total, we got a permutation of 2,3,4,5,1, that is, a generator could generate it.*/
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
typedef map<pair<ll, ll>, ll>  mplll;
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
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	foi(n - 1) {
		if (a[i + 1] - a[i] > 1) {
			cout << "No";
			return;
		}
	}
	cout << "Yes";
}
 
