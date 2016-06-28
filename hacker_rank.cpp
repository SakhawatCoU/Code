/**
  *                              ------------------------- ALLAH is Almighty -----------------------------
  *  @author: M. NAZIM UDDIN
  *  University: SUST
  *  OJ: HackerRank
  *  problem name:
  * Category :
  */

// Pre_code

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

#pragma comment(linker, "/STACK:667772160")
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
#define sz 100000+7
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
#define ps pf("PASS\n")

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

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//close

int dp[sz][4][4][3] ;
int arr[10] , n ;

int rec(int pos,int sa, int sb,int flag)
{
    if(pos == n)
    {
        int p = abs(sa-sb)%3 ;

        if(flag)
            return (p == 0) ;

        else
            return (p != 0) ;
    }

    int& ret = dp[pos][sa][sb][flag] ;
    int temp ;

    if(ret != -1)
    {
        if(flag)
            return (ret == 0) ;

        return (ret >= 1) ;
    }

    ret = 0 ;

    for(int i=0 ; i<3 ; i++)
    {
        if(arr[i] == 0)
            continue;

        arr[i]--;

        if(flag)
        {
            temp = (sb + i) %3 ;

            if(rec(pos+1,sa,temp,0))
            {
                ret = 1 ;
                arr[i]++;

                break;
            }
            arr[i]++;
        }

        else
        {
            temp = (sa+i)%3 ;

            if(rec(pos+1,temp,sb,1))
            {
                ret = 1 ;
                arr[i]++;

                break;
            }
            arr[i]++;
        }
    }

    if(flag)
        return (ret == 0) ;

    return (ret >= 1) ;
}


int main()
{
    int tcase , a , ans = 0 ;

    sf1(tcase);

    while(tcase--)
    {
        sf1(n);

        clr(arr,0);
        clr(dp,-1);

        for(int i=0 ; i<n ; i++)
        {
            sf1(a);
            a = a%3 ;
            arr[a]++;
        }

        ans = rec(0,0,0,1) ;

        if(ans)
            pf("Koca\n");
        else
            pf("Balsa\n");
    }

    return 0;
}
