#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

int p[4][4];
int step,flag=0;

void reverse(int x,int y){
    if(p[x][y]==0)    
        p[x][y] = 1;
    else    
        p[x][y] = 0;
}

void flip(int x, int y){
    reverse(x,y);
    if(x-1>=0)  reverse(x-1,y);
    if(x+1<=3)  reverse(x+1,y);
    if(y-1>=0)  reverse(x,y-1);
    if(y+1<=3)  reverse(x,y+1);  
}

int is_finish(){
    int flag = 1;
    for(int x=0;x<4;x++)
        for(int y=0;y<4;y++)
            if(p[x][y]!=p[0][0])
                flag = 0;
    return flag;
}

void DFS(int depth,int x,int y){
    if(depth==step){
        flag = is_finish();
        return;
    }
    if(flag || x==4)
        return;

    flip(x,y);
    if(y<3)
        DFS(depth+1,x,y+1);
    else
        DFS(depth+1,x+1,0);
    flip(x,y);

    if(y<3)
        DFS(depth,x,y+1);
    else
        DFS(depth,x+1,0);
    
    return;
}

int main(){
    char c;
    for(int i=0;i<16;i++){
        cin >> c;
        p[i/4][i%4] = c=='b'?0:1;
    }
    for(step=0;step<=16;step++){
        DFS(0,0,0);
        if(flag)    
            break;
    }
    if(flag)
        cout << step << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}


