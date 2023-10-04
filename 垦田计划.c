#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N = 100010;

int n, m, k;

int check(int x,int* t,int* c)   //判断使n块区域开垦耗时缩短到x天是否合法
{
    long long res = 0;  
    int i;
    for ( i = 0; i < n; i++)
        if (t[i] > x)  //若t[i] <= x直接跳过
            res += (t[i] - x) * c[i];
    if (res <= m)return 1;
    else return 0;
    
}

int mymax(int a,int b) {
    if (a > b)return a;
    else
    {
        return b;
    }
}
int main()
{
    int* t = (int*)malloc(N * sizeof(int));
    int* c = (int*)malloc(N * sizeof(int));
    int mx = 0;   //找到t[i]的最大值
    scanf("%d %d %d", &n, &m, &k);
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d %d", &t[i], &c[i]);

       
        mx = max(mx, t[i]);
    }
    int l = k, r = mx;  //在k到mx上二分
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid,t,c)) r = mid;  //如果mid满足，则答案在mid左边（包括mid）
        else l = mid + 1;        //否则在mid右边（不包括mid）
    }
    printf("%d", r);
    return 0;
}




