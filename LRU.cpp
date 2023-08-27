#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

void Print(vll &v)
{
    for(ll i=0; i<v.size(); i++)
    {
        if(v[i]==-1)  cout<<"Empty ";
        else cout<<v[i]<<" ";
    }
    cout<<endl;
}

ll NextIdx(vll &v,ll left,ll right,vll jayga)
{
    ll idx=0;
    ll sz=jayga.size();
    //vll vis (sz+1,0);
        ll ans=1e9,pos=0;
        for(ll j=0;j<jayga.size();j++)
        {
            ll val=jayga[j];
            ll idx=-1e9;
            for(ll i=right;i>=left;i--)
            {
                if(v[i]==val)
                {
                    idx=i;
                    break;
                }
            }
            if(idx<ans)
            {
                ans=idx;
                pos=j;

            }


        }
    return pos;
}

bool Find(ll val,vll &jayga)
{
    for(ll i=0;i<jayga.size();i++)
    {
        if(jayga[i]==val) return 1;
    }
    return 0;
}
int main()
{

    ll n;
    cin>>n;
    ll frames;
    cin>>frames;
    vll v;
    ll idx=0;
    vll jayga(frames,-1);
    //ll idx=0;
    for(ll i=0; i<n; i++)
    {
        ll d;cin>>d;
        v.pb(d);





    }
    idx=0;
    ll i=0,faults=0;
    for(;i<n;i++)
    {

        if(idx==frames) break;
        bool f=1;
        ll val=v[i];
        if(!Find(val,jayga))
        {
            jayga[idx]=v[i];
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
    for(;i<n;i++)
    {
        ll val=v[i];
        //cout<<val<<"\n\n";
        bool f=1;
        if(!Find(val,jayga))
        {
            f=0;
            faults++;
            ll pos=NextIdx(v,0,i-1,jayga);
            jayga[pos]=val;
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
    cout<<"Faults="<<faults<<endl;

    return 0;
    //jayga[idx]=d;


    //Print(jayga);
}
/*
 22 3
 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
*/



//return 0;
//}
