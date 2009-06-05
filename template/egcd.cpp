#include<iostream>
using namespace std;
enum {
    SIZ = 1,
};

int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// assume that a >= b
int egcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = egcd(b, a%b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int main(){
    int a, b, d, x, y;
    while(cin>>a>>b){
        d = egcd(a, b, x, y);
        printf("d = %d, x = %d, y = %d\n", d, x, y);
        printf("ax + by = %d\n", (a*x + b * y));
        printf("\n");
    }
    return 0;
}
