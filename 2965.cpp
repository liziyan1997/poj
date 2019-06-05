#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<stack>

using namespace std;

int f[5][5];
int step;
bool flag=false;
int t1[20];
int t2[20];

void change(int x,int y){
    for(int y_=1;y_<5;y_++){
        f[x][y_] = f[x][y_]==1 ? 0 : 1;
    }
    for(int x_=1;x_<5;x_++){
        f[x_][y] = f[x_][y]==1 ? 0 : 1;
    }
    f[x][y] = f[x][y]==1 ? 0 : 1;
}

bool is_finish(){
    for(int x=1;x<5;x++){
        for(int y=1;y<5;y++){
            if(f[x][y]==0)
                return false;
        }
    }
    return true;
}

void DFS(int depth,int x,int y){
    if(depth==step){
        flag = is_finish();
        return;
    }
    if(x==5 || flag){
        return;
    }
    change(x,y);
    t1[depth] = x;
    t2[depth] = y;
    if(y<4){
        DFS(depth+1,x,y+1);
    }
    else{
        DFS(depth+1,x+1,1);
    }
    change(x,y);

    if(y<4){
        DFS(depth,x,y+1);
    }
    else{
        DFS(depth,x+1,1);
    }
    return;
}

int main(){
    char c;
    for(int x=1;x<5;x++){
        for(int y=1;y<5;y++){
            cin >> c;
            f[x][y] = c=='+'? 0 : 1;
        }
    }
    for(step=1;step<=16;step++){
        DFS(0,1,1);
        if(flag)
            break;
    }
    cout << step << endl;
    for(int i=0;i<step;i++){
        cout << t1[i] << ' ' << t2[i] << endl;
    }
    return 0;
}