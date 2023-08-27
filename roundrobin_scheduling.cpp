#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<"="<<x<<endl
struct P
{
    int pid,atime,btime,ttime,wtime,baki;
};

bool cmp1(P x,P y)
{
    if(x.atime!=y.atime) return (x.atime<y.atime);
}

bool cmp2(P x, P y)
{
    if(x.pid!=y.pid ) return (x.pid<y.pid);
}


int main()
{

    int n,tq;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<P> p(n+1);
    cout<<"Enter time quantum: ";
    cin>>tq;
    cout<<"Enter CPU time : ";
    for(int i = 0; i < n; i++)
    {

        cin>>p[i+1].btime;

        p[i+1].pid = i+1;
        p[i+1].baki=p[i+1].btime;
        cout<<endl;

    }
    cout<<"Enter arrival time :";
    for(int i = 0; i < n; i++)
    {
        cin>>p[i+1].atime;


        cout<<endl;
    }

    sort(p.begin()+1,p.end(),cmp1);

    queue<int> q;
    int idx=0;
    q.push(1);




    vector<bool> vis(n+4,0);
    int nowtime=p[1].atime;
    while(!q.empty())
    {
        idx=q.front();

        q.pop();
        if(p[idx].baki==0) continue;
        int t=min(p[idx].baki,tq);
        int val1=nowtime;
        nowtime+=t;
        int val2=nowtime;
        p[idx].baki-=t;
        //cout<<"h:";deb(p[idx].pid);deb(nowtime);
        //deb(val1);
        for(int i=1;i<=n;i++)
        {

            if(p[i].atime>val1 && p[i].atime<=val2 && i!=idx)
            {
                q.push(i);
                //deb(p[i].pid);

            }
        }
        if(p[idx].baki==0)
        {
            //deb(nowtime);deb(p[idx].atime);deb(p[idx].pid);
            p[idx].ttime=(nowtime-p[idx].atime);
            p[idx].wtime=(p[idx].ttime-p[idx].btime);
            vis[idx]=1;
        }
        else
        {
            q.push(idx);
        }







    }

    sort(p.begin()+1,p.end(),cmp2);
    double avgwtime=0.0,avgttime=0.0;
    for(int i=1;i<=n;i++)
    {
        cout<<"Process "<<i<<" Waiting time="<<p[i].wtime<<" TurnAround time="<<p[i].ttime<<endl;
        avgwtime+=(p[i].wtime);
        avgttime+=p[i].ttime;
    }
    avgttime/=n;
    avgwtime/=n;
    cout<<"Average Waiting time = "<<avgwtime<<endl;
    cout<<"Average TurnAround time = "<<avgttime<<endl;

    return 0;
}
/*
4
3
5 7 9 9
4 0 6 10


*/
