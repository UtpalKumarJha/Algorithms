#include <stdio.h>
#include <math.h> 

long long *segmentTree;
long long *lazy;

long long query(int qLo, int qHi, int cLo, int cHi, int stIndex);

void update(int qLo, int qHi, int cLo, int cHi, int stIndex, long long val)
{
    if (cHi < qLo || qHi < cLo)
        return;

    if (lazy[stIndex] != 0)
    {
        if (cLo == cHi)
        {
            segmentTree[stIndex] += lazy[stIndex];
        }
        else
        {
            segmentTree[stIndex] += lazy[stIndex]*(cHi - cLo + 1);
            lazy[stIndex * 2 + 1] += lazy[stIndex];
            lazy[stIndex * 2 + 2] += lazy[stIndex];
        }
        lazy[stIndex] = 0;
    }

    if (qLo <= cLo && cHi <= qHi)
    {
        if (cLo == cHi)
        {
            segmentTree[stIndex] += val;
        }
        else
        {
            segmentTree[stIndex] += val * (cHi - cLo + 1);
            lazy[stIndex * 2 + 1] += val;
            lazy[stIndex * 2 + 2] += val;
        }
        return;
    }

    int mid = (cLo + cHi) / 2;
    update(qLo, qHi, cLo, mid, stIndex * 2 + 1, val);
    update(qLo, qHi, mid + 1, cHi, stIndex * 2 + 2, val);
    int left = stIndex * 2 + 1;
    int right = left + 1;
    segmentTree[stIndex] = query(cLo, mid, cLo, mid, stIndex * 2 + 1) + query(mid + 1, cHi, mid + 1, cHi, stIndex * 2 + 2);
}

long long query(int qLo, int qHi, int cLo, int cHi, int stIndex)
{
    if (cHi < qLo || qHi < cLo)return 0;

    if (lazy[stIndex] != 0)
    {
        if (cLo == cHi)
        {
            segmentTree[stIndex] += lazy[stIndex];
        }
        else
        {
            segmentTree[stIndex] += lazy[stIndex]*(cHi - cLo + 1);
            lazy[stIndex * 2 + 1] += lazy[stIndex];
            lazy[stIndex * 2 + 2] += lazy[stIndex];
        }

        lazy[stIndex] = 0;
    }
    if (qLo <= cLo && cHi <= qHi)
        return segmentTree[stIndex];

    int mid = (cLo + cHi) / 2;
    long long left = query(qLo, qHi, cLo, mid, stIndex * 2 + 1);
    long long right = query(qLo, qHi, mid + 1, cHi, stIndex * 2 + 2);
    return left + right;
}

int segSize;

void constructSegmentTree(int size)
{
    int height = (int) ceil(log((double) size) / log((double) 2));
    segSize = (int) ceil(pow((double) 2, height + 1));
    segmentTree = new long long[segSize];
    lazy = new long long[segSize];
    for (int i = 0; i < segSize; ++i)
    {
        segmentTree[i] = 0;
        lazy[i] = 0;
    }
}

int main()
{
    int nCases;
    scanf("%d", &nCases);
    while (nCases--)
    {
        int N, C;
        scanf("%d %d", &N, &C);
        constructSegmentTree(N);
        for (int i = 0; i < C; ++i)
        {
            int type, p, q;
            long long v;
            scanf("%d", &type);
            if (type == 0)
            {
                scanf("%d %d %lld", &p, &q, &v);
                update(p - 1, q - 1, 0, N - 1, 0, v);
            }
            else
            {
                scanf("%d %d", &p, &q);
                printf("%lld\n", query(p - 1, q - 1, 0, N - 1, 0));
            }
        }
        delete(segmentTree);
        delete(lazy);
    }
}