/*
------------------------- ALLAH is Almighty -----------------------------
    @author: Mohammad Nazim Uddin
    University: SUST
    OJ: codeforces
    problem name: contest
*/

#include <bits/stdc++.h>

// header file

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <numeric>
#include <cstring>

using namespace std ;

//define function

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>n ; i--)
#define fore0(i,a,n) for(int i=a ; i>=n ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 15000000+9
#define sz 500+7
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long
#define fs first
#define sc second
#define wait system("pause")
#define sf scanf
#define pf printf
#define mp make_pair

//debug

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

// moves

const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // horizontal->vertical->diagonal
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};     //knight moves


//close

// --------------------------------------------- MNU --------------------------------------------- //

const int MX = 1000005 ;
int grunday[MX] , rev[6] = { 1 , 4 , 27, 256, 3125, 46656} ; // in a single move n*n can be removed
int Cal(int x)
{
    if( x == 0 ) return 0 ; // base case , grunday is always zero
    int &ret = grunday[x];
    if( ret != -1 ) return ret;
    set <int> s ;
    int i ;
    for (i = 0 ;  i < 6 ; i++ )
    {
        if( x - rev[i] >= 0 )
        s.insert(Cal(x-(rev[i])));
    }
    int ans = 0 ;
    while(s.find(ans) != s.end()) ans++;
    return ret = ans ;
}
int main()
{
  // ios_base::sync_with_stdio(0); cin.tie(0);
    clr(grunday,-1);
    int cs , t ;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n , i , ans = 0 , x ;
        scanf("%d",&n);
        for ( i = 0 ; i < n ; i++ )
        {
            scanf("%d",&x);
            ans ^= Cal(x);
        }
        if( ans ) puts("Little Chef"); // first mover win
        else puts("Head Chef");
    }

    return 0;
}
