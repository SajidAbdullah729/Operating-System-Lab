/*
Author: Mohammad Abdullah-Al-Sajid Chowdhury
*/


#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
bool Find(ll val,vll &jayga)
{
    for(ll i=0;i<jayga.size();i++)
    {
        if(jayga[i]==val) return 1;
    }
    return 0;
}

void Print(vll &v)
{
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]==-1)  cout<<"Empty ";
        else cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{

    ll n;cin>>n;
    ll frames;cin>>frames;
    vll v;
    ll idx=0,faults=0;
    vll jayga(frames,-1);
    for(ll i=0;i<n;i++)
    {
        ll d;cin>>d;
        bool f=1;
        v.pb(d);
        if(!Find(d,jayga))
        {
            jayga[idx%frames]=d;
            idx++;
            faults++;
            f=0;

        }
        else f=1;
        if(i+1==1) cout<<"After 1st Value: \n";
        else if(i+1==2) cout<<"After 2nd Value: \n";
        else if(i+1==3) cout<<"After 3rd Value: \n";
        else cout<<"After "<<i+1<<"th value:\n";

        Print(jayga);

        if(!f) cout<<"Faults.\n";
        else cout<<"No Faults\n";

    }
    cout<<"Total Faults="<<faults<<endl;

    return 0;
}

/*
22 3
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1

*/
