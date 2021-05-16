/*
You are given a tree with N nodes numbered from 1 to N. A set S of nodes is called valid if there exist two vertices u and v (possibly, u=v) such that every node in S lies on the simple path from u to v

.

Count the number of valid sets modulo 109+7
. Two sets are different if one node is included in one set and not in the other. If there are multiple pairs (u,v)

making a set valid, that set is still only counted once.
Input

    The first line contains an integer T

, the number of test cases. Then the test cases follow.
Each test case contains N
lines of input.
The first line contains a single integer N
, the number of tree nodes.
Each of the next N−1
lines contains two space-separated integers u and v representing an edge between nodes u and v

    .

Output

For each test case, output in a single line the number of valid sets modulo 109+7

.
Constraints

    1≤T≤50

1≤N≤105
1≤u,v≤N
Sum N
over all testcases is at most 5⋅105
.
The given input is a valid tree.
*/
