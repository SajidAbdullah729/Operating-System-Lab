#include<bits/stdc++.h>
#define deb(x) cout<<#x<<"="<<x<<endl
using namespace std;

struct P
{
    int pid,btime,atime,wtime,ttime;
};




int main()
{
    cout<<"total process: ";
    int n;cin>>n;
    vector<P> v(n),v1;


    for(int i=0;i<n;i++)
    {
        cout<<"Burst time & process time of process no "<<i<<" is=";
        v[i].pid=i;
        cin>>v[i].btime;
        cin>>v[i].atime;

    }
    vector<int> vis(n+1,0);
    v1=v;

    int nowtime=0;
    int shsh=0;


    while(1)
    {
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) f=1;
        }

        if(!f) break;

        vector<P> temp;

        for(int i=0;i<n;i++)
        {
            if(v[i].atime<=nowtime && !vis[v[i].pid])
            {
                temp.push_back(v[i]);
            }
        }

        if(temp.size()==0) nowtime++;
        else
        {
            int minn=1e9,idx=-1;
            for(int i=0;i<temp.size();i++)
            {
                 if(temp[i].btime<minn)
                 {
                     minn=temp[i].btime;
                     idx=temp[i].pid;
                 }
            }
            if(v[idx].btime==0)
            {

                int t2=(nowtime-v1[idx].atime);
                int t1=(t2-v1[idx].btime);
                vis[idx]=1;
                v[idx].wtime=t1;
                v[idx].ttime=t2;

            }
            else
            {
                v[idx].btime--;

                nowtime++;
            }




        }



    }

    double awt=0.0,att=0.0;

        for(int i=0;i<n;i++)
        {
            awt+=v[i].wtime;
            att+=v[i].ttime;

            cout<<"waiting & turnaround time for process no "<<v[i].pid<<" is = "<<v[i].wtime<<" "<<v[i].ttime<<endl;
            //deb(v[i].wtime);deb(v[i].ttime);cout<<"\n";
        }
        awt/=(n*1.00);
        att/=(n*1.00);
        cout<<"AwT and  Att are:";
        cout<<awt<<" "<<att<<endl;


    //for(int i=0;i<n;i++)



    return 0;
}

/*
5
6 2
2 5
8 1
3 0
4 4

*/
