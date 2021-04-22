#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

int iq;

std::ostream &operator << (std::ostream &co, vector<int> &v) {
    bool ii = false;
    for (int a : v) {
        if (ii) co << ' ';
        ii = true;
        co << a;
    }
    co << endl;
    iq++;
    return co;
}

struct Node
{
    int value = 0;
    Node* next = nullptr;

    Node(int v)
    {
        value = v;
    }

    Node(int v, Node *n) {
        value = v;
        next = n;
    }
};

void rm(vector<int> &v, int ele) {
    for(auto it= v.begin(); it != v.end(); it++) {
        if (*it == ele) {
            v.erase(it);
            return;
        }
    }
}

Node *getMiddleNode(Node *head, Node* tail, Node* &midl, Node* &midr)
{
    int n = 1; Node *p = head;
    while(p != tail && ++n) p = p->next;

    if (n >= 4)
    {
        int ml = n/3;
        int mr = 2 * n / 3;
        midl = head; while (ml-- > 0) midl = midl->next;
        midr = head; while (mr-- > 0) midr = midr->next;
        return nullptr;
    }
    else
    {
        int mid = n/2;
        p = head;
        while (mid-- > 0) p = p->next;
        return p;
    }
}

void insertMiddleNode(Node *head, Node *tail, int imid) {
    if (head->next == tail) {
        head->next = new Node(imid, tail);
        return;
    }
    
    Node *ml, *mr;
    Node *pmid = getMiddleNode(head, tail, ml, mr);
    if (pmid == nullptr)
    {
        vector<int> query({ml->value, mr->value, imid});
        cout << query;
        int inext; cin >> inext;
        if (inext == imid)
        {
            insertMiddleNode(ml, mr, imid);
        }
        else if (inext == ml->value)
        {
            insertMiddleNode(head, ml, imid);
        }
        else 
        {
            insertMiddleNode(mr, tail, imid);
        }
    }
    else
    {
        vector<int> query({head->value, pmid->value, imid});
        cout << query; 
        int inext; cin >> inext;

        if (inext == imid) {
            insertMiddleNode(head, pmid, imid);
        } else {
            insertMiddleNode(pmid, tail, imid);
        }
    }
}

void solve(int t, const int n, const int q)
{
    
    int imid; iq = 0;
    vector<int> query({1, 2, 3});
    cout << query;
    cin >> imid; rm(query, imid);

    Node *head = new Node(query[0]);
    Node *tail = new Node(query[1]);
    head->next = tail;
    
    insertMiddleNode(head, tail, imid);

    int inext = 4;
    query.push_back(inext);
    while (iq < q && inext <= n)
    {
        cout << query;
        cin >> imid;

        // normal
        if (imid != inext)
        {
            // new head
            if (imid == query[0])
            {
                head = new Node(inext, head);
                query.clear();
                query.push_back(inext);
                query.push_back(tail->value);
                query.push_back(++inext);
            }
            else // new tail
            {
                tail->next = new Node(inext);
                tail = tail->next;
                query.clear();
                query.push_back(head->value);
                query.push_back(inext);
                query.push_back(++inext);
            }
        }
        else // 
        {
            insertMiddleNode(head, tail, imid);
            query.pop_back();
            query.push_back(++inext);
        }
    }

    Node *p = head;
    while(p != nullptr) {
        cout << p->value << ' ';
        head = p->next;
        delete p;
        p = head;
    }
    cout << endl;
    
    int rs;
    cin >> rs;
    //cerr << iq << endl;
    if (rs != 1)
    {
        exit(0);
    }
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL_DEBUG
    //freopen("bai04.txt", "r", stdin);
#endif

    int tt, n, q;
    cin >> tt >> n >> q;
    for (int t = 1; t <= tt; t++)
    {
        solve(t, n, q);
    }

    return 0;
}
