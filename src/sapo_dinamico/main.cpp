#include <bits/stdc++.h>
#include <algorithm>  // Para std::max

using namespace std;

typedef long long ll;

ll n, com, max, i, x, a, dis, j, pos, res=0, dif, tot;
bool isb, valid, grande;

// char ped[3];

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

      cin.ignore();

      pedras.push_back({0,true, true});

      getline(cin, input);

      istringstream iss(input);

      while(iss >> type >> dash >> x){

        if(dash == '-'){
          isb = (type == 'B');
          pedras.push_back({x, isb, true});
        }
      }

      pedras.push_back({com, true, true});

      for(i=0; i<=n+1;){

        dis = get<0>(pedras[i]);
        // grande = get<1>(pedras[i]);
        // valid = get<2>(pedras[i]);


        if(i<n){
          if(get<1>(pedras[i+1])){
            dif = get<0>(pedras[i+1]) - dis;
            res = std::max(res, dif);
            i++;
          }else{
            if(get<1>(pedras[i+2])){
              dif = get<0>(pedras[i+2]) - dis;
              res = std::max(res, dif);
              i += 2;
            }else{
              dif = get<0>(pedras[i+2]) - dis;
              res = std::max(res, dif);
              get<2>(pedras[i+2]) = false;
              i += 2;
            }
          }

        }else{
          if(i==n){
            dif = get<0>(pedras[i+1]) - dis;
            res = std::max(res, dif);
            i++;
          }else{
            i++;
          }
        }

      }

      dis = com;

      for(i=n+1; i>0; i--){

        if(get<2>(pedras[i-1])){
          dif = dis - get<0>(pedras[i-1]);
          res = std::max(res, dif);
          dis = get<0>(pedras[i-1]);
        }
      }

      fim.push_back({res});


      // for(auto [a, s, d]:pedras){

      //   cout << a << " " << s << " " << d << endl;


      // }

      // cout << "res = " << res << endl;


      // // for(i=0; i<n; i++){

      // //   cin >> tipo >> '-' >> x;



      // // }

      // // cin >> tipo >> '-' >> x;

      // for(i=0; i<=2; i++){


      //   // cin.getline(ped, 4);
      //   cin >> ped;


      //   cout << ped[0] << endl;
      //   cout << ped[2] << endl;
      // }
      // cout << typedef(ped[2]) << endl;




    }
  }

  for(ll z=0; z<tot; z++){

    cout << "Case " << z+1 << ": " << fim[z] << endl;
  }

  return 0;

}



