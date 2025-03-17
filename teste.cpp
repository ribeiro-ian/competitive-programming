#include <iostream>
#include <vector>

using namespace std;

vector<int> V;

int busca_menor(int num){
    int ini=1, fim=V.size()-1;
    int aux=1;
    while(ini<=fim){
        int meio=(ini+fim)/2;
        if(V[meio]==num) return V[meio-1];
        
        else if(V[meio]<num && V[meio]>=V[aux]){
            aux=meio;
            ini=meio+1;
        }
        else if(V[meio]>num){
            fim=meio-1;
        }
    }
    if(V[aux]>num){
        return -1;
    }
    return V[aux];
}

int busca_maior(int num){
    int ini=1, fim=V.size()-1;
    int aux=V.size()-1;
    while(ini<=fim){
        int meio=(ini+fim)/2;
        if(V[meio]==num) return V[meio+1];
        
        else if(V[meio]>num && V[meio]<=V[aux]){
            aux=meio;
            fim=meio-1;
        }
        else if(V[meio]<num){
            ini=meio+1;
        }
    }
    if(V[aux]<num){
        return -1;
    }
    return V[aux];
}

int main()
{
    int N;
    cin>>N;
    V.push_back(0);
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        V.push_back(num);
    }
    cin>>N;
    vector<int> P(N);
    for(int i=0; i<N; i++){
        cin>>P[i];
    }
    for(int i=0; i<N; i++){
        int num1=busca_menor(P[i]);
        int num2=busca_maior(P[i]);
        if(num1==-1) cout<<"X";
        else cout<<num1;
        
        if(num2==-1) cout<<" X"<<endl;
        else cout<<" "<<num2<<endl;
    }
    cout<<endl;
    return 0;
}