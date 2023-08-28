#include<bits/stdc++.h>
#define deb(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long int ll;

map<ll,ll> blocks;
set<ll> ase;
map<string, ll> uniquenumber;
string filename;
ll filesize;
ll uni=1,vv=0;
ll bl,query;
void Print()
{
    for(ll i=0;i<=bl;i++) cout<<blocks[i]<<" ";
}


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
        ll r=0,rr=0;
        for(ll i=0;i<=bl;i++)
        {
            if(blocks[i]==value)
            {
                rr++;
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
        //cout<<"\t"<<rr<<endl;
    }

}


ll Range(ll left,ll right,ll uniquenum)
{
    for(ll i=left;i<=right;i++)
    {
        if(blocks[i]==0)
        {
            blocks[i]=uniquenum;
            vv++;
            return i;
        }
    }
    return -1;
}

void AllocateBlocks(string &s,ll sizere)
{

    ll temp=sizere;
    ll c=0,jayga=0;
    for(ll i=0;i<=bl;i++)
    {
        if(blocks[i]==0) jayga++;
    }
    if(sizere>jayga)
    {
        cout<<"File "<<s<<" cannot be created(not enough free blocks) \n";
    }
    else
    {
        uniquenumber[s]=uni;

        for(ll j=bl/2;j>=1;j--)
        {
             if(temp==0) break;
             for(ll i=0;i<bl+1;i+=j)
             {
                 ll idx=Range(i,min(i+j-1,bl),uni);
                 //deb(idx);deb(temp);
                 if(idx!=-1) temp--;
                 else continue;

                 if(temp==0) break;
             }
             if(temp==0) break;
        }
        for(ll j=bl+1;j>=1;j--)
        {
             if(temp==0) break;
             for(ll i=0;i<bl+1;i+=j)
             {
                 ll idx=Range(i,min(i+j-1,bl),uni);
                 //deb(idx);deb(temp);
                 if(idx!=-1) temp--;
                 else continue;

                 if(temp==0) break;
             }
             if(temp==0) break;
        }

        cout<<"File "<<s<<" is created\n";
        ase.insert(uni);
        uni++;
        //deb(vv);
        //vv=0;

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
            //Print();
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
C
2
D




*/

