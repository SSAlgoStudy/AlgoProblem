#include <bits/stdc++.h>
using namespace std;
 
int path[16];
int n,ans;
void rec(int x, int y)
{
    for(int i=0;i<y;++i){
        if(path[i]==x || abs(x-path[i])==y-i)return;
    }
    if(y==n-1){
        ans++;
        return;
    }
    for(int i=0;i<n;++i){
        path[y+1]=i;
        rec(i,y+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        path[0]=i;
        rec(i,0);
    }
    printf("%d",ans);
}
