#include <bits/stdc++.h>
#define pii pair<int,int>
#define psi pair<int,pii>

using namespace std;

const int INF = 1e8;
const int MAXN = 1005;

pii dist[MAXN];
vector<psi> grafo[MAXN];

pii Suma(pii a,pii b){
    a.first += b.first;
    a.second += b.second;
    return a;
}

pii Dijkstra(int s,int t,int n){

    fill( dist , dist + n , pii(INF,INF) );
    priority_queue<psi, vector<psi>, greater<psi> > q;
    dist[s] = pii( 0 , 0 );
    q.push( psi( 0 , pii( 0 , s ) ) );

    while(!q.empty()){

        int u = q.top().second.second;
        pii d = pii( q.top().first , q.top().second.first );
        q.pop();

        if(d>dist[u]) continue;

        for(int i=0;i<grafo[u].size();i++){
            int v = grafo[u][i].first;
            pii d2 = grafo[u][i].second;

            if( Suma(d2 , dist[u]) < dist[v] ){
                dist[v] = Suma(dist[u] , d2);
                q.push( psi( dist[v].first , pii( dist[v].second , v ) ) );
            }
        }

    }

    return dist[t];
}

int main(){

    int n,m,s,t,a,b,c,d;

    scanf("%d %d %d %d",&n,&m,&s,&t);

    while(m--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        grafo[a].push_back( psi( b , pii( c - d , c ) ) );
        grafo[b].push_back( psi( a , pii( c - d , c ) ) );
    }

    pii res = Dijkstra( s , t , n );

    printf("%d %d\n",res.second,res.first);

    return 0;
}
