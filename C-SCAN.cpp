#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
ll head,cm=0,n;
vector<ll> gm,v;
vector<ll> bame,dane;
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
    v.pb(head);
    gm.pb(head);
    ll cc;
    cout<<"Cylinder size = ";
    cin>>cc;
    cout<<"Total Requests: ";
    cin>>n;
    cout<<"Cylinder Requests: ";

    for(ll i=0;i<n;i++)
    {
        ll d;cin>>d;v.pb(d);
    }
    //dane.pb(111111);
    for(ll i=1;i<v.size();i++)
    {
        if(v[i]>=head) dane.pb(v[i]);
        else if(v[i]<head) bame.pb(v[i]);
    }

    if(dane.size()>0) dane.pb(cc-1);
    if(bame.size()>0) bame.pb(0);
    sort(dane.begin(),dane.end());
    sort(bame.begin(),bame.end());
    for(ll i=0;i<dane.size();i++)
    {
        cm+=llabs(head-dane[i]);
        gm.pb(dane[i]);
        head=dane[i];
    }
    for(ll i=0;i<bame.size();i++)
    {
        cm+=llabs(head-bame[i]);
        gm.pb(bame[i]);
        head=bame[i];
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

