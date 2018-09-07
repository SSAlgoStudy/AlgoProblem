#include<cstdio>
#include<cstring>
char map[12][7];

char st[12], top;
bool visit[12][6];

int st2[100][2];
int que[100][2];

void down(){
    for(int j = 0; j < 6; j++){
        top = 0;
        for(int i = 0; i < 12 ; i++){
           if(map[i][j] != '.'){
               st[top++] = map[i][j];
               map[i][j] = '.';
           } 
        }
        int i = 11;
        while(top){
            map[i][j] = st[--top];
            i--;
        }
    }
}

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

bool bbang(int r, int c){
    char flag = map[r][c];
    int fr, re;
    fr = re = 0;

    que[re][0] = r;
    que[re++][1] = c;
    
    visit[r][c] = true;
    
    top = 0;
    st2[top][0] = r;
    st2[top++][1] = c;

    while(fr!=re){
       int now[2] = {que[fr][0], que[fr][1]};
       fr++;

        for(int d = 0; d < 4; d++){
            int next[2] = {now[0] + dr[d], now[1] + dc[d]};

            if(map[next[0]][next[1]] != flag) continue;
            if(visit[next[0]][next[1]]) continue;
            visit[next[0]][next[1]] = true;

            que[re][0] = next[0];
            que[re++][1] = next[1];

            st2[top][0] = next[0];
            st2[top++][1] = next[1];
        }
    }

    bool ret = false;
    if(top >= 4){
        ret = true;
        while(top){
            top--;
            map[st2[top][0]][st2[top][1]] = '.';
        }
    }
    return ret;
}
int main(){
    for(int i = 0; i < 12; i++){
           scanf("%s\n", map[i]); 
    }

    int res = 0;
    bool isEnd = false;
    while(!isEnd){
        isEnd = true;
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(map[i][j] == '.') continue;
               isEnd &= !bbang(i,j); 
            }
        }
        down();
        res++;
    }
    printf("%d\n", --res);
    return 0;
}