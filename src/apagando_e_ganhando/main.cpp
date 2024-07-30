#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, d, resto_remover;

stack<char> pilha;

string num;

int main() {

  while (cin >> n >> d) {

    if (n == 0 && d == 0){
      break;
    }  

    cin >> num;
    
    resto_remover = d;

    for (int i = 0; i < n; i++) {
      while (!pilha.empty() and resto_remover > 0 and pilha.top() < num[i]) {
        pilha.pop();
        resto_remover--;
      }
      pilha.push(num[i]);
    }

    while (resto_remover > 0) {
      pilha.pop();
      resto_remover--;
    }

    string resultado = "";
    while (!pilha.empty()) {
      resultado = pilha.top() + resultado;
      pilha.pop();
    }

    cout << resultado << endl;
  }

  return 0;
}
