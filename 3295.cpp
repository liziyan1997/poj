#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

stack<int> op_number;

const char MAX_CODE = 0x1F;

const char P_MASK = 0x01;
const char Q_MASK = 0x02;
const char R_MASK = 0x04;
const char S_MASK = 0x08;
const char T_MASK = 0x10;

#define K(a,b)  ((a) && (b));   //and
#define A(a,b)  ((a) || (b));   //or
#define N(a)    (!(a));         //not
#define C(a,b)  (!(a) || (b));  //imply
#define E(a,b)  ((a) == (b));   //equal

int toVal(char c,char code){
    int val;
    switch(c){
        case 'p':{val = ((code & P_MASK) == 0?0:1); break;}
        case 'q':{val = ((code & Q_MASK) == 0?0:1); break;}
        case 'r':{val = ((code & R_MASK) == 0?0:1); break;}
        case 's':{val = ((code & S_MASK) == 0?0:1); break;}
        case 't':{val = ((code & T_MASK) == 0?0:1); break;}
        default:{val = -1;}// printf("wrong val!\n");
    }
    return val;
}

int get_top(){
    int top = op_number.top();
    op_number.pop();
    return top;
}

bool solve(char* wff,int len,char code){
    for(int i=len-1;i>=0;i--){
        if(wff[i] == 'p' || wff[i] == 'q' || wff[i] == 'r' || wff[i] == 's' || wff[i] == 't' ){
            int val = toVal(wff[i],code);
            op_number.push(val);
        }
        else{
            if(wff[i] == 'N'){
                int a = get_top();
                a = N(a);
                op_number.push(a);
            }
            else{
                int a = get_top();
                int b = get_top();
                int ans;
                if(wff[i] == 'K')   ans = K(a,b);
                if(wff[i] == 'A')   ans = A(a,b);
                if(wff[i] == 'C')   ans = C(a,b);
                if(wff[i] == 'E')   ans = E(a,b);
                
                op_number.push(ans);
            }
        }
    }
    // cout << hex << (int)code << ' ';
    // cout << op_number.top() << endl;
    return (op_number.size() == 1 && get_top() == 1);
} 

int main(){
    char wff[101];
    while(cin >> wff && wff[0]!='0'){
        bool is_solve = true;
        for(char code=0;code <= MAX_CODE;code++){
            op_number.empty();
            is_solve = solve(wff,strlen(wff),code);
            if(!is_solve){
                break;
            }
        }
        cout << (is_solve?"tautology":"not") << endl;
    }
    return 0;
}



