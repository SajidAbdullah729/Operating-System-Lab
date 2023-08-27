/*
Author: Mohammad Abdullah-Al-Sajid Chowdhury
*/


#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
ll head,cm=0,n;
vector<ll> v,vis,gm;

void Print(vector<ll> &v)
{
    ll sz=v.size();
    for(ll i=0;i<v.size();i++)
    {
        if(i!=sz-1) cout<<v[i]<<" -> ";
        else {
            cout<<v[i]<<endl;
            break;
        }
    }

}
int main()
{
    cout<<"Head: ";
    cin>>head;
    ll cc;
    cout<<"Cylinder size = ";
    cin>>cc;
    v.pb(head);
    gm.pb(head);
    cout<<"Total Requests: ";
    cin>>n;
    vis.assign(n+2,0);
    cout<<"Cylinder Requests: ";

    for(ll i=0;i<n;i++)
    {
        ll d;cin>>d;v.pb(d);
    }

    for(ll i=1;i<v.size();i++)
    {
        ll minn=1e18,idx=-1;
        for(ll j=1;j<v.size();j++)
        {
           if(llabs(head-v[j])<=minn && !vis[j])
           {
               minn=llabs(head-v[j]);
               idx=j;
           }
        }
        if(idx==-1) break;

        gm.pb(v[idx]);
        cm+=(v[idx]-head);
        vis[idx]=1;
        head=v[idx];




    }
    cout<<"Cylinder Serving Order = ";
    Print(gm);
    cout<<"Total Cylinder Movement = ";
    cout<<cm<<endl;
    return 0;
}

/*
53
200
8
98 183 37 122 14 124 65 67
*/

