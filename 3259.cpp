#include<iostream>
#include<string.h>
using namespace std;
 
int dis[1001];      //源点到各点权值
const int max_w=10001;      //无穷远


class weight{
    public:
        int s;
        int e;
        int t;
}edge[5200];

int N,M,W;      // N：顶点数  M:正权双向边 W:负权单向边

int edge_num;

bool bellman(){
    bool flag;   //判断本次迭代是否有更新

    for(int i=0;i<N-1;i++){ //最多N-1次迭代
        flag = false;
        for(int j=0;j<edge_num;j++){
            if(dis[edge[j].e]>dis[edge[j].s]+edge[j].t){
                dis[edge[j].e] = dis[edge[j].s] + edge[j].t;
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }

    for(int k=0;k<edge_num;k++)     //检测是否有负权圈，有则符合题意
        if( dis[edge[k].e] > dis[edge[k].s] + edge[k].t)
            return true;

    return false;
}

int main(){
    int u,v,w,F;
    cin >> F;
    while(F--){
        cin >> N >> M >> W;
        edge_num = 0;
        for(int i=1;i<=M;i++){
            cin>>u>>v>>w;
            edge[edge_num].s=edge[edge_num+1].e=u;
            edge[edge_num].e=edge[edge_num+1].s=v;
            edge[edge_num++].t=w;
            edge[edge_num++].t=w;               //由于paths的双向性，两个方向权值相等，注意指针的移动
        }

        for(int j=1;j<=W;j++){
            cin>>u>>v>>w;
            edge[edge_num].s=u;
            edge[edge_num].e=v;
            edge[edge_num++].t=-w;     //注意权值为负
        }

        memset(dis,max_w,sizeof(dis));
		/*Bellman-Ford Algorithm*/
 
        if(bellman())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	}
	return 0;
}
