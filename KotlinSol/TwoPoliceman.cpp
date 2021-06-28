/*
C. Two Policemen
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a street that can be represented as an array of length n.

There are two policemen patrolling a street: the first one is standing at the point x of the street and the second one is standing at the point y of the street.

During one minute, both policemen can decide what to do (independently): move left (if the current position is greater than 1), move right (if the current position is less than n), or do nothing.

The street is considered clear if each point of the street is visited by at least one policeman.

Your task is to find the minimum number of minutes the policemen need to visit each point of the street (again, each point should be visited by at least one of them).

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The only line of the test case contains three integers n, x and y (2≤n≤106; 1≤x,y≤n; x≠y) — the length of the street, the position of the first policeman and the position of the second policeman, respectively.

It is guaranteed that the sum of n does not exceed 106 (∑n≤106).

Output
For each test case, print one integer — the minimum number of minutes the policemen need to visit each point of the street.

Example
inputCopy
6
4 1 2
7 7 1
10 2 6
8 5 2
2 1 2
20 4 14
outputCopy
2
3
5
4
0
12

*/
import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    var tc = readInt()
    for (q in 0 until tc) {
        var (n,x,y) = readInts()
        var t=maxOf(x,y)
        var t1=minOf(x,y)
        x=t1
        y=t
        var l=maxOf(x-1,n-y)
        var r=n
        while(l<r){
        var m=(l+r)/2
        var x1=maxOf((m-(x-1))/2,m-2*(x-1))
        var y1=maxOf((m-(n-y))/2,m-2*(n-y))
        if(x1+y1+1>=y-x){
        r=m
        }
        else {
        l=m+1
        }
        }
        println(l)
    }
}
