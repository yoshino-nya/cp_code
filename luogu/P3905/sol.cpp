
#if defined(LOCAL)
#include<D:/template/yuanshen.hpp>
#else
#include<bits/stdc++.h>
#define dbg(...) 42
#endif
#define INF 1e18
#define pb push_back
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<ll> u(m),v(m),k(m);
    vector<vector<int>> check(1000,vector<int> (1000,0));
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>k[i];
        u[i]--,v[i]--;
    }
    int D;
    cin>>D;
    vector<ll> U(D),V(D);
    for(int i=0;i<D;i++){
        cin>>U[i]>>V[i];
        U[i]--,V[i]--;
        check[U[i]][V[i]]=1;
        check[V[i]][U[i]]=1;
    }
    int s,z;
    cin>>s>>z;
    s--,z--;
    vector<vector<pair<ll,ll>>> table(n);
    for(int i=0;i<m;i++){
        if(check[u[i]][v[i]]==1){
            dbg(u[i],v[i]);
            table[u[i]].pb({v[i],k[i]});
            table[v[i]].pb({u[i],k[i]});
        }
        else{
            table[u[i]].pb({v[i],0});
            table[v[i]].pb({u[i],0});
        }
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    vector<ll> dist(n,1e18);
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty()){
        auto [dis,point]=pq.top();
        pq.pop();
        if(dis>dist[point]) continue;
        for(auto x:table[point]){
            ll new_point=x.first;
            ll new_dis=x.second+dist[point];
            if(new_dis<dist[new_point]){
                dist[new_point]=new_dis;
                pq.push({dist[new_point],new_point});
            }
        }
    }
    cout<<dist[z]<<endl;
    return 0;
    return 0;
}