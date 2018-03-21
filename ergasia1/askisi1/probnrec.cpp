#include<bits/stdc++.h>
#include <iostream>
#define maxlongint 1000000000000000000 
using namespace std;
typedef unsigned long long int ll;

// Utility function to find GCD of 'a' and 'b'
ll gcd(ll a, ll b)

{
        if (b==0)
                return a;
        return gcd(b, a%b);
}


ll a1,a2,previous_lcmLeft;

ll findlcmLeft(ll previous_lcmLeft, ll ak)
{
        return (( (previous_lcmLeft * ak )) / (gcd(previous_lcmLeft,ak) ) );
}

ll findlcmRight(int a[] ,int n , int k)
{
        if(k==n-1 || k==n) return 1;
    // Initialize result
    ll ans = a[k+1];

    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=k+2; i<n; i++)
        ans = (a[i]*ans) /
                (gcd(a[i], ans)) ;

    return ans;
}



ll findlcmForK(int *a ,int n , int k)
{

        if(k==0){ previous_lcmLeft=a[0]; return findlcmRight(a,n,k); }
//      else if(k==n-1|| k==n) { return previous_lcmLeft=findlcmLeft(previous_lcmLeft,a[k-1]) ; } 
        a1=findlcmLeft(previous_lcmLeft,a[k-1]);
        previous_lcmLeft=a1;
        a2=findlcmRight(a,n,k);
        return findlcmLeft(a1,a2);
}

int main(int argc, char* argv[])
{
        ifstream infile;
        infile.open(argv[1]);
        int n;
        infile >> n;
        int i,j=0;
        int a[n];
        for(i=0; i<n; i++)
                infile>> a[i];
        ll r,rmin=maxlongint;
        for(i=0;i<n+1;i++)
        {
                r=findlcmForK(a,n,i);
              if(r<=rmin)
                {       rmin=r;
                        j=i+1;
                                 }
        }
        if(j==n+1) j=0;
        cout<<rmin<<" " <<j<<endl;
          return 0;


}
