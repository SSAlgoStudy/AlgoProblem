#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct Info
{
    int height[102][102];
    int n;
    bool h[101];
    int maxNum;
    const int dr[4] = {-1,1,0,0};
    const int dc[4] = {0,0,-1,1};
    typedef struct Cod{int r,c;} cod;
    void init()
    {
        cin >> n;
        maxNum = 1;
        memset(h,false,sizeof(h));
        memset(height,-1,sizeof(height));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> height[i][j];
                h[height[i][j]] = true;
            }
        }
    }

    int getArea(int h)
    {
        cod now, next;
        queue<cod> que;

        int num = 0;
        bool visit[102][102] = {false};
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(!visit[i][j] && height[i][j] > h)
                {
                    visit[i][j] = true;
                    num++;
                    now.r = i; now.c = j;
                    que.push(now);
                    
                    while(que.size())
                    {
                        now = que.front();
                        que.pop();

                        for(int d = 0; d < 4; d++)
                        {
                            next.r = now.r + dr[d];
                            next.c = now.c + dc[d];

                            if(!visit[next.r][next.c] && height[next.r][next.c] > h)
                            {
                                visit[next.r][next.c] = true;
                                que.push(next);
                            }
                        }
                    }
                }
            }
        }
        return num;
    }

    int getMaxSafeArea()
    {
       
        int num, maxNum = 1;

        for(int i = 1; i <= 100; i++)
        {
            if(h[i])
            {
                num = getArea(i);
                maxNum = num > maxNum ? num : maxNum;
            }
        }

        return maxNum;
    }
} info;

int main(){
    info.init();
    cout << info.getMaxSafeArea() << '\n';
}