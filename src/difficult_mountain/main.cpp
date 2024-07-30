#include <bits/stdc++.h>

using namespace std;

int tot=0, alp=0, d, n, i, x, y, m;

vector<tuple<int, int, int>> lis_alp;

// [max, habilidade, limpeza]

int main(){

  cin >> n >> d;

  for(i=0; i<n; i++){

    cin >> x >> y;

    if(x>=d){

      lis_alp.push_back({max(x,y), x, y});
      tot++;

    }

  }

  sort(lis_alp.begin(), lis_alp.end());

  for(auto [m, x, y]:lis_alp){
    
    if(x>=d){
      d=max(y, d);
      alp++;
    }

  }


  cout << alp << endl;

  return 0;

}




