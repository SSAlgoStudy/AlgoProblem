#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int arr[8];
int nums[10001] = {0,};
int selected[8];
void print(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[selected[i]] << ' ' ;
    }

    cout << '\n';
}
void permutation(int n, int r, int length)
{
    if(r == length)
    {
        print(r);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(nums[arr[i]] == 0) continue; 
        selected[length] = i;

        nums[arr[i]]--;
        permutation(n,r,length+1);
        nums[arr[i]]++;
    }
}

int main()
{
    int n,r;
    cin >> n >> r;

    priority_queue<int,vector<int>, greater<int> > input;
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
        input.push(arr[i]);
    }

    int index =0;
    while(input.size())
    {
        int num = input.top();
        input.pop();

        if(nums[num] == 0)
        {
            arr[index++] =  num;
        }
        nums[num]++;
    }

    permutation(index,r,0);
    return 0;
}