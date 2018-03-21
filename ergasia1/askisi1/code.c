#include<bits/stdc++.h>
#include <iostream>
#define maxlongint 1000000000000000000 
using namespace std;
typedef unsigned long long int ll;

// Utility function to find GCD of 'a' and 'b'
int gcd(ll a, ll b)

{
        if (b==0)
                return a;
        return gcd(b, a%b);
}

// Returns LCM of array elements
ll findlcm(int arr[], int n,int k)
{
        // Initialize result
        ll ans;
        if (k==0) {ans=arr[1];}
        else {  ans = arr[0]; }

        // ans contains LCM of arr[0],..arr[i]
        // after i'th iteration,
        for (int i=1; i<n; i++)
                if(k==i || (k==0 && i==1))  continue;
                else   ans = ( ((arr[i]*ans)) /
                                (gcd(arr[i], ans)) );

        return ans;
}
int main(int argc,char* argv[])
{
        ifstream infile;
        infile.open(argv[1]);
        int n;
        infile >> n;
        int i,j=0;
        int a[n];
//      unsigned long long int r[n+1];
        for(i=0; i<n; i++)
                infile>> a[i];
        unsigned long long int r,rmin=maxlongint;
        for(i=0;i<n+1;i++)
        {
                r=findlcm(a,n,i);

                if(r<=rmin) {rmin=r;
                j=i+1;
         }
        }
        if(j==n+1) j=0;
        cout<<rmin<<" " <<j<<endl;
        /*sorting R and pick minimum
          sort(r,r+n+1);
          for(i=0; i<n+1; i++)
          cout<<r[i]<<endl; */
          return 0;


}
