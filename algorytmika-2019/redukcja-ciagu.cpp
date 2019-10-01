#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  // Trudno wyrazić jak bardzo nienawidzę tego zadania.
  //
  // Proszę sobie wyobrazić ludzkie życie jako tragedię, gdzie każdy wybór jak i
  // brak wyboru, będący decyzją samą w sobie, odcina wszystkie możliwe
  // przyszłości oprócz jednej; pociągając do odpowiedzialności wobec siebie
  // samego każdego, chociaż wolna wola nie może być niczym więcej niż żałosną
  // iluzją.
  //
  // Żyjemy, żeby umrzeć, lecz w trwodze przed śmiercią. Bóg został zabity w
  // biegu po ostateczne znaczenie, w biegu, w którym opuściliśmy nasze miasta,
  // minęliśmy wsie, zostawiliśmy ludzkość i biegniemy dalej patrząc na kolejne
  // poświęcenia. Po co, a dokąd i czy jest to tego warte?
  //
  // Większość sądzi, że nie, są granice, dawno przekroczone; choć włożyliśmy
  // wysiłek, jesteśmy w stanie zrozumieć, że mniejszym wysiłkiem jest zawrócić
  // niż przeć dalej wbrew wszelkiej logice; że krzywdząc siebie krzywdzimy
  // człowieka, bliskich, społeczeństwo; że jedyne co nawet moglibyśmy osiągnąć
  // to własna korzyść, własne zrozumienie, nieprzekładające się na zrozumienie
  // innych.
  //
  // Lecz są też inni; w swoim zaprzeczeniu agencji osoby zewnętrznej, tworzący
  // tragedię gdzie dawno była schowana; tworzący zamęt, gdzie był spokój,
  // tworzący chaos, gdzie był porządek. Reifikacją abstrakcji takiej osoby jest
  // to zadanie.

  I r = 0;
  for (I i = 0; i < n; ++i) {
    r += (i == 0 ? v[i] : i == 1 ? -v[i] : abs(v[i]));
  }
  cout << r << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
