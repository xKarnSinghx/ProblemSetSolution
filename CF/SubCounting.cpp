/*
C. Subsequence Counting
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pikachu had an array with him. He wrote down all the non-empty subsequences of the array on paper. Note that an array of size n has 2n - 1 non-empty subsequences in it.

Pikachu being mischievous as he always is, removed all the subsequences in which Maximum_element_of_the_subsequence  -  Minimum_element_of_subsequence  ≥ d

Pikachu was finally left with X subsequences.

However, he lost the initial array he had, and now is in serious trouble. He still remembers the numbers X and d. He now wants you to construct any such array which will satisfy the above conditions. All the numbers in the final array should be positive integers less than 1018.

Note the number of elements in the output array should not be more than 104. If no answer is possible, print  - 1.

Input
The only line of input consists of two space separated integers X and d (1 ≤ X, d ≤ 109).

Output
Output should consist of two lines.

First line should contain a single integer n (1 ≤ n ≤ 10 000)— the number of integers in the final array.

Second line should consist of n space separated integers — a1, a2, ... , an (1 ≤ ai < 1018).

If there is no answer, print a single integer -1. If there are multiple answers, print any of them.

Examples
inputCopy
10 5
outputCopy
6
5 50 7 15 6 100
inputCopy
4 2
outputCopy
4
10 100 1000 10000
Note
In the output of the first example case, the remaining subsequences after removing those with Maximum_element_of_the_subsequence  -  Minimum_element_of_subsequence  ≥ 5 are [5], [5, 7], [5, 6], [5, 7, 6], [50], [7], [7, 6], [15], [6], [100]. There are 10 of them. Hence, the array [5, 50, 7, 15, 6, 100] is valid.

Similarly, in the output of the second example case, the remaining sub-sequences after removing those with Maximum_element_of_the_subsequence  -  Minimum_element_of_subsequence  ≥ 2 are [10], [100], [1000], [10000]. There are 4 of them. Hence, the array [10, 100, 1000, 10000] is valid.


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
typedef pair<pll, ll>      plll;
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

	//ll t ; cin >> t;
	//while (t--)
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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
vb is_prime(1e6 + 1, true);

ll binomialCoeffSpaceEff(ll n, ll k)
{
	ll C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // nC0 is 1

	for (ll i = 1; i <= n; i++) {
		// Compute next row of pascal triangle using
		// the previous row
		for (ll j = min(i, k); j > 0; j--)
			C[j] = (C[j] + C[j - 1]) % MOD;
	}
	return C[k];
}
ll primeFactors(ll n)
{
	vll ar;
	ll i = 2;
	while (n > 0)
	{
		if (i > n) break;
		if (n % i == 0)
		{
			ar.pb(i);
			while (n > 0 and n % i == 0) n = n / i;
		}
		i++;
	}
	return ar.size();
}

vpll primeFactorsFreq(ll n)
{
	vpll ar;
	ll i = 2;
	while (n > 0)
	{
		// cout<<n<<" ";
		if (i > n) break;
		if (n % i == 0)
		{
			ll cnt = 0;
			while (n > 0 and n % i == 0) n = n / i, cnt++;
			ar.pb(mp(i, cnt));
		}
		i++;
	}
	return ar;
}
void seive()
{
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= 1e6 + 1; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= 1e6 + 1; j += i)
				is_prime[j] = false;
		}
	}
}

bool isSorted(vll &ar)
{
	ll n = ar.size();

	for (ll i = 0; i < n - 1; i++)
	{
		if (ar[i + 1] < ar[i]) return false;
	}

	return true;
}

ll fastPower(ll x, ll y)
{
	ll res = 1;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % MOD;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % MOD; // Change x to x^2
	}
	return res;
}

ll kadanesAlgo(vll ar)
{
	ll n = ar.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	for (ll i = 0; i < n; i++)
	{
		currMax += ar[i];

		if (currMax <= ar[i])
		{
			currMax = ar[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}

pll kadanesAlgoIdx(vll ar)
{
	ll n = ar.size();
	ll currMax = 0;
	ll mx = INT_MIN;
	ll a = 0, b;
	for (ll i = 0; i < n; i++)
	{
		currMax += ar[i];

		if (currMax <= ar[i])
		{
			currMax = ar[i];
			a = i;
		}

		if (mx < currMax)
		{
			mx = currMax;
			b = i;
		}
	}
	return mp(a, b);
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
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}
ll findLCS(string a, string b, ll m, ll n)
{

	ll LCS[m + 1][n + 1];
	ll result = 0;
	for (ll i = 0; i <= m; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				LCS[i][j] = 0;

			else if (a[i - 1] == b[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				result = max(result, LCS[i][j]);
			}
			else
				LCS[i][j] = 0;
		}
	}
	return result;
}
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll f(ll x) {
	ll d = 0;
	while (x > 0)
	{
		d += x % 10;
		x /= 10;
	}

	return d;
}
vs generateGray(ll n)
{
	if (n <= 0)
		return {"0"};

	if (n == 1)
	{
		return {"0", "1"};
	}
	vs recAns = generateGray(n - 1);
	vs mainAns;
	for (ll i = 0; i < recAns.size(); i++)
	{
		string s = recAns[i];
		mainAns.push_back("0" + s);
	}
	for (ll i = recAns.size() - 1; i >= 0; i--)
	{
		string s = recAns[i];
		mainAns.push_back("1" + s);
	}
	return mainAns;
}
void generateGraya(ll n)
{
	vs a;
	a = generateGray(n);
	for (ll i = 0 ; i < a.size(); i++ )
		cout << a[i] << endl;
}
void move(ll disks, ll source, ll auxiliary, ll target)
{
	if (disks > 0)
	{
		move(disks - 1, source, target, auxiliary);
		cout << source << "  " << target << endl;
		move(disks - 1, auxiliary, source, target);
	}
}
ld polyarea(ld n, ld a)
{
	if (a < 0 && n < 0)
		return -1;

	ld A = (a * a * n) / (4 * tan((180 / n) * 3.14159 / 180));

	return A;
}
ll eqDiv(ll *a, ll s1, ll s, ll l) {
	if (l == 0)
		return abs((s - s1) - s1);

	return min(eqDiv(a, s1 + a[l], s, l - 1), eqDiv(a, s1, s, l - 1));

}
ll noofdigit(ll n) {
	ll x = 0;
	while (n > 0) {
		n /= 10;
		x++;
	}
	return x;
}
ll firstdigit(ll n) {
	ll x = 0;
	while (n > 9) {
		n /= 10;
	}
	x = n % 10;
	return x;
}
ll b = 1;
void solve()
{
	ll x, d;
	cin >> x >> d;
	vll ans;
	ll c = 1;
	foi(32) {
		if (x & (1 << i)) {
			for (ll j = 1; j <= i; j++)
				ans.pb(c);
			c += d;
			ans.pb(c);
			c += d;
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << " ";

}



 
