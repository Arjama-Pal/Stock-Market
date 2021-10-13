#include<bits/stdc++.h>
using namespace std;
 
int maxProfit(int n, vector<int> &a)
{
    int i;
    int mx;
    int mn;
    int profit;
 
    vector<vector<int> >dp(2,vector<int>(n));
    dp[0][0]=0;
    mn=a[0];
 
    for(i=1;i<n;i++)
    {
        dp[0][i]=max(dp[0][i-1],a[i]-mn);
 
        if(a[i]<mn)
        {
            mn=a[i];
        }
 
    }
    dp[1][n-1]=0;
    mx=a[n-1];
    profit=dp[0][n-1];
 
    for(i=n-2;i>=2;i--)
    {
        dp[1][i]=max(dp[1][i+1],mx-a[i]);
 
        profit=max(profit,dp[1][i]+dp[0][i-1]);
 
        if(a[i]>mx)
        {
            mx=a[i];
        }
 
    }
 
    return profit;
}
 
int main()
{
    int i,n;
    cout<<"Enter the number of stock values ";
    cin>>n;
 
    vector<int> a(n);
    cout<<"Enter the values of stock on each day "<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
 
    cout<<"Maximum profit that could be made by buying and selling a share at most twice"<<endl;
    cout<<maxProfit(n,a);
 
    cout<<endl;
    return 0;
}
