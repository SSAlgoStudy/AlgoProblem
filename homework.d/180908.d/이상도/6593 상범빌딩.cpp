#include<iostream>
#include<queue>

using namespace std;

char SangBeom_map[32][32][32];
bool SangBeom_visit[32][32][32];

struct SangBeomBuilding_Position
{
    int x; int y; int z;
    int cnt;
};

int main()
{
    typedef SangBeomBuilding_Position pos;
    int x,y,z;

    while(true)
    {
        cin >> z >> y >> x;

        if(!x && !y && !z) break;

        queue<pos> que;
        bool find = false;
        SangBeomBuilding_Position start;
        pos des;
        while(!que.empty()) que.pop();

        for(int i = 0 ; i<32;i++)
            for(int j = 0 ; j<32;j++)
                for(int k = 0 ; k<32; k++)
                {
                    SangBeom_map[i][j][k] = '#';
                    SangBeom_visit[i][j][k] = false;
                }
        
            for(int h = 1 ;h<=z;h++ )
            {
                for(int r = 1; r<=y;r++)
                {
                    for(int c = 1 ;c<=x;c++ )
                    {
                        cin >> SangBeom_map[h][r][c];
                        if(SangBeom_map[h][r][c] == 'S')
                        {
                            start.x = c; start.y = r; start.z = h;
                            start.cnt = 0;
                            que.push(start);
                        }

                        else if(SangBeom_map[h][r][c] == 'E')
                        {
                            des = {c,r,h,0};
                        }
                    }
                }
            }

        int dx[6] = {0,1,0,-1,0,0};
        int dy[6] = {-1,0,1,0,0,0};
        int dz[6] = {0,0,0,0,-1,1};
        pos p, next;
        while(!que.empty())
        {
            p = que.front();
            que.pop();

            if(p.x == des.x && p.y == des.y&&p.z == des.z)
            {
                find = true;
                break;
            }

            for(int d= 0; d<6;d++)
            {
                next = {p.x + dx[d], p.y + dy[d], p.z + dz[d], p.cnt+1};


                if(SangBeom_visit[next.z][next.y][next.x]) continue;

                SangBeom_visit[next.z][next.y][next.x] = true;
                if(SangBeom_map[next.z][next.y][next.x] == '#') continue;
                 que.push(next);
            }
        }

        if(find) cout << "Escaped in " << p.cnt << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}