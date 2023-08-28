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
    vector<P> v(n);


    for(int i=0;i<n;i++)
    {
        cout<<"Burst time & process time of process no "<<i<<" is=";
        v[i].pid=i;
        cin>>v[i].btime;
        cin>>v[i].atime;

    }
    vector<int> vis(n+1,0);


    int nowtime=0;
    int shsh=0;


    while(1)
    {
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) f=1;
        }
        //deb(nowtime);
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

                int t2=(nowtime-v[idx].atime);
                int t1=(t2-v[idx].btime);
                vis[idx]=1;
                v[idx].wtime=t1;
                v[idx].ttime=t2;
                deb(t1;deb(t2);
                nowtime++;
            }
            else
            {
                v[idx].btime--;
                nowtime++;
            }

            /*
            int t1=nowtime-v[idx].atime;
            int t2=(nowtime+v[idx].btime)-v[idx].atime;
            vis[idx]=1;
            v[idx].wtime=t1;
            v[idx].ttime=t2;
            nowtime+=v[idx].btime;
            */


        }



    }

    double awt=0.0,att=0.0;

        for(int i=0;i<n;i++)
        {
            awt+=v[i].wtime;
            att+=v[i].ttime;

            cout<<"waiting & turnaround time for process no "<<i<<" is = "<<v[i].wtime<<" "<<v[i].ttime<<endl;
            //deb(v[i].wtime);deb(v[i].ttime);cout<<"\n";
        }
        awt/=(n*1.00);
        att/=(n*1.00);
        cout<<"AwT and  Att are:";
        cout<<awt<<" "<<att<<endl;


    //for(int i=0;i<n;i++)



    return 0;
}

