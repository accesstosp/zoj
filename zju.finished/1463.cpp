// 1463.cpp
// 1. 空格合法
// 2. (), [] 处理时必须匹配
#include<iostream>
using namespace std;
enum {
    SIZ = 108,
};
struct Node {
    int val;
    int ref;
};
const char ans[4] = {'(','[',')',']'};
int num;
char input[120];
Node mat[SIZ][SIZ];

char find_str(char ch){
    if(ch == '('){
        return 0;
    } else if(ch == ')'){
        return 2;
    } else if(ch =='['){
        return 1;
    }
    return 3;
}
void conv(){
    num = 0;
    while(input[num]!='\n'){
        input[num] = find_str(input[num]);
        num++;
    }
    input[num] = -1;
}
void fun(){
    memset(mat, -1, sizeof(mat));
    int l, i, j, e, v;
    for(i = 0; i < num; i++){
        mat[i][i].val = 2;
        mat[i][i].ref = -1;
    }
    for(l = 1; l<num; l++){
    for(i=0; i+l<num; i++){
        e = i + l;
        mat[i][e].val = 2 + mat[i+1][e].val;
        mat[i][e].ref = -1;
        for(j=i+1;j<=e;j++){
            if(input[i] < input[j] && (input[j]%2 == input[i]%2)){ // promise they are brackets and ordered.
                v = 2;
                if(j != i+1){
                    v += mat[i+1][j-1].val;
                }
                if(j < e){
                    v += mat[j+1][e].val;
                }
                if(mat[i][e].val > v ){
                    mat[i][e].val = v;
                    mat[i][e].ref = j;
                }
            }
        }
    }
    }
}
void output(int s, int e){
    int p;
    if(mat[s][e].ref == -1){        
        p = input[s];
        p += (input[s]>=2)?-2:2;
        if(input[s] < p)
            printf("%c%c", ans[input[s]], ans[p]);
        else 
            printf("%c%c", ans[p], ans[input[s]]);
        if(s < e)
            output(s+1, e);
    } else {
        printf("%c", ans[input[s]]);
        if(mat[s][e].ref != s+1){
            output(s+1, mat[s][e].ref-1);
        }
        p = mat[s][e].ref;
        printf("%c", ans[input[p]]);
        if(p < e){
            output(p+1,e);
        }
    }
}

int main(){
    int tstcase;
    
    fgets(input, SIZ, stdin);
    tstcase = atoi(input);
    while(tstcase --){
        fgets(input, SIZ, stdin);
        fgets(input, SIZ, stdin);        
        conv();
        fun();
        if(num != 0)            
            output(0, num-1);
        printf("\n");
        if(tstcase){
            printf("\n");
        }
    }

    return 0;
}

