#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int n;

typedef struct c
{
    int ini, fim;
} compromisso;

const int MAXN = 1e5+10;
compromisso cons[MAXN];

bool comp(compromisso a, compromisso b){
    return a.fim < b.fim;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> cons[i].ini >> cons[i].fim;

    sort(cons, cons +n, comp);
    
    int cnt = 0, aux = 0;

    for (int i = 0; i < n; i++)
		if (cons[i].ini >= aux){
			cnt++;
			aux = cons[i].fim;
		}
		
	printf("%d\n", cnt);
	
	return 0;
}
