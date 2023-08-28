#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll> blocks;
set<ll> ase;
map<string, ll> uniquenumber;
string filename;
ll filesize;
ll uni=1;


ll bl,query;
void Fun()
{
    cout<<"To Choice Press 1 \nTo Allocate Choice 2 \n";
}

void FileSearch(string &s)
{
    ll value=uniquenumber[s];
    if(ase.find(value)==ase.end())
    {
        cout<<"File Not Found"<<endl;
    }
    else
    {
        cout<<"Files found in the blocks : ";
        ll r=0;
        for(ll i=0;i<=bl;i++)
        {
            if(blocks[i]==value)
            {
               if(r==0)
               {
                   cout<<i;
                   r++;
                   continue;
               }
               else
               {
                   cout<<" , "<<i;
                   r++;
               }
            }
        }
        cout<<endl;
    }

}

void AllocateBlocks(string &s,ll sizere)
{

    ll c=0,idx=-1;
    for(ll i=0;i<=bl;i++)
    {
        if(blocks[i]==0)
        {
           c++;
           if(c==sizere)
           {
               idx=i;
           }
        }
        else
        {
            c=0;
        }
    }
    if(idx==-1)
    {
        cout<<"File "<<s<<" cannot be created(not enough free blocks) \n";
    }
    else
    {
        uniquenumber[s]=uni;
        for(ll i=idx;i>=idx-sizere+1;i--)
        {
             blocks[i]=uni;
        }
        cout<<"File "<<s<<" is created\n";
        ase.insert(uni);
        uni++;
    }
}

int main()
{
    cout<<"Enter Total No of Blocks: ";cin>>bl;
    cout<<"Total Query: ";
    cin>>query;
    Fun();

    for(ll i=0;i<query;i++)
    {
        cout<<"Choice : ";
        ll ch;cin>>ch;
        if(ch==1)
        {
            cout<<"Enter File Name: ";
            cin>>filename;
            cout<<"Enter File Size: ";
            cin>>filesize;
            AllocateBlocks(filename,filesize);
        }
        else
        {
            cout<<"Search File Name: ";
            cin>>filename;
            FileSearch(filename);
        }
    }


    return 0;
}
/*
200
5
1
A
4
1
B
400
1
C
40
2
A
2
D




*/
