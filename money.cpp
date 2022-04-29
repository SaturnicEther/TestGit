#include <fstream>
#include <iostream>
#include <ctime>

int main()  {

    using namespace std;

    int bills[]{ 100,200,500,1000,2000,5000 };
    int i, nbills[6];
    int sumbills = 0;
    float k;

    const char* fbills = "bills.bin";

    char action;

    cout << "Input bills  ->  '+', cash withdrawal -> '-'"; cin >> action;

    if (action == '+') {   //load
        srand(time(0)); 
        for (i = 5; i > 0; i--) {
            nbills[i] = i%2 + rand() % 333;
            sumbills += nbills[i];
        }

        cout << sumbills << "\n";

        if (sumbills > 900)   // Исключаем перебор
            for (i = 5, k = 900 / (float)sumbills, sumbills = 0; i > 0; i--) {
                nbills[i] *= k;
                sumbills += nbills[i];
            }

        cout << sumbills << "\n";

        nbills[0] = 1000 - sumbills;

        ofstream f(fbills, ios::binary);

        for (i = 5; i >= 0; i-- ) {        //save
            f.write((char*)&nbills[i], sizeof(int));
            cout << nbills[i] << ": " << bills[i] << "\t";
        }

        f.close();

        // cout << "\nQuit ->  'q', cash withdrawal -> '-'"; cin >> action;  // debug
    }


    if (action == '-') {
        ifstream f(fbills, ios::binary);
        int summ, total = 0;
        int n, ts, s, s1=0;

        for (i = 5; i >= 0; i--) {
            f.read((char*)&nbills[i], sizeof(int));
            total += nbills[i] * bills[i];
            cout << nbills[i] << ": " << bills[i] << "\t";
        }

        cout << "\nTotal = " << total<< "\n";
        cout << "Input summ : "; cin >> summ;
        s = summ;
        nbills[0] = 0;
        if (nbills[0] == 0 and (s / 100) % 2)
        {
            s1 = s % 1000;
            if (s1 < 500)
            {
                s1 += 1000;
            }
            s1 -= s1;
            cout << 1 << ": " << 500 << "\t" << (s1 - 500) / 200 << ": " << 200 << "\n";
        }

        for (ts=0, s = summ, i = 5; i >= 0; i--) {
            if (s >= bills[i]) {
                n = s / bills[i];
                if (nbills[i] < n)  n = nbills[i];

                nbills[i] -= n;
                s -= n * bills[i];
                cout << n << ": " << bills[i] << "\t";
                ts += n * bills[i];
            }
        }
        
        cout << "\n";
        f.close();

        if (ts != summ) {
            cout << "Not enough money!\n";
            return 1;
        }

        // сохраняем остатки
        ofstream fw(fbills, ios::binary);

        for (i = 5; i >= 0; i--) {
            fw.write((char*)&nbills[i], sizeof(int));
            cout << nbills[i] << ": " << bills[i] << "\t";
        }

        fw.close();
    }
    return 0;
}