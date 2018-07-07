#include <stdio.h>
int main(void) {
	int T=10;
	setbuf(stdout, NULL);
	//scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int n;
		scanf("%d\n", &n);
		char map[9][9] = { {0,}, };
		for (int i = 0; i < 8; i++)
			scanf("%s", map[i]);

		int count = 0;

		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j + n - 1 < 8)//가로
				{
					int check = 1;
					for (int k = 0; k < n / 2; k++)
					{
						if (map[i][j + k] != map[i][j + n - 1 - k])//인덱스를 왼쪽에서 하나씩증가, 오른쪽에서 하나씩 감소 이동시키며 같지 않으면 빠져나온다
						{
							check = 0;
							break;
						}
					}
					if (check)//위 for문을 if문에 들어가지 않고 끝내면, 회문이라는 의미이므로 카운트 증가
						count++;
				}
				else//가로에서 범위를 벗어나면 세로도 범위를 벗어나게 되므로 바로 break
					break;
				if (j + n - 1 < 8)//세로 탐색
				{
					int check = 1;
					for (int k = 0; k < n / 2; k++)
					{
						if (map[j + k][i] != map[j + n - 1 - k][i])
						{
							check = 0;
							break;
						}
					}
					if (check)
						count++;
				}
			}			
		}
		printf("#%d %d\n", test_case, count);
	}
	return 0;
}