/*
Author: Mohammad Abdullah-Al-Sajid Chowdhury
*/


#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<"="<<x<<endl
typedef long long int ll;

set<ll> s;
map<ll,ll> refbit;

map<ll,ll> prothomashche;
priority_queue<pair<ll,ll> > pq;
ll n,m;

void Clear()
{
    while(!pq.empty()) pq.pop();
}
vector<ll> jayga;
void print(ll i,ll val)
{
    if(i==1)
    {
        cout<<"After 1st request :\n";
    }
    else if(i==2)
    {
        cout<<"After 2nd request :\n";
    }
    else if(i==3)
    {
        cout<<"After 3rd request :\n";
    }
    else
    {
        cout<<"After "<<i<<"th request :\n";
    }
    cout<<val<<endl;
    for(ll j=0;j<m;j++)
    if(jayga[j]==-1) cout<<"Empty "; else cout<<jayga[j]<<" ";
    cout<<endl;
}
void print2()
{
    for(int i=0;i<m;i++)
    {
        cout<<refbit[jayga[i]]<<" ";
    }
    cout<<endl;
}

void t2()
{
    cout<<"sre:     ";
    for(auto x:s) cout<<x<<" ";cout<<endl;
}

void t()
{
    vector<pair<ll,ll> >   v;
    cout<<"pre:"<<endl<<endl;
    while(!pq.empty())
    {
        v.push_back(pq.top());
        cout<<pq.top().first<<" "<<jayga[pq.top().second]<<endl;
        pq.pop();
    }
    cout<<endl<<endl;
    for(ll i=0;i<v.size();i++)
    {
        pq.push(v[i]);
    }
}
int main()
{
    cin>>m;
    cin>>n;
    ll prev=-2;
    jayga.assign(m+1,-1);
    ll idx=0,faults=0;
    for(ll i=1;i<=n;i++)
    {
        ll val;cin>>val;
       // t2();
        if(s.find(val)==s.end())
        {
            if(s.size()<m)
            {
                //deb(jayga[idx]);
                jayga[idx]=val;
                idx++;

            }
            else
            {
                Clear();
                for(ll j=0;j<m;j++)
                {
                    //deb(jayga[j]);deb(prothomashche[jayga[j]]);
                    //if(jayga[j]==prev) { pq.push({1e9,j});}
                    pq.push({-prothomashche[jayga[j]],j});
                }
                //t();
                while(!pq.empty())
                {
                    ll pos=pq.top().second;
                    ll val2=jayga[pos];
                    //deb(val2);
                    //deb(pos);deb(val2);cout<<"\n";
                    if(refbit[val2]==0 && prev!=val2)
                    {
                        ll baad = jayga[pos];
                        jayga[pos]=val;
                        s.erase(baad);
                        break;

                    }
                    else
                    {
                        refbit[val2]=0;
                    }
                    pq.pop();
                }

            }
            faults++;

        }
        else
        {
            refbit[val]=1;

        }




        if(prothomashche[val]==0) prothomashche[val]=i;
        s.insert(val);
        print(i,val);
        //print2();
        prev=val;
    }
    cout<<"Faults="<<faults<<endl;
    return 0;
}
/*
3
12
2 3 2 1 5 2 4 5 3 2 5 2
*/
