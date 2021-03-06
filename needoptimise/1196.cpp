#include<iostream>
#include<map>


//本题很难，在确认后才能放到完成程序中 
using namespace std;
enum {
    SIZ = 204,
};
int N,K;
int cost[SIZ][SIZ];
int dis[SIZ];
map<int,int> tab;
map<int,int>::iterator iter;

int compute(int a, int b){
    int mid = (a+b)/2;
    int ret = 0,t;
    for(int i=a;i<=b;i++){
        t = dis[i] - dis[mid];
        if(t < 0)
            t = -t;
        ret += t;
    }
    return ret;
}
int calc(int n, int k){
    int key = (n<<8) + k;
    iter = tab.find(key);
    if(iter != tab.end()){
        return iter->second;
    }
    if(k==1){
        return cost[0][n];
    }
    int cur,save = 99999999;
    for(int i=n;i>=k-1;i--){
        cur = calc(i-1,k-1) + cost[i][n];
        if(cur < save)
            save = cur;
    }
    return tab[key] = save;
}

int fun(){
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            cost[i][j] = compute(i,j);
        }
    }
    tab.clear();
    return calc(N-1,K);
}

int main(){
    int tstcase = 0;
    cin>>N>>K;
    while(N){
        cout<<"Chain "<<++tstcase
            <<"\nTotal distance sum = ";
        for(int i=0;i<N;i++){
            cin>>dis[i];
        }
        cout<<fun() <<endl<<endl;

        cin>>N>>K;
    }

	return 0;
}


/*
zoj1196_Fast Food

zju1196_Fast Food 瑙ｄ綋鎶ュ憡

璇戦锛歾ju 1196 fast food 淇粨搴�

鏈変竴涓叕鍙�,鍦ㄤ竴鏉¤涓婃湁N涓揩椁愬簵,鍏徃鍐冲畾淇甂涓粨搴撲互婊¤冻杩欎簺蹇鐢电殑鍘熸枡闇�姹�.

鐜板湪缁欏嚭N涓揩椁愬簵鐨勬í鍧愭爣(浠栦滑閮藉湪涓�鏉＄洿绾夸笂闈�),瑕佹眰淇甂涓粨搴�,浣垮緱鎵�鏈夌殑蹇搴楃鍏跺搴旂殑浠撳簱鐨勮窛绂绘渶鐭�.

鍏紡濡備笅:


1 <= n <= 200, 1 <= k <= 30, k <= n

Sample Input

6 3
5
6
12
19
20
27
0 0

Sample Output

Chain 1
Total distance sum = 8
姣忎釜杈撳嚭涔嬪悗鎵撲竴涓┖琛�

*********************************************************************************************************

鐩稿綋缁忓吀鐨勪竴閬撻銆傘��

璁� F[ i , j ] 琛ㄧず鍓� i  涓揩椁愬簵淇� j  涓粨搴撶殑鏈�灏� distant 锛�

鍒� F[ i , j ]=F[ k , j-1 ] + cost[ k+1 , i ]   { k>=j-1, k+1<=i}

鍏朵腑 Cost[ i, j ] 琛ㄧず绗� i  涓鍘呭埌绗� j 涓鍘呴棿鎻� 1 涓粨搴撶殑鏈�灏� distant锛� 绛変簬鎵�鏈夐鍘呭埌绗� (i+j+1)div 2  涓鍘呯殑distant 涔嬪拰銆�

1) F[i , 1] 鍒濆�煎嵆涓� Cost[ 1, i];

2) Cost[i , j] 鍙彁鍓嶇畻鍑轰互鍔犲揩鏁堢巼锛�

闄凙C浠ｇ爜锛�

program zju1196;

const maxnA=200;
      maxnB=30;
var f:array[1..maxnA,1..maxnB]of longint;
    cost:array[1..maxnA,1..maxnA]of longint;
    d:array[1..maxnA]of longint;
    i,j,p,n,k,index,tmp:longint;

function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;

function data(x,y:longint):longint;
var i,mid,sum:longint;
begin
  mid:=(x+y+1)div 2;
  sum:=0;
  for i:=x to y do
    sum:=sum+abs(d[i]-d[mid]);
  data:=sum;
end;

begin
  n:=1; k:=1; index:=0;
  while (n<>0)or(k<>0) do begin
    fillchar(f,sizeof(f),0);
    fillchar(cost,sizeof(cost),0);
    read(n,k);
    readln;
    if (n=0)and(k=0) then break;
    for i:=1 to n do readln(d[i]);
    for i:=1 to n-1 do
      for j:=i+1 to n do cost[i,j]:=data(i,j);
    for i:=1 to n do f[i,1]:=cost[1,i];
    for i:=1 to n do
      for j:=2 to k do
        if j<i then begin
          tmp:=maxlongint;
          for p:=j to i do tmp:=min(cost[p,i]+f[p-1,j-1],tmp);
          if tmp<maxlongint then f[i,j]:=tmp;
        end;
    inc(index);
    writeln('Chain ',index);
    writeln('Total distance sum = ',f[n,k]);
    writeln;
  end;
end.
*/
