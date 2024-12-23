// Uniqueone's Code
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ll int
#define pair<int,int> pi

int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
// triplet
struct triplet
{
    int a, b, c;
    triplet(int x, int y, int z) : a(x), b(y), c(z) {}
};

// segment tree
struct segtree{
    int size;
    vector<long long> sums;
    void initialize(int x){
        size = 1;
        while(size < x){ size*=2;}
        sums.assign(2*size,0);
    }
    void build(vector<int> &a, int x,int left,int right){
        if(right - left == 1){
            if(left < int(a.size())) sums[x] = a[left];
            return;
        }
        int mid = (left + right ) / 2;
        build(a,2*x+1,left,mid);
        build(a,2*x+2,mid,right);
        sums[x] = sums[2*x+1] + sums[2*x+2];
        return;
    }
    
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    
    void update(int i,int value, int x,int left,int right){
        if(right - left == 1){
            sums[x] = value;
            return;
        }
        int mid = (left + right) / 2;
        if(i < mid) update(i,value,2*x+1,left,mid);
        else update(i,value,2*x+2,mid,right);
        sums[x] = sums[2*x + 1] + sums[2*x + 2];
        return;
    }
    void update(int pos,int value){
        update(pos,value,0,0,size);
    }

    long long query(int ql,int qr, int x,int left, int right){
        if(qr <= left || right <= ql) return 0;
        if(qr >= right && ql <= left){
            return sums[x];
        }
        int mid = (left + right ) / 2;
        long long leftpart = query(ql,qr, (2*x+1), left,mid);
        long long rightpart = query(ql,qr, (2*x+2), mid,right);
        return leftpart+rightpart;
    }
    long long query(int left,int right){
        return query(left,right,0,0,size);
    }
};
// Disjoint set Union
class DSU {
  private:
    vector<int> parents;
    vector<int> sizes;

  public:
    DSU(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }

    /** @return the "representative" node in x's component */
    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    /** @return whether the merge changed connectivity */
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }

        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y) { return find(x) == find(y); }
};
//gcd
int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
      return gcd(a - b, b);
    return gcd(a, b - a);
}
// MergeSort 
void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp(high - low + 1, 0);
        int idx  = 0;
        int lIdx = low;
        int rIdx = mid;
        while(lIdx < mid && rIdx <= high){
            if(nums[lIdx] <= nums[rIdx]){
                temp[idx++] = nums[lIdx++];
            }
            else{
                temp[idx++] = nums[rIdx++];
            }
        }
        while(lIdx < mid){
            temp[idx++] = nums[lIdx++];
        }
        while(rIdx <= high){
            temp[idx++] = nums[rIdx++]; 
        }
        idx = 0;
        for(int i = low ; i <= high ; i++){
            nums[i] = temp[idx++];
        }

    }
    
void mergeSort(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid + 1, high);
    }
}
//Modulo Inverse
// a is the number u want mod inverse of and mod is the value with which mod is to be taken of like 1e9+7
int modInverse(int a, int mod) {
        int res = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1)
                res = (1LL * res * a) % mod;
            a = (1LL * a * a) % mod;
            p >>= 1;
        }
        return res;
}
// start here

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    if(k == 1){
        if(n == 1){
            cout<<1<<endl;cout<<1<<endl;
        }
        else cout<<-1<<endl;
        return;
    }
    if(k >= n){
    	cout<<-1<<endl;
    }
    else{
    	int val = k;
    	if(k%2 == 0){
            cout<<3<<endl;
            cout<<1<<" "<<k<<" "<<k+1<<endl;
        }
        else{
            cout<<3<<endl;
            cout<<1<<" "<<k-1<<" "<<k+2<<endl;
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
    