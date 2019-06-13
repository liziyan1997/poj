#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char dic[10001][16];
char ans[100][16];
int ans_idx;    //可修补的词数

void replace_word(char* a,char *b){
    int diff = 0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]!=b[i]){
            diff++;
        }
    }
    if(diff==1){
        strcpy(ans[ans_idx++],b);
    }
    return;
}

void delete_word(char* a, char* b){
    bool solve = true;
    int i=0;
    for(;i<strlen(b);i++){
        if(a[i]!=b[i]){
            break;
        }
    }
    for(;i<strlen(b);i++){
        if(a[i+1]!=b[i]){
            solve = false;
        }
    }
    if(solve){
        strcpy(ans[ans_idx++],b);
    }
    return;
}

void insert_word(char* a,char* b){
    bool solve = true;
    int i=0;
    for(;i<strlen(a);i++){
        if(a[i]!=b[i]){
            break;
        }
    }
    for(;i<strlen(a);i++){
        if(a[i]!=b[i+1]){
            solve = false;
        }
    }
    if(solve){
        strcpy(ans[ans_idx++],b);
    }
    return;
}



int main(){
    int word_num;
    for(word_num=0;word_num<10001;word_num++){
        scanf("%s",dic[word_num]);
        if(dic[word_num][0] == '#'){
            break;
        }
    }
    char word[16];
    while(scanf("%s",word) && word[0]!='#'){
        ans_idx = 0;
        memset(ans,'\0',sizeof(ans));
        for(int i=0;i<word_num;i++){
            if(strcmp(word,dic[i])==0){
                ans_idx = -1;
                break;
            }
            else{
                int diff = strlen(word) - strlen(dic[i]);
                switch(diff){
                    case 0: {replace_word(word,dic[i]);break;}
                    case 1: {delete_word(word,dic[i]);break;}
                    case -1:{insert_word(word,dic[i]);break;}
                    default:break;
                }

            }
        }
        if(ans_idx>=0){
            cout << word << ": ";
            for(int i=0;i<ans_idx;i++)
                cout << ans[i] << ' ';
            cout << endl;
        }
        else{
            printf("%s is correct\n",word);
        }
    }
    return 0;
}
