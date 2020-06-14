//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#define ll long long

const int maxn = 1e5 + 5;
//因为初始值全为一所以没有a[maxn]
struct tree
{
    int l;
    int r;
    ll sum;
    ll lazy;        //lazy标记
}node[maxn << 2];

void pushup(int rt)
{
    node[rt].sum = node[rt << 1].sum + node[rt << 1 | 1].sum;
}

void pushdown(int rt , int nl , int nr)
{
    //rt指当前节点，，，
    //nl指左节点有nl个需要被赋值为lazy
    //同理，，nr指右节点有nr个需要被赋值为lazy
    if(node[rt].lazy)
    {
        //当这节点lazy不为0时，，要向下更新一下
        node[rt << 1].sum = node[rt].lazy * nl; //修改sum
        node[rt << 1].lazy = node[rt].lazy; //下推lazy

        node[rt << 1 | 1].sum = node[rt].lazy * nr;
        node[rt << 1 | 1].lazy = node[rt].lazy;

        node[rt].lazy = 0;      //标记清除
    }
}

void build(int rt , int l , int r)
{
    node[rt].l = l;
    node[rt].r = r;
    node[rt].sum = 0;
    node[rt].lazy = 0;      //不要忘了

    if(l == r)
    {
        node[rt].sum = 1;
        return;
    }

    int mid = node[rt].l + ((node[rt].r - node[rt].l) >> 1);

    build(rt << 1 , l , mid);
    build(rt << 1 | 1 , mid + 1 , r);

    pushup(rt);

    return;
}
void update(int rt , int L , int R , int C)
{
    if(L <= node[rt].l && node[rt].r <= R)
    {
        //当该节点对应的区间在所要操作的区间里时更新
        node[rt].sum = (node[rt].r - node[rt].l + 1) * C;
        node[rt].lazy = C;
        return;
    }

    int mid = node[rt].l + ((node[rt].r - node[rt].l) >> 1);
    //下推lazy标记，，想上保证正确
    pushdown(rt , mid - node[rt].l + 1 , node[rt].r - mid);

    if(L <= mid)    update(rt << 1 , L , R , C);
    if(R >  mid)    update(rt << 1 | 1 , L , R , C);
    pushup(rt);
    return;
}
ll query(int rt , int L , int R)
{
    if(L <= node[rt].l && node[rt].r <= R)
    {
        return node[rt].sum;
    }

    int mid = node[rt].l + ((node[rt].r - node[rt].l) >> 1);

    pushdown(rt , mid - node[rt].l + 1 , node[rt].r - mid);

    ll ans = 0;
    if(L <= mid)    ans += query(rt << 1 , L , R);
    if(R >  mid)    ans += query(rt << 1 | 1 , L , R);
    return ans;
}
int main(int argc, char const *argv[])
{
    int T;scanf("%d" , &T);
    for(int i = 1; i <= T; ++i)
    {
        int n , q;
        scanf("%d%d" , &n , &q);

        build(1 , 1 , n);

        while(q--)
        {
            int a , b , c;
            scanf("%d%d%d" , &a , &b , &c);

            update(1 , a , b , c);
        }

        printf("Case %d: The total value of the hook is %lld.\n" , i , query(1 , 1 , n));
    }
    return 0;
}