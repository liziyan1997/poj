#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int inf = 0x7FFFFFF;

int M,N;
int dis[101];           //买一件物品的价钱
int price[101][101];    //从a到b的优惠价钱
int L[101];          //物品主人等级
int X[101];    

void input(){
    memset(dis,0x3F,sizeof(dis));
    memset(price,0,sizeof(price));
    memset(L,0,sizeof(L));
    memset(X,0,sizeof(X));

    cin >> M >> N;
    int idx,p;
    for(int i=1;i<=N;i++){
        cin >> price[0][i] >> L[i] >> X[i];
        while (X[i]--){
            cin >>idx >> p;
            price[idx][i] = p;
        }
    }
}

bool is_trade(int lv_min,int lv_max,int lv){
    if(lv_min<=lv && lv<=lv_max)
        return true;
    return false;
}


void spfa(int lv_min,int lv_max){
    memset(dis,0x3F,sizeof(dis));
    queue<int> q;
    bool flag[101];
    memset(flag,false,sizeof(flag));

    q.push(0);
    dis[0] = 0;
    flag[0] = 1;

    while (!q.empty()){
        int now = q.front();
        flag[now] = 0;
        q.pop();
        for(int i=1;i<=N;i++){
            if(is_trade(lv_min,lv_max,L[i]) && price[now][i] && dis[i] > dis[now] + price[now][i]){
                dis[i] = dis[now] + price[now][i];
                if(!flag[i]){
                    q.push(i);
                    flag[i] = 1;
                }
            }
        }
    }
}

int main(){
    input();
    int kinglv = L[1];                          //酋长等级必须包括在[i,i+M]的可交易范围内
    int mincost = inf;
    for(int d=kinglv-M;d<=kinglv;d++){
        spfa(d,d+M);
        if(dis[1]<mincost)
            mincost = dis[1];
    }
    cout << mincost << endl;
    return 0;
}





