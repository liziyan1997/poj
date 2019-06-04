#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[260];
    while(cin.getline(s,260) && s[0]!='#'){
        int length = strlen(s);
        int sum = 0;
        for(int i=0;i<length;i++){
            if(s[i]!=' '){
                sum+=(s[i]-'A'+1) * (i+1);
            }
        }
        cout << sum << endl;
    }
    return 0;
}