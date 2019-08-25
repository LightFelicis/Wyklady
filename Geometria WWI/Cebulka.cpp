#include <bits/stdc++.h>
using namespace std;

using para = pair<int, int>;

para Odejmij(para A, para B){
    return {B.first - A.first, B.second - A.second};
}


long long IloczynWektorowy(para A, para B, para C){
    para Wek1 = Odejmij(A, B);
    para Wek2 = Odejmij(A, C);
    return static_cast <long long> (Wek1.first) * static_cast<long long> (Wek2.second) -
           static_cast <long long> (Wek2.first) * static_cast <long long> (Wek1.second);

}

vector <para> GenerujOtoczke(vector <para> &V){
    sort(V.begin(), V.end(), [](const para&A, const para&B)->bool{
                                    if (A.first == B.first){return A.second < B.second;}
                                                            return A.first < B.first;});
    vector <para> Gorna;
    Gorna.push_back(V[0]);
    Gorna.push_back(V[1]);
    for (int i = 2; i < V.size(); i++){
        auto Punkt = V[i];
        while (Gorna.size() >= 2 && IloczynWektorowy(Gorna.end()[-2], Gorna.end()[-1], Punkt) > 0){
            Gorna.pop_back();
        }
        Gorna.push_back(Punkt);
    }
    sort(V.begin(), V.end(), [](const para&A, const para&B)->bool{
                                    if (A.first == B.first){return A.second > B.second;}
                                                            return A.first > B.first;});
    vector <para> Dolna;
    Dolna.push_back(V[0]);
    Dolna.push_back(V[1]);
    for (int i = 2; i < V.size(); i++){
        auto Punkt = V[i];
        while (Dolna.size() >= 2 && IloczynWektorowy(Dolna.end()[-2], Dolna.end()[-1], Punkt) > 0){
            Dolna.pop_back();
        }
        Dolna.push_back(Punkt);
    }
    reverse(Gorna.rbegin(), Gorna.rend());
    
    if (Dolna == Gorna){
        return Dolna;
    }
    reverse(Gorna.begin(), Gorna.end());
    Dolna.pop_back();
    Gorna.pop_back();
    Gorna.insert(Gorna.end(), Dolna.begin(), Dolna.end());
    return Gorna;
}

int main() {
  int n;
  cin >> n;
  set <para> Secik;

  for (int i = 0; i < n; i++) {
      para Punkt;
      cin >> Punkt.first >> Punkt.second;
      Secik.insert(Punkt);
  }
  int IleWarstw = 0;
  while (Secik.size() > 2){
      vector <para> V;
      for (auto &co : Secik){
          V.push_back(co);
      }
      vector <para> Otoczka = GenerujOtoczke(V);
      for (auto &co : Otoczka){
          Secik.erase(co);
      }
      IleWarstw++;
  }
  if (Secik.size() > 0){
      IleWarstw++;
  }
  cout << IleWarstw;

  return 0;
}
