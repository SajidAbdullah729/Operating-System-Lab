/*
Author: Mohammad Abdullah-Al-Sajid Chowdhury
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
list<ll> v;
ll totframe;
ll n;
void print()
{
    int c=0;
    for(auto x:v)
    {
        cout<<x<<" ";
        c++;
    }
    for(ll i=c;i<totframe;i++) cout<<"Empty ";
    cout<<endl;
}

int main()
{

    cout<<"Total Frame=";
    cin>>totframe;
    cout<<"Total Page Request: ";
    cin>>n;
    cout<<"Requests are = \n";
    int faults=0;
    for(ll i=0;i<n;i++)
    {
        ll val;cin>>val;
        auto it=find(v.begin(),v.end(),val);
        if(it!=v.end())
        {
            v.erase(it);
            v.push_front(val);
            faults++;
        }
        else
        {
            if(v.size()<totframe)
            {
                v.push_front(val);
            }
            else
            {
                v.pop_back();
                v.push_front(val);
            }


        }
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

        print();

    }
    cout<<"Total Faults = "<<faults<<endl;

    return 0;
}
/*
 3
 22
 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
*/
