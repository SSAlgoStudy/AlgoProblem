#pragma once
#include<cstdio>
#include<iostream>

using namespace std;

int nums[13];
int k;
void func(int visit) {
	int idx = 0;
	while(visit)
	{
		if (visit & 1) {
			printf("%d ", nums[idx]);
		}
		idx++;
		visit >>= 1;
	}
	printf("\n");
}
void celcious(int depth,int selected, int visit) {
	if (k - depth == 6 - selected || selected == 6)
	{
		for (int i = 0; i < 6 - selected; i++) {
			visit |= 1 << (depth + i);
		}
		func(visit);
		return;
	}

	celcious(depth + 1, selected + 1, visit | (1 << depth));
	celcious(depth + 1, selected, visit);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> nums[i];
		}
		celcious(0, 0, 0);
		printf("\n");
	}
	return 0;
}