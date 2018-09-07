#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
priority_queue<int> pq;
char N[27][27];
int que[10000][2];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
bool visit[27][27];

void setNum(int r, int c){
    int s, e; s = e = 0;

    que[e][0] = r;
    que[e++][1] = c;
    visit[r][c] = true;
    int cnt = 0;
    while(s != e){
        int now[2] = {que[s][0], que[s++][1]};

        cnt++;
        for(int d = 0; d < 4; d++){
            int next[2] = {now[0] + dr[d], now[1] + dc[d]};

            if(N[next[0]][next[1]] == '1') {
                if(visit[next[0]][next[1]]) continue;
                visit[next[0]][next[1]] = true;

                que[e][0] = next[0];
                que[e++][1] = next[1];
            }
        }
    }
    pq.push(-cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r, f;
    r = f = 0; 
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> N[i] + 1;
    }
        
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(visit[i][j]) continue;
            if(N[i][j] == '1'){
                setNum(i,j);
            }
        }
    }

    cout << pq.size() << '\n';
    while(pq.size()){
        cout << -pq.top() << '\n';
        pq.pop();
    }
    return 0;
}