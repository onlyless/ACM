#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 105;
struct city
{
    int end,len,val;
    city(int a,int b,int c):end(a),len(b),val(c){}
};
struct node
{
    int beg,dis,val;
    node(int a,int b,int c):beg(a),dis(b),val(c){}
    bool operator <(const node& a)const
    {
        if(this->dis!=a.dis)return this->dis>a.dis;
        else return this->val<a.val;
    }
};
int d[maxn];
int K,N,R;
vector<city> g[maxn];
int bfs()
{
    priority_queue<node> Q;
    Q.push(node(1,0,K));
    while(!Q.empty()){
        node temp = Q.top();
        Q.pop();
        if(temp.beg==N)return temp.dis;
        for(int i=0;i<g[temp.beg].size();i++){
            city te = g[temp.beg][i];
            if(temp.val<te.val)continue;
            Q.push(node(te.end,te.len+temp.dis,temp.val-te.val));
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d",&K,&N,&R);
    for(int i=0;i<R;i++){
        int S,D,L,T;
        scanf("%d%d%d%d",&S,&D,&L,&T);
        g[S].push_back(city(D,L,T));
    }
    printf("%d\n",bfs());
    return 0;
}
