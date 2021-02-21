/*
C. Learning Languages
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The "BerCorp" company has got n employees. These employees can use m approved official languages for the formal correspondence. The languages are numbered with integers from 1 to m. For each employee we have the list of languages, which he knows. This list could be empty, i. e. an employee may know no official languages. But the employees are willing to learn any number of official languages, as long as the company pays their lessons. A study course in one language for one employee costs 1 berdollar.

Find the minimum sum of money the company needs to spend so as any employee could correspond to any other one (their correspondence can be indirect, i. e. other employees can help out translating).

Input
The first line contains two integers n and m (2 ≤ n, m ≤ 100) — the number of employees and the number of languages.

Then n lines follow — each employee's language list. At the beginning of the i-th line is integer ki (0 ≤ ki ≤ m) — the number of languages the i-th employee knows. Next, the i-th line contains ki integers — aij (1 ≤ aij ≤ m) — the identifiers of languages the i-th employee knows. It is guaranteed that all the identifiers in one list are distinct. Note that an employee may know zero languages.

The numbers in the lines are separated by single spaces.

Output
Print a single integer — the minimum amount of money to pay so that in the end every employee could write a letter to every other one (other employees can help out translating).

Examples
inputCopy
5 5
1 2
2 2 3
2 3 4
2 4 5
1 5
outputCopy
0
inputCopy
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
outputCopy
2
inputCopy
2 2
1 2
0
outputCopy
1
Note
In the second sample the employee 1 can learn language 2, and employee 8 can learn language 4.

In the third sample employee 2 must learn language 2.


*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001 

using namespace std; 

int ans = 0;
vector<bool> visited;


void Addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void DFSRec(vector<int> adj[], int s)
{
    visited[s] = true;
    // cout << s << " ";

    for(int u: adj[s])
        if(!visited[u])
        DFSRec(adj, u);
}

void DFS(vector<int> adj[], int v, int s)
{
    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            ans += 1;
            DFSRec(adj, i);
        }
        
    }
    
}
void printGraph(vector<int>adj[], int v)
{
	for (int i = 0; i < v; ++i)
	{
		cout << i << "-> ";
		for (auto x : adj[i])
			cout << x << " ";
		cout << endl;
	}
}
void solve()
{
    int n, v;
    cin >> v >> n;
    visited.resize(v, false);
    vector<int> adj[v];
    vector<unordered_set<int>> spa(v);
    for(int i = 0; i < v; i++)
    {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            spa[i].insert(y);
            for(int k = 0; k < v; k++)
            {
                if(spa[k].find(y) != spa[k].end() && k != i)
                Addedge(adj, i, k);
            }
        }
    }
    DFS(adj, v, 0);
    bool diff = true;
    for(int i = 0; i < v; i++)
    {
        if(spa[i].size() != 0)
        diff = false;
    }
    if(diff)
    cout << ans ;
    else
    cout << ans - 1 ;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
