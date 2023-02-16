#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

ll arr[N], seg[4 * N], lazy[4 * N];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        seg[si] = arr[se];
        return;
    }

    int mid = (ss + se) / 2;

    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    seg[si] = seg[2 * si] + seg[2 * si + 1];
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si] != 0)
    {
        ll dx = lazy[si];
        seg[si] += dx * (se - ss + 1);
        lazy[si] = 0;

        if (ss != se)
            lazy[2 * si] += dx, lazy[2 * si + 1] += dx;
    }

    if (ss > qe || se < qs)
    {
        return 0;
    }

    if (ss >= qs && se <= qe)
    {
        return seg[si];
    }

    int mid = (ss + se) / 2;

    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, ll val)
{
    if (lazy[si] != 0)
    {
        ll dx = lazy[si];
        seg[si] += dx * (se - ss + 1);
        lazy[si] = 0;

        if (ss != se)
            lazy[2 * si] += dx, lazy[2 * si + 1] += dx;
    }

    if (ss > qe || se < qs)
        return;

    if (ss >= qs && se <= qe)
    {
        seg[si] += val * (se - ss + 1);

        if (ss != se)
            lazy[2 * si] += val, lazy[2 * si + 1] += val;

        return;
    }

    int mid = (ss + se) / 2;

    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);

    seg[si] = seg[2 * si] + seg[2 * si + 1];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int n, q;
        cin >> n >> q;

        build(1, 1, n);

        while (q--)
        {
            int o;
            cin >> o;

            if (o == 0)
            {
                int l, r;
                ll v;
                cin >> l >> r >> v;

                update(1, 1, n, l, r, v);
            }
            else
            {
                int l, r;
                cin >> l >> r;

                cout << query(1, 1, n, l, r) << endl;
            }
        }

        memset(seg, 0, sizeof seg);
        memset(arr, 0, sizeof arr);
        memset(lazy, 0, sizeof lazy);
    }

    return 0;
}