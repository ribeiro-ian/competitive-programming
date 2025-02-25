/*
    Beecrowd 1088 - Bolhas e Baldes
    https://judge.beecrowd.com/pt/problems/view/1088
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
vector <int> v;
int cnt;

void merge(int l, int m, int r){
    int n1 = m - l + 1,
        n2 = r - m;
    vector <int> left(n1), right(n2);    
    
    for (int i = 0; i < n1; i++)
        left[i] = v[l+i];

    for (int i = 0; i < n2; i++)
        right[i] = v[m+i+1];
    
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            v[k] = left[i++];
        }
        else{
            v[k] = right[j++];
            cnt += abs(n1-i);
        }
        k++;
    }

    while (i < n1){
        v[k++] = left[i++];
    }

    while (j < n2){
        v[k++] = right[j++];
    }
}

void merge_sort(int l, int r){
    if (l>=r) return;

    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, mid, r);
}

int main(){
    // um par de elementos consecutivos da seqüência que estejam fora de ordem
    // Marcelo é sempre o primeiro a começar a jogar
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0) break;

        v.assign(n,0);
        cnt = 0;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        merge_sort(0, n - 1);

        printf("%s\n", cnt % 2 ? "Marcelo" : "Carlos");
    }
    

    return 0;
}
