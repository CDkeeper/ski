#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=305;
int h[N][N],f[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int dp(int x,int y){
    int &v=f[x][y];
    if(v!=-1) return v;
        v=1;
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a>0&&a<=n&&b>0&&b<=m&&h[x][y]>h[a][b]){
            v=max(v,dp(a,b)+1);
        }
    }
    return v;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        scanf("%d",&h[i][j]);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
         res=max(res,dp(i,j));
    }
    printf("%d",res);
    return 0;
}
