#include <lastweapon/number>
#include <bits/stdc++.h>
using namespace lastweapon;

const int N = 50, M = 3;
const int offset = 3, mask = (1 << offset) - 1, offset2 = 8, mask2 = (1 << offset2) - 1;
int A[N + 1][M + 1], B[N*M];
int n, m;
int ans; Int d;
const int MaxSZ = 16796, Prime = 9973;

struct hashTable
{
    int head[Prime], next[MaxSZ], sz;
    int state[MaxSZ];
    Int key[MaxSZ];

    void clear()
    {
        sz = 0;
        memset(head, -1, sizeof(head));
    }

    void push(int s)
    {
        int x = s % Prime;
        for (int i = head[x]; ~i; i = next[i])
        {
            if (state[i] == s)
            {
                key[i] += d;
                return;
            }
        }
        state[sz] = s, key[sz] = d;
        next[sz] = head[x];
        head[x] = sz++;
    }

    void roll()
    {
        for (int i = 0; i < sz; i++) {
            int s0 = state[i] & ((1 << (offset2*m)) - 1), s1 = state[i] ^ s0;
            state[i] = (s1 << offset) | s0;
        }
    }
} H[2][3], *H0, *H1;

int b[M + 1], bb[M + 1];
int b2[M + 1];

// 256 = 2^8

int encode()
{
    int s = 0;
    memset(bb, -1, sizeof(bb));
    int bn = 1;
    bb[0] = 0;
    for (int i = m; i >= 0; --i)
    {
        if (!~bb[b[i]]) bb[b[i]] = bn++;
        s <<= offset;
        s |= bb[b[i]];
    }

    for (int i = m-1; i >= 0; --i)
    {
        s <<= offset2;
        s |= b2[i];
    }
    return s;
}

void decode(int s)
{
    for (int i = 0; i < m; i++)
    {
        b2[i] = s & mask2;
        s >>= offset2;
    }
    for (int i = 0; i < m + 1; i++)
    {
        b[i] = s & mask;
        s >>= offset;
    }
}


bool onTheEdge(int x, int y) {
    return !x || !y || (x == n-1) || (y == m-1);
}

int i, j;
void push(int c, int j, int dn, int rt, int o)
{
    if (o < 0 || n*m <= o) return;
    if (!o && !onTheEdge(i, j)) return;

    //cout << i << " " << j << " " << A[i][j] << " " << o << " " << B[o] << endl;

    if (A[i][j] != B[o]) return;

    b[j] = dn;
    b[j + 1] = rt;
    b2[j] = o;

    H1[c].push(encode());
}

void init()
{
    cin >> n >> m; swap(n, m);
    H0 = H[0], H1 = H[1]; for (int c = 0; c < 3; c++) H1[c].clear();

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) cin >> A[i][j];

    REP(i, n*m) RD(B[i]);
}



Int solve()
{

    if (n == 1 & m == 1) { // ����
        return A[0][0] = B[0];
    }

    Int ans = 0;
    d = 1; H1[0].push(encode());

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            //checkMax(ans, A[i][j]);  // ��Ҫ��������һ�����ӵ����
            // if (!A[i][j]) continue;  // ������ϰ�����������ע����ʱ״̬���鲻��Ҫ����

            swap(H0, H1);
            for (int c = 0; c < 3; c++)
                H1[c].clear();  // c ��ʾ���ɺ���ʧ�¼��������ܴ�������಻���� 2 ��

            for (int c = 0; c < 3; c++)
                for (int ii = 0; ii < H0[c].sz; ii++)
                {
                    decode(H0[c].state[ii]);
                    d = H0[c].key[ii];

                    //cout << i << " " << j << " " << d << ": " << endl;
                    //REP(i, m) cout << b2[i] << " "; cout << endl;
                    //REP(i, m+1) cout << b[i] << " "; cout << endl;


                    int lt = b[j], up = b[j + 1];
                    bool dn = i != n-1, rt = j != m-1;
                    if (lt && up)
                    {
                        if (lt == up)    // ��һ��·�������У����ǲ��ܺϲ���ͬ�Ĳ�ͷ��
                        {
                            // Cannot deploy here...
                        }
                        else      // �п��ܲ���ϲ����������ж�����ͷ������Ҳ������ͬ���Ĵ���Ƭ�δ���
                        {
                            for (int i = 0; i < m + 1; i++)
                                if (b[i] == lt) b[i] = up;
                            if (abs(b2[j] - b2[j-1]) == 2)
                                push(c, j, 0, 0, (b2[j] + b2[j-1])/2);
                        }
                    }
                    else if (lt || up)
                    {
                        int t = lt | up;

                        int o = lt ? b2[j-1] : b2[j];

                        if (dn)
                        {
                            push(c, j, t, 0, o+1);
                            push(c, j, t, 0, o-1);
                        }
                        if (rt)
                        {
                            push(c, j, 0, t, o+1);
                            push(c, j, 0, t, o-1);
                        }
                        // һ����ͷ��ʧ�����������Ƕ�����ͷ����ζ����ʧ������ǳɶԳ��ֵĲ�ͷ���൱��������һ��������ͷ��
                        // ������һ���¼�����Ҫ�� c + 1��
                        if (c < 2)
                        {

                            //cout << o << "!?" << endl;
                            //cout << d << "??" << endl;

                            if (o == 1) push(c + 1, j, 0, 0, 0);
                            if (o == n*m-2) push(c + 1, j, 0, 0, n*m-1);
                        }
                    }
                    else
                    {
                        if (dn && rt)    // ����һ�Բ�ͷ
                        {
                            FOR(o, 1, n*m-1) push(c, j, m, m, o);
                        }
                        if (c < 2)    // ����һ��������ͷ
                        {
                            //cout << dn << " " << rt << "???" << " " << onTheEdge(i, j) << endl;

                            if (dn)
                            {
                                push(c + 1, j, m, 0, 0);
                                push(c + 1, j, m, 0, n*m-1);
                            }
                            if (rt)
                            {
                                push(c + 1, j, 0, m, 0);
                                push(c + 1, j, 0, m, n*m-1);
                            }
                        }
                    }
                }
        }
        for (int c = 0; c < 3; c++) H1[c].roll();  // һ�н���������������
    }
    for (int ii = 0; ii < H1[2].sz; ii++) ans += H1[2].key[ii];
    return ans;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif


    MOD = 11192869;
    init();
    cout << solve() << endl;
}
