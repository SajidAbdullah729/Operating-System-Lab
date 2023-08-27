/*
Author: Mohammad Abdullah-Al-Sajid Chowdhury
*/


#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll RR=100;
ll Need[RR][RR];
ll alloc[RR][RR];
ll MaxAlloc[RR][RR];
int main()
{
    ll resource,process;
    cout<<"Enter the number of processes: ";
    cin>>process;
    cout<<"Enter the number of resources: ";
    cin>>resource;
    vector<ll> Ase(resource+2,0);
    vector<ll> fin(process+2,0);
    vector<ll> ans;
    for(ll i=1; i<=process; i++)
    {
        cout<<" Process "<<i<<endl;
        for(ll j=1; j<=resource; j++)
        {
            cout<<"Maximum value for resource "<<j<<": ";
            cin>>MaxAlloc[i][j];
        }
        for(ll j=1; j<=resource; j++)
        {
            cout<<"Allocated from resource "<<j<<": ";
            cin>>alloc[i][j];
        }
        cout<<endl;
    }

    for(ll i=1; i<=resource; i++)
    {

        cout<<"Enter total value of resource "<<i+1<<": ";
        cin>>Ase[i];
    }
    for(ll i=1; i<=process; i++)
    {
        for(ll j=1;j<=resource; j++)
        {
            Ase[j]-=alloc[i][j];
        }

    }
    for (ll i=1; i<=process; i++)
    {
        for (ll j=1; j<=resource; j++)
        {
            Need[i][j] = MaxAlloc[i][j] - alloc[i][j];
        }
    }

    ll idx=0;
    for (ll k=1; k<=process; k++)
    {
        for (ll i = 1; i<=process; i++)
        {
            if (!fin[i])
            {

                bool f = 1;
                for (ll j = 1; j <=resource; j++)
                {
                    if (Need[i][j] > Ase[j])
                    {
                        f = 0;
                        break;
                    }
                }

                if (f)
                {
                    ans.push_back(i);
                    for (ll j = 1; j <= resource; j++)
                    {
                        Ase[j] += alloc[i][j];
                    }
                    fin[i] = 1;
                    break;


                }
            }
        }
    }

    bool hoise= 1;
    cout<<"\n";
    for(int i = 1; i<=process; i++)
    {
        if(!fin[i])
        {
            hoise = 0;
            cout<<"The System is unsafe";
            return 0;
        }
    }

    if(hoise)
    {
        cout<<"The System is currently in safe state and < ";
        for (ll i = 0; i < ans.size(); i++)
        {
            cout<<" P"<<ans[i]<<" ";
        }
        cout<<"> is the safe sequence"<<endl;

    }
    return (0);

}

/*
4
3
3 2 2
1 0 0
6 1 3
5 1 1
3 1 4
2 1 1
4 2 2
0 0 2
9 3 6
*/
