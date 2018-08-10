#include <iostream>
#include <queue>

using namespace std;

char map [50][51];
int check [50][50];

int distance (int N, int M, int row, int col){
  
  int max = 0;
  int dir_row [4] = {1,0,-1,0};
  int dir_col [4] = {0,1,0,-1};
  
  queue <int> q_row;
  queue <int> q_col;
  queue <int> dist;
  
  q_row.push(row);
  q_col.push(col);
  dist.push(0);
  

  while(!q_row.empty()){
    
    int row = q_row.front(); int col = q_col.front(); int d = dist.front();
    q_row.pop(); q_col.pop(); dist.pop();
    
    // check
    
    for (int i = 0; i < 4; i++){
      
      int temp_row = row + dir_row[i];
      int temp_col = col+ dir_col[i];
      
      if(temp_row > -1 && temp_row < N &&
         temp_col > -1 && temp_col < M &&
         map[temp_row][temp_col] == 'L' &&
         check[temp_row][temp_col] == 0
        ){
           check[temp_row][temp_col] = 1;
           q_row.push(temp_row);
           q_col.push(temp_col);
           dist.push(d+1);
         }
    }
    
    max = d;
  }
  
  return max;  
}

int main() {

    queue <int> q_row;
    queue <int> q_col;
    int N,M;
    
    scanf("%d %d",&N,&M);
    // Input all elements in map
    for(int row = 0; row < N; row++){
      cin.ignore(1);
      for(int col = 0; col < M; col++){
        scanf("%c",&map[row][col]);
        if(map[row][col] == 'L'){
          q_row.push(row);
          q_col.push(col);
        }
      }
    }
    /*
    for(int row = 0; row < N; row++){
      for(int col = 0; col <M; col++){
        printf("%c",map[row][col]);
      }
      printf("\n");
    }
    */
    int row,col,t,max = 0;

    while (!q_row.empty()){
       
      row = q_row.front();
      col = q_col.front();
      q_row.pop(); q_col.pop();
      
      // row,col 지점에서 최단 거리가 가장 먼 특정 지점으로 이동할 때 걸리는 시간.
      t = distance(N,M,row,col) * 1;
     // printf("%d\n",t);
      if (t > max)
        max = t;
        
      for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++)
          check [row][col] = 0;
    }
    
 printf("%d\n",max);
 return 0; 
}
