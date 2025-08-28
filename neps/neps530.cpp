#include <iostream>
using namespace std;

#define TAM 101

int main(){
    int mar[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            mar[i][j] = 0;

    int num_redes;
    cin >> num_redes;

    while (num_redes--){
        int xi, xf, yi, yf;
        cin >> xi >> xf >> yi >> yf;

        for (int i = xi; i < xf; ++i)
            for (int j = yi; j < yf; ++j)
                mar[i][j] = 1;
    }        
    
    int area = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (mar[i][j] == 1)
                area++;

    cout << area << endl;

    return 0;
}