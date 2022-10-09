#include <iostream>
#include <vector>

void print(int*pv, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << *pv << " ";
        pv++;
    }
}

void QuickSort (int* pv, const int l, const int r) {
    if (r > l) {
        int* pl = &(*(pv + l));
        int* pr = &(*(pv + r));
        int m = (l + r) / 2;
        int mid = *(pv + m); 
        while(pl <= pr){
            while (*pl < mid) {
                pl++;
            }
            while (*pr > mid) {
                pr--;
            }
            if (pl >= pr) {
                break;
            }
            int swap = *pl;
            *pl = *pr;
            *pr = swap;
            pl++;
            pr--;
        }
        QuickSort(pv, l, pr-pv);
        QuickSort(pv, pr-pv+1, r);
    }
}

int main() {
    int n;
    std::cin >> n;
    int v[100001] = {};
    int* pv = &v[0];
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    QuickSort(pv, 0, n - 1);
    print(pv, n);

    return 0;
}
