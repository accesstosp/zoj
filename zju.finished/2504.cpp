
#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 1008,
};
map<int, int> tab[SIZ];
map<int, int>::iterator it;
int num, src, dest, edge;
int dis[SIZ];
int mark[SIZ];

int path(){
    int cur, nex;
    int t;
    int p = 0;
    int flag = 1;
    scanf("%d%d",&t,&cur);
    src = nex = cur;
    for(int i=1; i<t; i++){
        scanf("%d", &nex);
        if(i==1){   src = nex;}
        it = tab[cur].find(nex);
        if(it == tab[cur].end()){
            flag = 0;
        } else {
            p += it->second;
        }
        cur = nex;
    }
    if(flag == 0)
        return -1;
    dest = nex;
    return p;
}

int find_min(){
    int t = -1;
    for(int i=1; i<=num; i++){
        if(mark[i] == 0|| dis[i] == -1)
            continue;
        if(t == -1 || dis[i] < dis[t]){
            t = i;
        }
    }
    mark[t] = 0;
    return t;
}
void update(int cur){
    int t;
    for(it=tab[cur].begin(); it!=tab[cur].end(); it++){
        if(mark[it->first] == 0)
            continue;
        t = dis[cur] + it->second;
        if(dis[it->first]==-1 || dis[it->first] > t){
            dis[it->first] = t;
        }
    }
}
int sp(){
    memset(dis, -1, sizeof(int)*(num+2));
    memset(mark, -1, sizeof(int)*(num+2));
    dis[1]  = 0;
    mark[1] = 0;
    if(src == 1) return 0;
    
    it = tab[1].find(src);
    dis[src] = it->second;
    while(1){
        int cur = find_min();
        if(cur == dest){
            return dis[dest];
        }
        update(cur);
    }
    return 0;
}

void fun(){
    int a = path();
    if(a == -1){
        printf("N\n");
        return;
    }
    int b = sp();
    a -= b;
    printf("Y %d\n", a);
}

void readIn(){
    scanf("%d%d",&num,&edge);
    for(int i=1; i<=num; i++){
        tab[i].clear();
    }
    int a, b, c;
    for(int i=0; i<edge; i++){
        scanf("%d%d%d",&a,&b,&c);
        
        // bidirectional
        it = tab[a].find(b);
        if(it == tab[a].end()){
            tab[a].insert(make_pair(b,c));
        } else if(it->second > c){
            it->second = c;
        }
        
        it = tab[b].find(a);
        if(it == tab[b].end()){
            tab[b].insert(make_pair(a,c));
        } else if(it->second > c){
            it->second = c;
        }
    }
}

int main(){
    int tstcase, tstnum = 0;
    scanf("%d",&tstcase);
    while(tstnum++ < tstcase){
        readIn();
        printf("TEST %d ", tstnum);
        fun();
    }

    return 0;
}

/*
有一个重要条件没说，就是最短路径中经过的第二个点必须和固定路线中经过的第二个点相同
*/