#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N = 100010;

int n, m, k;

int check(int x,int* t,int* c)   //�ж�ʹn�����򿪿Ѻ�ʱ���̵�x���Ƿ�Ϸ�
{
    long long res = 0;  
    int i;
    for ( i = 0; i < n; i++)
        if (t[i] > x)  //��t[i] <= xֱ������
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
    int mx = 0;   //�ҵ�t[i]�����ֵ
    scanf("%d %d %d", &n, &m, &k);
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d %d", &t[i], &c[i]);

       
        mx = max(mx, t[i]);
    }
    int l = k, r = mx;  //��k��mx�϶���
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid,t,c)) r = mid;  //���mid���㣬�����mid��ߣ�����mid��
        else l = mid + 1;        //������mid�ұߣ�������mid��
    }
    printf("%d", r);
    return 0;
}




