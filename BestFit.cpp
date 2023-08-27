#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
const ll NN=1000;
const ll INF=1e9;
ll hole,need;
ll Hole[NN];
ll Need[NN];
vector< vector<ll> > arr(NN+10,vll(NN+10,0));
ll sum=0;
ll i,j,k,shsh=-1;
bool hobena=0;
//hole=5,need=10

void Space(ll val)
{
    if(val>=0 && val<10) cout<<"  ";
    else if(val>=10 && val<100) cout<<" ";
    else cout<<"";
}

void Spacex(ll n)
{
    for(ll i=0;i<n;i++)
    {
        cout<<" ";
    }
}

void HoleInput()
{
    cout<<"Holes are: ";
    for(ll i =0 ; i<hole; i++)
    {
        cin>>Hole[i];
        arr[i][0]=Hole[i];
    }
}


void NeedInput()
{
    cout<<"Need Space in Memory: ";
    for(ll i =0 ; i<need; i++)
    {
        cin>>Need[i];

    }
}

void AssignFirstColumn()
{
    for(ll i=0;i<hole;i++)
    {
        arr[0][i]=Hole[i];
    }
}
void FullNeedPrint()
{
    //cout<<"\t";
    Spacex(4);
    for(ll i=0;i<need;i++)
    {
        Space(Need[i]);
        cout<<Need[i]<<" ";
    }
    cout<<endl;
}

void BestFitChoice()
{
     for(ll i=0; i<need; i++)
    {
        ll minval=INF;
        ll pos=-1;
        for(ll j = 0; j<hole; j++)
        {
            if((Need[i]<= Hole[j]) && (Hole[j]<minval))
            {
                    minval=Hole[j];pos=j;
            }

        }
        if(pos==-1)
        {
            shsh = i+1;
            hobena=1;
            break;
        }

        Hole[pos]-=Need[i];
        for(ll j = 0; j<hole; j++)
        {
            arr[j][i+1]=Hole[j];
        }
    }
}


void PrintColWise()
{
    for(ll i=0; i<hole; i++)
    {
        for(ll j=0; j<shsh; j++)
        {
            Space(arr[i][j]);
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void NotAllocated()
{
    cout<<Need[shsh-1]<<" can't be allocated"<<endl;
    for(ll i =0; i<hole; i++)
    {
        sum+=Hole[i];
    }
    cout<<"External Fragmentation: "<<sum<<endl;
}

void Allocated()
{
    cout<<"No external Fragmentation"<<endl;
}

int main()
{
    cout<<"Total hole && total request are: ";
    cin>>hole>>need;
    shsh=need+1;
    HoleInput();
    NeedInput();
    AssignFirstColumn();
    BestFitChoice();
    cout<<"For Best Fit:\n";
    FullNeedPrint();
    PrintColWise();
    if(hobena)
    {
        NotAllocated();
    }
    else
    {
        Allocated();
    }
}

/*
5 10
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/


