#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;

struct Interval{
    double left;
    double right;
};

bool compare(Interval a,Interval b){
    return a.right <= b.right;
}

int solve(Interval* intervals,int size){
    sort(intervals,intervals+size,compare);
    double right = intervals[0].right;
    int radar = 1;
    for(int i=1;i<size;i++){
        if(intervals[i].left > right){
            right = intervals[i].right;
            radar++;
        }
    }
    return radar;
}

int main(){
    int kase=0,n,d;
    bool if_solve;
    double x,y;
    while(scanf("%d %d",&n,&d) && n!=0){
        if_solve = true;
        if(d <= 0){
            if_solve = false;
            // continue;
        }
        double d2 = d * d; 
        Interval* intervals = new Interval[n];
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            if(y > d || y < 0){
                if_solve = false;
            }
            double offset = sqrt(max(0.0,d2-y*y));
            intervals[i].left = x-offset;
            intervals[i].right = x+offset;
        }
        if(if_solve){
            int radar = solve(intervals,n);
            printf("Case %d: %d\n",++kase,radar);
            // cout << "Case "<<++kase<<": "<<radar<<endl;
        }
        else{
            printf("Case %d: -1\n",++kase);
            // cout << "Case "<<++kase<<": -1"<<endl;
        }
        delete[] intervals;
    }
    return 0;
}

