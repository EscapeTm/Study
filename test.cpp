#include <stdio.h>
#include <algorithm>

using namespace std;

int dx[4]={1,0,-1,0}
int dy[4]={0,1,0,-1}

int main()
{
    int N;
    int mat[102][102];
    scanf("%d", &N);
    for(int i=0;i<N+2;i++)
    {
        for(int j=0;j<N+2;j++)
        {
            if(i==0||i==N+1||j==0||j==N+1)
                mat[i][j]=-1;
            else
                mat[i][j]=0;
        }
    }
    int K;
    scanf("%d", &K);
    for(int i=0;i<K;i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        mat[a][b]=2;
    }
    int L;
    scanf("%d", &L);
    int x=1;
    int y=1;
    int d=0;
    int ans=0;
    mat[x][y]=1;
    for(int i=0;i<L;i++)
    {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        for(int j=0;j<a;j++)
        {
            x+=dx[d];
            y+=dy[d];    
            ans++;
            if(mat[x][y]==-1)
            {
                goto A;   
            }
            else if(mat[x][y]==0)
            {
                mat[x][y]=1;
                mat[x-dx[d]][y-dy[d]]=0;
            }
            else if(mat[x][y]==2)
            {
                mat[x][y]=1;
            }
        }
        if(b=='L')
        {
            d-=1;
            if(d==-1)
                d=3;
        }
        else if(b=='D')
        {
            d+=1;
            if(d==4)
                d=0;
        }
    }
    A:
    printf("%d\n", ans);
}