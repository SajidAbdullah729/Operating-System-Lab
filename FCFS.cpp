/*
Author: Mohammad Abdullah-Al-Sajid Chowdhury
*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
ll head,cm=0,n;
vector<ll> v;
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
    for(ll i=1;i<v.size();i++)
    {
        cm+=llabs(v[i]-head);
        head=v[i];
    }
    cout<<"Cylinder Serving Order = ";
    Print(v);
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
