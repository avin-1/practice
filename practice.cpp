#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> v;
typedef pair<int, int> pii;
typedef pair<int, pii> node;

v arr = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};

// node.first = max value in range
// node.second = {l,r}

// i ignored the segment trees concept ki actually me calculated values store kaha karne hai for efficient retrieval and updated

vector<node> segment(4 * arr.size());

int build(int l, int r, int c)
{
    if (l == r)
    {
        segment[c] = {arr[l], {l, r}};
        return arr[l];
    }
    int mid = l + (r - l) / 2;
    // build left and right then return their maximum
    int left = build(l, mid, 2 * c + 1);
    int right = build(mid + 1, r, 2 * c + 2);
    int m = max(left, right);
    pii p = {l, r};
    node n = {m, p};
    segment[c] = n;
    return m;
}
// now we have segment tree properly we use it and do the query
// query works like return me the max element from this and this range
int query(int l, int r, int c)
{
    node n = segment[c];
    pii p = n.second;
    if (p.first > r || p.second < l)
    {
        // completly outside
        return INT_MIN;
    }
    if (p.first >= l && p.second <= r)
    {
        // completly inside
        return n.first;
    }
    // overlapping
    int left = query(l, r, 2 * c + 1);
    int right = query(l, r, 2 * c + 2);
    return max(left, right);
}
// there are three conditions i need to look for
// completly inside
// completly outside
// overlappping

int main()
{
    build(0, arr.size() - 1, 0);

    cout << "Root Max = " << segment[0].first << endl;
    cout << query(1, 4, 0) << endl;

    return 0;
}
