#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Info{
    typedef struct Cod{int r,c;} cod;
    int map[1002][1002];
    int m,n;
    
    queue<cod> box;

    void init()
    {
        memset(map,-1,sizeof(map));

        cin >> m >> n;
        cod pos;
        for(int r = 1; r <= n; r++)
        {
            for(int c = 1; c <= m; c++)
            {
                cin >> map[r][c];
                pos.r = r;
                pos.c = c;
                if(map[r][c] == 1) box.push(pos);
            }
        }
    }
    bool check()
    {
        for(int r = 1; r <= n; r++)
        {
            for(int c = 1; c <= m; c++)
            {
                if(map[r][c] == 0) return false;
            }
        }
        return true;
    }

    const int dr[4] = {-1,1,0,0};
    const int dc[4] = {0,0,-1,1};

    int time()
    {
        int t = 0; 
        int size = box.size();
        cod now, next;

        while(box.size())
        {
            now = box.front();
            box.pop();

            for(int d = 0; d < 4; d++)
            {
                next.r = now.r + dr[d];
                next.c = now.c + dc[d];

                if(map[next.r][next.c] == 0)
                {
                    map[next.r][next.c] = 1;
                    box.push(next);
                }
            }

            size--;
            if(size == 0)
            {
                size = box.size();
                t++;
            }
        }

        int allDelicious = check();
        return allDelicious ? t - 1 : -1;
    }
} info;

int main()
{
    info.init();

    cout << info.time() << '\n';
    return 0;
}