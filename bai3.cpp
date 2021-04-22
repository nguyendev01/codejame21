#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int arr[101];

// inclusive
void reverse(int *a, int *b)
{
    int t;
    while (a < b)
    {
        t = *a;
        *a = *b;
        *b = t;
        ++a;
        --b;
    }
}

int recheck(int n){
    int cost = 0;
    for (int i=0, j=1, ni=n-1; i < ni; i++, j++) {
        for (int k=i; k < n; k++) {
            if (arr[k] == j) {
                cost += k - i + 1;
                if (k > i) {
                    reverse(arr + i, arr + k);
                }
            }
        }
    }
    return cost;    
}

void solve(const int t)
{
    int n, c, ccc;
    cin >> n >> c;

    ccc = c;

    if (n == 3 && c == 3)
    {
        cout << "Case #" << t << ": 1 3 2" << endl;
        return;
    }

    if (c < n - 1 || c > (n - 1) * (n + 2) / 2)
    {
        cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        return;
    }

    if (c == 2 * n - 2)
    {
        cout << "Case #" << t << ":";
        do
        {
            cout << ' ' << n;
        } while (--n > 0);
        cout << endl;
        return;
    }

    if (c == n - 1)
    {
        cout << "Case #" << t << ":";
        for (int i = 1; i <= n; i++)
            cout << ' ' << i;
        cout << endl;
        return;
    }

    for (int i = 0, j = 1; i < n; i++, j++)
        arr[i] = j;
    
    int *b = arr + n - 1;
    int *a = arr + n - 2;
    int ce = 2;
    int nn = n;
    while (c > 0)
    {
        c -= ce;
        reverse(a, b);

        if (c == ce+1)
        {
            --c;
            --a;
            --b;
            --nn;
            continue;
        }

        if (c == 0) break;
        
        if (c == nn - ce)  break;

        if (nn == ce) break; // maximum c === 0

        if (ce == nn-1) {
            if (c == 1) {
                reverse(arr+1, b-1);
                break;
            }
        }

        ++ce;
        --a;
    }
    
    

    cout << "Case #" << t << ":";
    for (int i = 0; i < n; i++)
        cout << ' ' << arr[i];
    

    if (ccc != recheck(n)) {
        cout << " ----------- WRONG " << n << ' ' << ccc;
    }

    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL_DEBUG
    freopen("bai03.txt", "r", stdin);
#endif

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        solve(t);
    }

    return 0;
}
