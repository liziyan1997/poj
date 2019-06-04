#include<iostream>
using namespace std;

int main(){
    float length;
    // cout << "hello\n";
    while(cin>>length && length > 0.0){
        int i=2;
        float sum=0.0;
        sum+=(1.0/i);
        while (sum < length){
            i++;
            sum+=(1.0/i);
            // cout << sum << endl;
        }
        cout << i-1 <<" card(s)" << endl;
        
    }
    return 0;
}