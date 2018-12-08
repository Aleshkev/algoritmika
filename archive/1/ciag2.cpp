#include <iostream>
#include <vector>

/*
Liczymy ciag dopoki znane, pamietajc cale przedzial
*/

using namespace std;

const int N = 1000*100;

int Ost[N];

int main(){
    long long int n,znane;
    long long int j,i,k,ktory,wsk;
    bool koniec_petli = false;
    cin >> n;
    if (n==1) {
       cout << "1\n";
       return 0;
    }
    if ( n<=3 ) {
       cout << "2\n";
       return 0;
    }
    if ( n<=5 ) {
       cout << "3\n";
       return 0;
    }
    if ( n<=8 ) {
       cout << "4\n";
       return 0;
    }
    if ( n<=11 ) {
       cout << "5\n";
       return 0;
    }
//ost - ostatni element który wystepuje index razy
    Ost[1] = 1;
    Ost[2] = 3; //3 jest ostatnia ktora wystepuje 2 razy
    //ost[3] = 5
    //ost[4] = 8
    //ost[5] == 11
    k = 2;      //index dla ost
    wsk = 3;    //index dla ost
    znane = 11;
    ktory = 5;
/*
1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
1  2  2  3  3  4  4  4  5  5  5  6  6  6  6  7  7  7  7  8  8  8  8  9  9  9  9  9  10 10
1 wyraz który występuje 1 raz
2 wyrazy które wyystępują 2 razy (2 2 oraz 3 3)
2 wyrazy które wyystępują 3 razy (4 4 4 oraz 5 5 5)
3 wyrazy które wyystępują 4 razy
*/
    while(znane < n) {
        Ost[wsk] = Ost[wsk-1]+k;
        for(i=Ost[wsk-1]+1; i<=Ost[wsk]; i++){
            if (znane + i*wsk > n) {
               koniec_petli = true;
               break;
            }
            znane += i*wsk;
            ktory += wsk;
        }
        if (koniec_petli == true) {
             break;
        }
        wsk++;
        if(wsk > Ost[k]) k++;
    }
    while(znane < n){
        znane += i;
        ktory++;
    }
    cout << ktory << "\n";
    return 0;
}
