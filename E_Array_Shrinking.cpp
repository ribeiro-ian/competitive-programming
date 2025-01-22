#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int indexGreatest(vector <int> v){
    int greatest = v[0], ans = 0;

    for (int i = 0; i < v.size(); i++){
        if (v[i] > greatest){
            ans = i;
            greatest = v[i];
        }
    }
    
    return ans;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;

    vector <int> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    while (1){
        bool ok = false;
        int next;

        vector <pair <int, int>> p;
        for (int i = 0; i < v.size()-1; i++){
            if (v[i] == v[i+1]){
                ok = true;
                p.push_back(make_pair(i, i+1));

                if (i > indexGreatest(v))
                    next = 0;
                else
                    next = p.size()-1;
            }
        }

        if (!ok)
            break;
        
        v[p[next].first]++;
        v.erase(v.begin() + p[next].second);

        // cerr << "vetor:\n";
        // for (auto &i : v) cerr << i << " ";
        // cerr << endl;
    }
    
    cout << v.size() << endl;

    return 0;
}
