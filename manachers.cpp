// ==========================================================================
//
//                   Bismillah ir-Rahman ir-Rahim
//
// ==========================================================================

/*************************************************************************
  ████      ▀███▀    ▄▄▄▀▀▀▀▄▄▄   █▀▄▀▄▀▄▀▄▀▄█  ▀███▀   ████       ████
  ███ █      ███     ███    ███              █   ███    ███ █     █ ███
  ███  █     ███     ███    ███            █     ███    ███  █   █  ███
  ███   █    ███     ███    ███          █       ███    ███   █▄█   ███
  ███    █   ███     ███▀▀▀▀███        █         ███    ███         ███
  ███     █  ███     ███    ███      █           ███    ███         ███
  ███      █ ███     ███    ███    █             ███    ███         ███
 ▄███▄      ████     ███    ███   █▄▀▄▀▄▀▄▀▄▀█  ▄███▄  ▄███▄       ▄███▄
**************************************************************************/

// Pre_code

//#include <bits/stdc++.h>

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
#define Max 1000000000
#define sz 1000000+7
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
#define Read freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\input.txt","r",stdin)
#define Write freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\output.txt","w",stdout)
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

char str[sz] , fstr[2*sz] ;
int len , p[2*sz] ;

void reset()
{
    len = strlen(str);
    fstr[0] = '^' ;
    p[0] = 0 ;
    int k = 1 ;

    for(int i=0 ; i<len ; i++)
    {
        p[k] = 0 ;
        fstr[k++] = '#';
        p[k] = 0 ;
        fstr[k++] = str[i] ;
    }

    fstr[k++] = '#' ;
    fstr[k++] = '$' ;

    len = len*2 + 2 ;
}

int manchers()
{
    int r = 0 , c = 0 , miror ;
    int mx = 0 ;

    for(int i=1 ; i<len ; i++)
    {
        miror = 2*c - i ;

        p[i] = r > i ? min(r-i,p[miror]) : 0 ;

        while(fstr[i+1+p[i]] == fstr[i-1-p[i]])
            p[i]++;

        if(i+p[i] > r)
        {
            c = i ;
            r = i+p[i] ;
        }

        mx = max(mx,p[i]);
    }

    return mx;
}

int main()
{
    int ans , cas = 0 ;

    while(sf("%s",str) and str[0] != 'E')
    {
        reset();
        ans = manchers();

        pf("Case %d: %d\n",++cas,ans);
    }

    return 0;
}
