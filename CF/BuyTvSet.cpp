/*
B. Buying a TV Set
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Monocarp has decided to buy a new TV set and hang it on the wall in his flat. The wall has enough free space so Monocarp can buy a TV set with screen width not greater than a and screen height not greater than b. Monocarp is also used to TV sets with a certain aspect ratio: formally, if the width of the screen is w, and the height of the screen is h, then the following condition should be met: wh=xy.

There are many different TV sets in the shop. Monocarp is sure that for any pair of positive integers w and h there is a TV set with screen width w and height h in the shop.

Monocarp isn't ready to choose the exact TV set he is going to buy. Firstly he wants to determine the optimal screen resolution. He has decided to try all possible variants of screen size. But he must count the number of pairs of positive integers w and h, beforehand, such that (w≤a), (h≤b) and (wh=xy).

In other words, Monocarp wants to determine the number of TV sets having aspect ratio xy, screen width not exceeding a, and screen height not exceeding b. Two TV sets are considered different if they have different screen width or different screen height.

Input
The first line contains four integers a, b, x, y (1≤a,b,x,y≤1018) — the constraints on the screen width and height, and on the aspect ratio.

Output
Print one integer — the number of different variants to choose TV screen width and screen height so that they meet the aforementioned constraints.

Examples
inputCopy
17 15 5 3
outputCopy
3
inputCopy
14 16 7 22
outputCopy
0
inputCopy
4 2 6 4
outputCopy
1
inputCopy
1000000000000000000 1000000000000000000 999999866000004473 999999822000007597
outputCopy
1000000063
Note
In the first example, there are 3 possible variants: (5,3), (10,6), (15,9).

In the second example, there is no TV set meeting the constraints.

In the third example, there is only one variant: (3,2).


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
ll factorial(ll n)
{
	if (n == 0)
		return 1;
	return (n * factorial(n - 1) % MOD) % MOD;
}
void solve()
{
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	while (gcd(x, y) != 1) {
		ll t = gcd(x, y);
		x /= t;
		y /= t;
	}
	ll fin = min(a / x, b / y);
	cout << fin;
}



 
