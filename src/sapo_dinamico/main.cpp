#include <bits/stdc++.h>
#include <algorithm>  // Para std::max

using namespace std;

typedef long long ll;

ll n, com, i, x, a, dis, j, pos, res=0, dif, tot;
bool isb, valid, grande;

string input;
char type, dash;


vector<tuple<ll,bool,bool>> pedras;
vector<ll> fim;

int main(){

  cin >> tot;

  for(ll l=0; l<tot; l++){
   
    pedras.clear();

    res = 0;

    cin >> n >> com;

    if(n==0){
      fim.push_back({com});
    }else{

      pedras.push_back({0,true, true});

      for(ll q=0; q<n; q++){
        cin >> type >> x;
        isb = (type == 'B');
        pedras.push_back({x, isb, true});
      }

      pedras.push_back({com, true, true});

      // sort(pedras.begin(), pedras.end());

      for(i=0; i<=n+1;){

        dis = get<0>(pedras[i]);

        if(i<n){
          if(get<1>(pedras[i+1])){
            dif = get<0>(pedras[i+1]) - get<0>(pedras[i]);
            res = max(res, dif);
            i++;
          }else if(get<1>(pedras[i+2])){
            dif = get<0>(pedras[i+2]) - get<0>(pedras[i]);
            res = max(res, dif);
            i += 2;
          }else{
            dif = get<0>(pedras[i+2]) - get<0>(pedras[i]);
            res = max(res, dif);
            get<2>(pedras[i+2]) = false;
            i += 2;
          }
        }else if(i==n){
            dif = get<0>(pedras[i+1]) - get<0>(pedras[i]);
            res = max(res, dif);
            i = n+2;
          }else{
            i = n+2;
          }
      }


      dis = com;

      ll p=pedras.size()-1;

      for(i=pedras.size()-1; i>0; i--){

        if(get<2>(pedras[i-1])){
          dif = get<0>(pedras[p]) - get<0>(pedras[i-1]);
          res = max(res, dif);
          p = i-1;
        }
      }

      fim.push_back({res});

      res = 0;

    }
  }

  for(ll z=0; z<tot; z++){

    cout << "Case " << z+1 << ": " << fim[z] << endl;
  }

  cout << endl;

  return 0;

}



