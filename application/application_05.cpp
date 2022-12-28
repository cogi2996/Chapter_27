// ung dung cua tree method
// tim max min day so
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1e6;

int a[MAXN];  // the set of integers
int n;  // the number of integers in the set

struct Node {
  int l, r;  // indices of the left and right children
  int min, max;  // minimum and maximum values in the subtree rooted at this node
};

Node tree[MAXN];

// builds the power tree for the given set of integers
void build_tree(int u, int l, int r) {
  tree[u].l = l;
  tree[u].r = r;
  if (l == r) {  // leaf node
    tree[u].min = tree[u].max = a[l];
    return;
  }
  int mid = l + (r - l) / 2;
  build_tree(u * 2, l, mid);
  build_tree(u * 2 + 1, mid + 1, r);
  tree[u].min = std::min(tree[u * 2].min, tree[u * 2 + 1].min);
  tree[u].max = std::max(tree[u * 2].max, tree[u * 2 + 1].max);
}

// returns the minimum value in the set
int get_min() {
  return tree[1].min;
}

// returns the maximum value in the set
int get_max() {
  return tree[1].max;
}

int main() {
  // read in the set of integers
  cout<<"Nhap so phan tu can so sanh: ";
  std::cin >> n;
  cout<<"Nhap cac phan tu: ";
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  // build the power tree
  build_tree(1, 0, n - 1);

  // print the minimum and maximum values
  std::cout << "Minimum value: " << get_min() << std::endl;
  std::cout << "Maximum value: " << get_max() << std::endl;

  return 0;
}
