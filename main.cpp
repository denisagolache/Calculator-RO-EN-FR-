#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <winbgim.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

using namespace std;

vector<string> masculin{"", "un" };
vector<string> feminin{ "","o", "doua" };
vector<string> cifre{ "zero","unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua" };
vector<string> zeci{ "zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece","saisprezece", "saptesprezece", "optsprezece", "nouasprezece" };
vector<string> dzeci{ "","","douazeci", "treizeci", "patruzeci", "cincizeci", "sasezeci", "saptezeci", "optzeci", "nouazeci" };

string numeNumar(long numar)
{
    if (numar < 10)
    {
        return cifre[numar];
    }
    else if (numar < 20)
    {
        return zeci[numar - 10];
    }
    else if (numar < 100)
    {
        return dzeci[numar / 10] + ((numar % 10 != 0) ? " si " + numeNumar(numar % 10) : "");
    }
    else if (numar < 200)
    {
        return feminin[numar / 100] + " suta" + ((numar % 100 != 0) ? " " + numeNumar(numar % 100) : "");
    }
    else if (numar < 300)
    {
        return feminin[numar / 100] + " sute" + ((numar % 100 != 0) ? " " + numeNumar(numar % 100) : "");
    }
    else if (numar < 1000)
    {
        return numeNumar(numar / 100) + " sute" + ((numar % 100 != 0) ? " " + numeNumar(numar % 100) : "");
    }
    else if (numar < 2000)
    {
        return feminin[numar / 1000] + " mie" + ((numar % 1000 != 0) ? " " + numeNumar(numar % 1000) : "");
    }
    else if (numar < 3000)
    {
        return feminin[numar / 1000] + " mii" + ((numar % 1000 != 0) ? " " + numeNumar(numar % 1000) : "");
    }
    else if (numar < 20000)
    {
        return numeNumar(numar / 1000) + " mii" + ((numar % 1000 != 0) ? " " + numeNumar(numar % 1000) : "");
    }
    else if (numar < 1000000)
    {
        return numeNumar(numar / 1000) + " de mii" + ((numar % 1000 != 0) ? " " + numeNumar(numar % 1000) : "");
    }
    else if (numar < 2000000)
    {
        return masculin[numar / 1000000] + " milion" + ((numar % 1000000 != 0) ? " " + numeNumar(numar % 1000000) : "");
    }
    else if (numar < 3000000)
    {
        return feminin[numar / 1000000] + " milioane" + ((numar % 1000000 != 0) ? " " + numeNumar(numar % 1000000) : "");
    }
    else if (numar < 20000000)
    {
        return numeNumar(numar / 1000000) + " milioane" + ((numar % 1000000 != 0) ? " " + numeNumar(numar % 1000000) : "");
    }
    else if (numar < 1000000000)
    {
        return numeNumar(numar / 1000000) + " de milioane" + ((numar % 1000000 != 0) ? " " + numeNumar(numar % 1000000) : "");
    }
    else if (numar < 2000000000)
    {
        return masculin[numar / 1000000000] + " miliard" + ((numar % 1000000000 != 0) ? " " + numeNumar(numar % 1000000000) : "");
    }
    else if (numar < 3000000000)
    {
        return feminin[numar / 1000000000] + " miliarde" + ((numar % 1000000000 != 0) ? " " + numeNumar(numar % 1000000000) : "");
    }
    else if (numar < 20000000000)
    {
        return numeNumar(numar / 1000000000) + " miliarde" + ((numar % 1000000000 != 0) ? " " + numeNumar(numar % 1000000000) : "");
    }
    else if (numar < 1000000000000)
    {
        return numeNumar(numar / 1000000000) + " de miliarde" + ((numar % 1000000000 != 0) ? " " + numeNumar(numar % 1000000000) : "");
    }

}

int cuvantcheie(char* s1, char* s2)
{
    if (strstr(s1, s2))
        return true;
    return false;
}

bool cautaAdunare(char* s1)
{
    char adunare[6][20] = { "suma","adunarii","plus","sumei","adunat","adunarea" };
    for (int i = 0; i < 6; i++)
    {
        if (cuvantcheie(s1, adunare[i]))
        {
            return true;
        }

    }
    return false;
}

bool cautaScadere(char* s1)
{
    char scadere[6][20] = { "diferenta","scaderii","minus","diferentei","scazut","scaderea" };
    for (int i = 0; i < 6; i++)
    {
        if (cuvantcheie(s1, scadere[i]))
        {
            return true;
        }

    }
    return false;
}

bool cautaInmultire(char* s1)
{
    char inmultire[6][20] = { "produsul","inmultirii","ori","produsului","inmultit","inmultirea" };
    for (int i = 0; i < 6; i++)
    {
        if (cuvantcheie(s1, inmultire[i]))
        {
            return true;
        }

    }
    return false;
}

bool cautaImpartire(char* s1)
{
    char impartire[4][20] = { "catul","impartirii","impartit","impartirea" };
    for (int i = 0; i < 4; i++)
    {
        if (cuvantcheie(s1, impartire[i]))
        {
            return true;
        }

    }
    return false;
}

void eroare(char* s1)
{
    if (!(cautaAdunare(s1) || cautaImpartire(s1) || cautaInmultire(s1) || cautaScadere(s1)))

    {
        cout << "\n" << "Eroare: Propozitia nu contine niciun operator." << "\n";
        outtextxy(5,395,"Eroare: Propozitia nu contine niciun operator.");
    }
}


void cifrele(char* p, int& oprd, int& nr) // de la 0 la 9
{
    char cuvant[100];
    strcpy(cuvant, "zero");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 0;

    strcpy(cuvant, "unu");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 1;

    strcpy(cuvant, "doi");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 2;

    strcpy(cuvant, "doua");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 2;

    strcpy(cuvant, "trei");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 3;

    strcpy(cuvant, "patru");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 4;

    strcpy(cuvant, "cinci");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 5;

    strcpy(cuvant, "sase");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 6;

    strcpy(cuvant, "sapte");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 7;

    strcpy(cuvant, "opt");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 8;

    strcpy(cuvant, "noua");
    if (strcmp(p, cuvant) == 0)
        nr = nr + 9;

}

void zecimale(char* p, int& oprd, int& nr) // de la 10 la 99
{
    char cuvant[100];
    short int hit = 0;
    strcpy(cuvant, "zece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 10;
        hit = 1;
    }

    strcpy(cuvant, "unsprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 11;
        hit = 1;
    }

    strcpy(cuvant, "doisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 12;
        hit = 1;
    }

    strcpy(cuvant, "treisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 13;
        hit = 1;
    }

    strcpy(cuvant, "paisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 14;
        hit = 1;
    }

    strcpy(cuvant, "cincisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 15;
        hit = 1;
    }

    strcpy(cuvant, "saisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 16;
        hit = 1;
    }

    strcpy(cuvant, "saptesprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 17;
        hit = 1;
    }

    strcpy(cuvant, "optsprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 18;
        hit = 1;
    }

    strcpy(cuvant, "nouasprezece");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 19;
        hit = 1;
    }

    strcpy(cuvant, "douazeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 20;
        hit = 1;
    }

    strcpy(cuvant, "treizeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 30;
        hit = 1;
    }

    strcpy(cuvant, "patruzeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 40;
        hit = 1;
    }

    strcpy(cuvant, "cincizeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 50;
        hit = 1;
    }

    strcpy(cuvant, "saizeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 60;
        hit = 1;
    }

    strcpy(cuvant, "saptezeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 70;
        hit = 1;
    }

    strcpy(cuvant, "optzeci");
    if (strcmp(p, cuvant) == 0)
    {
        nr = nr + 80;
        hit = 1;
    }

    strcpy(cuvant, "nouazeci");
    if (strcmp(p, "nouazeci") == 0)
    {
        nr = nr + 90;
        hit = 1;
    }

    if (hit == 0)
        cifrele(p, oprd, nr);
}

void sute(char* p, int& oprd, int& nr, int& mid) // de la 100 la 999
{
    char cuvant[100];
    int hit = 0;
    strcpy(cuvant, "suta");
    if (strcmp(p, cuvant) == 0)
    {
        mid = 100;
        hit = 1;
        nr = 0;
    }
    strcpy(cuvant, "sute");
    if (strcmp(p, cuvant) == 0)
    {
        mid = nr * 100;
        hit = 1;
        nr = 0;
    }

    if (hit == 0)
        zecimale(p, oprd, nr);
}

void mii(char* p, int& oprd, int& nr, int& mid) // de la 1000 la 999999
{
    char cuvant[100];
    int hit = 0;
    strcpy(cuvant, "mie");
    if (strcmp(p, cuvant) == 0)
    {
        oprd = oprd + 1000;
        hit = 1;
    }
    strcpy(cuvant, "mii");
    if (strcmp(p, cuvant) == 0 && mid != 0 || strcmp(p, cuvant) == 0 && nr != 0)
    {
        if (nr != 0)
        {
            mid = mid + nr;
            nr = 0;
        }
        nr = nr + mid * 1000;
        mid = 0;
        hit = 1;
    }
    if (hit == 0)
        sute(p, oprd, nr, mid);
}
void milioane(char* p, int& oprd, int& nr, int& mid) // de la 1000000 la 999999999
{
    char cuvant[100];
    int hit = 0;
    strcpy(cuvant, "milion");
    if (strcmp(p, cuvant) == 0)
    {
        oprd = oprd + 1000000;
        hit = 1;
    }
    strcpy(cuvant, "milioane");
    if ((strcmp(p, cuvant) == 0 && mid != 0) || (strcmp(p, cuvant) == 0 && nr != 0))
    {
        if (nr != 0)
        {
            mid = mid + nr;
            nr = 0;
        }
        oprd = oprd + mid * 1000000;
        hit = 1;
        mid = 0;
    }
    if (hit == 0)
        mii(p, oprd, nr, mid);
}
int transformareInt(char s[101])
{
    int numar=0, cif=0;
    for (int i = 0 ; i < strlen(s) ; i++ )
    {
        cif=s[i]-'0';
        numar=numar*10+cif;
    }
    return numar;
}
void convertor(char propozitie[100])
{
    int oprd = 0, nr = 0, mid = 0;
    int oprd1 = 0, oprd2 = 0;
    float rez = 0;
    float a = 0, b = 0;
    float r = 0, rest = 0;
    char * p, sep[] = " ", aux[100];
    cout << "\n" << "Introduceti propozitia: " << endl;
    //cin.getline(propozitie, 100);
    //outtextxy(5,375,propozitie);
    strcat(aux, propozitie);
    p = strtok(propozitie, sep);
    while (p)
    {
        if ((strcmp(p, "cu") == 0) || (strcmp(p, " , ") == 0) || (strcmp(p, "la") == 0) || (strcmp(p, "ori") == 0) || (strcmp(p, "minus") == 0) || (strcmp(p, "scazut") == 0) || (strcmp(p, "plus") == 0) || (strcmp(p, "adunat") == 0))
        {
            if (nr != 0)
                oprd = oprd + nr;
            if (mid != 0)
                oprd = oprd + mid;
            oprd1 = oprd;
            oprd = 0;
            nr = 0;
            mid = 0;

        }
        char aux1[100];
        strcpy(aux1,p);
        if(isdigit(aux1[0]))
            oprd=transformareInt(aux1);
        milioane(p, oprd, nr, mid);

        p = strtok(NULL, sep);
    }
    if (nr != 0)
    {
        oprd = oprd + nr;

    }
    if (mid != 0)
    {
        oprd = oprd + mid;

    }
    oprd2 = oprd;
    eroare(aux);
    if (cautaAdunare(aux))
    {
        rez = oprd1 + oprd2;
        cout << "\n" << "Rezultatul este: " << numeNumar(rez) << endl;
        char *aux1 = new char [numeNumar(rez).length()+1];
        strcpy(aux1,numeNumar(rez).c_str());
        outtextxy(5, 395, "Rezultatul este :");
        outtextxy(260,395,aux1);
    }

    if (cautaScadere(aux))
    {
        rez = oprd1 - oprd2;
        if (rez >= 0)
        {
            cout << "\n" << "Rezultatul este: " << numeNumar(rez) << endl;
            char *aux1 = new char [numeNumar(rez).length()+1];
            strcpy(aux1,numeNumar(rez).c_str());
            outtextxy(5, 395, "Rezultatul este: ");
            outtextxy(260,395,aux1);
        }
        else
        {
            rez= abs(oprd1 - oprd2);
            cout << "\n" << "Rezultatul este: minus "<< numeNumar(rez) << endl;

            char *aux1 = new char [numeNumar(rez).length()+1];
            strcpy(aux1,numeNumar(rez).c_str());
            outtextxy(5, 395, "Rezultatul este :");
            outtextxy(260,395,"minus");
            outtextxy(340,395,aux1);
        }

    }

    if (cautaInmultire(aux))
    {
        rez = oprd1 * oprd2;
        cout << "\n" << "Rezultatul este: " << numeNumar(rez) << endl;
        char *aux1 = new char [numeNumar(rez).length()+1];
        strcpy(aux1,numeNumar(rez).c_str());
        outtextxy(5, 395, "Rezultatul este :");
        outtextxy(260,395,aux1);
    }

    if (cautaImpartire(aux) && oprd2 > 0)
    {
        rez = oprd1 / oprd2;
        if (oprd1 % oprd2 == 0)
        {
            cout << "\n" << "Rezultatul este: " << numeNumar(rez) << endl;
            char *aux1 = new char [numeNumar(rez).length()+1];
            strcpy(aux1,numeNumar(rez).c_str());
            outtextxy(5, 395, "Rezultatul este :");
            outtextxy(260,395,aux1);
        }
        else
        {
            a = oprd1;
            b = oprd2;
            r = (float)(a / b);
            cout << "\n" << "Rezultatul este: " << numeNumar(rez) << " virgula " << numeNumar((r - rez) * 10) << endl;
            char *aux1 = new char [numeNumar(rez).length()+1];
            strcpy(aux1,numeNumar(rez).c_str());
            outtextxy(5, 395, "Rezultatul este :");
            outtextxy(260,395,aux1);
            outtextxy(320,395,"virgula");
            char *aux5 = new char [numeNumar((r - rez)*10).length()+1];
            strcpy(aux5,numeNumar((r-rez)*10).c_str());
            outtextxy(440,395,aux5);
        }

    }
    else if (cautaImpartire(aux) && oprd2 == 0)
    {
        cout << "\n" << "Calcul imposibil" << endl;
        outtextxy(5, 395,"Calcul Imposibil");
    }

    //convertor();
}
vector<string> units{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> tens{ "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
vector<string> dtens{ "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety "};
string nameForNumber(long number)
{
    if (number < 10)
    {
        return units[number];
    }
    else if (number < 20)
    {
        return tens[number - 10];
    }
    else if (number < 100)
    {
        return dtens[number / 10] + ((number % 10 != 0) ? "-" + nameForNumber(number % 10) : "");
    }

    else if (number < 1000)
    {
        return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    }

    else if (number < 1000000)
    {
        return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    }

    else if (number < 1000000000)
    {
        return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    }

    else if (number < 1000000000000)
    {
        return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }

}
int keyWord(char* s1, char* s2)
{
    if (strstr(s1, s2))
        return true;
    return false;
}
bool searchGathering(char* s1)
{
    char gathering[5][20] = { "sum","gathering","plus","adding","added"};
    for (int i = 0; i < 5; i++)
    {
        if (keyWord(s1, gathering[i]))
        {
            return true;
        }

    }
    return false;
}
bool searchSubstraction(char* s1)
{
    char substraction[4][20] = {"substraction","minus","difference","substracted"};
    for (int i = 0; i < 4; i++)
    {
        if (keyWord(s1, substraction[i]))
        {
            return true;
        }

    }
    return false;
}
bool searchMultiplication(char* s1)
{
    char multiplication[3][20] = {"multiplying","multiplication", "multiplied"};
    for (int i = 0; i < 3; i++)
    {
        if (keyWord(s1, multiplication[i]))
        {
            return true;
        }

    }
    return false;
}
bool searchDivision(char* s1)
{
    char division[3][20] = {"dividing","divided","division"};
    for (int i = 0; i < 3; i++)
    {
        if (keyWord(s1, division[i]))
        {
            return true;
        }

    }
    return false;
}
void error(char* s1)
{
    if (!(searchGathering(s1) || searchSubstraction(s1) || searchMultiplication(s1) || searchDivision(s1)))
    {
        cout << "\n" << "Error: The sentence does not contain any operator" << "\n";
        outtextxy(5,395,"Error: The sentence does not contain any operator");
    }
}
void unit(char* p, int& oprd, int& nr) // de la 0 la 9
{
    char word[100];
    if (strcmp(p, word) == 0)
        nr = nr + 0;

    strcpy(word, "one");
    if (strcmp(p, word) == 0)
        nr = nr + 1;

    strcpy(word, "two");
    if (strcmp(p, word) == 0)
        nr = nr + 2;

    strcpy(word, "three");
    if (strcmp(p, word) == 0)
        nr = nr + 3;

    strcpy(word, "four");
    if (strcmp(p, word) == 0)
        nr = nr + 4;

    strcpy(word, "five");
    if (strcmp(p, word) == 0)
        nr = nr + 5;

    strcpy(word, "six");
    if (strcmp(p, word) == 0)
        nr = nr + 6;

    strcpy(word, "seven");
    if (strcmp(p, word) == 0)
        nr = nr + 7;

    strcpy(word, "eight");
    if (strcmp(p, word) == 0)
        nr = nr + 8;

    strcpy(word, "nine");
    if (strcmp(p, word) == 0)
        nr = nr + 9;

}

void ten(char* p, int& oprd, int& nr) // de la 10 la 99
{
    char word[100];
    short int hit = 0;
    strcpy(word, "ten");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 10;
        hit = 1;
    }

    strcpy(word, "eleven");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 11;
        hit = 1;
    }

    strcpy(word, "twelve");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 12;
        hit = 1;
    }

    strcpy(word, "thirteen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 13;
        hit = 1;
    }

    strcpy(word, "fourteen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 14;
        hit = 1;
    }

    strcpy(word, "fifteen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 15;
        hit = 1;
    }

    strcpy(word, "sixteen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 16;
        hit = 1;
    }

    strcpy(word, "seventeen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 17;
        hit = 1;
    }

    strcpy(word, "eighteen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 18;
        hit = 1;
    }

    strcpy(word, "nineteen");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 19;
        hit = 1;
    }

    strcpy(word, "twenty");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 20;
        hit = 1;
    }

    strcpy(word, "thirty");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 30;
        hit = 1;
    }

    strcpy(word, "fourty");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 40;
        hit = 1;
    }

    strcpy(word, "fifty");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 50;
        hit = 1;
    }

    strcpy(word, "sixty");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 60;
        hit = 1;
    }

    strcpy(word, "seventy");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 70;
        hit = 1;
    }

    strcpy(word, "eighty");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 80;
        hit = 1;
    }

    strcpy(word, "ninety");
    if (strcmp(p, word) == 0)
    {
        nr = nr + 90;
        hit = 1;
    }

    if (hit == 0)
        unit(p, oprd, nr);
}

void hundred(char* p, int& oprd, int& nr, int& mid) // de la 100 la 999
{
    char word[100];
    int hit = 0;
    strcpy(word, "hundred");
    if (strcmp(p, word) == 0)
    {
        mid = nr * 100;
        hit = 1;
        nr = 0;
    }


    if (hit == 0)
        ten(p, oprd, nr);
}

void thousand(char* p, int& oprd, int& nr, int& mid) // de la 1000 la 999999
{
    char word[100];
    int hit = 0;
    strcpy(word, "thousand");
    if (strcmp(p, word) == 0 && mid != 0 || strcmp(p, word) == 0 && nr != 0)
    {
        if (nr != 0)
        {
            mid = mid + nr;
            nr = 0;
        }
        nr = nr + mid * 1000;
        mid = 0;
        hit = 1;
    }
    if (hit == 0)
        hundred(p, oprd, nr, mid);
}
void million(char* p, int& oprd, int& nr, int& mid) // de la 1000000 la 999999999
{
    char word[100];
    int hit = 0;
    strcpy(word, "million");
    if ((strcmp(p, word) == 0 && mid != 0) || (strcmp(p, word) == 0 && nr != 0))
    {
        if (nr != 0)
        {
            mid = mid + nr;
            nr = 0;
        }
        oprd = oprd + mid * 1000000;
        hit = 1;
        mid = 0;
    }
    if (hit == 0)
        thousand(p, oprd, nr, mid);
}
int transformationInt(char s[101])
{
    int numar=0, cif=0;
    for (int i = 0 ; i < strlen(s) ; i++ )
    {
        cif=s[i]-'0';
        numar=numar*10+cif;
    }
    return numar;
}
void convertorEN(char sentence[100])
{
    int oprd = 0, pred = 0, mid = 0;
    int oprd1 = 0, oprd2 = 0;
    float rez = 0;
    float a = 0, b = 0;
    float r = 0, rest = 0;
    char * p, sep[] = " ", aux[100];
    cout << "\n" << "Type your sentence : " << endl;
    //cin.getline(sentence, 100);
    //outtextxy(5,375,sentence);
    strcat(aux, sentence);
    p = strtok(sentence, sep);
    while (p)
    {
        if ( (strcmp(p, "to") == 0) || (strcmp(p, "by") == 0) || (strcmp(p, "minus") == 0) || (strcmp(p, "substracted") == 0) || (strcmp(p, "plus") == 0) || (strcmp(p, "added") == 0))
        {
            if (pred != 0)
                oprd = oprd + pred;
            if (mid != 0)
                oprd = oprd + mid;
            oprd1 = oprd;
            oprd = 0;
            pred = 0;
            mid = 0;

        }
        char aux1[100];
        strcpy(aux1,p);
        if(isdigit(aux1[0]))
            oprd=transformationInt(aux1);
        million(p, oprd, pred, mid);
        p = strtok(NULL, sep);
    }
    if (pred != 0)
    {
        oprd = oprd + pred;

    }
    if (mid != 0)
    {
        oprd = oprd + mid;

    }
    oprd2 = oprd;
    error(aux);
    if (searchGathering(aux))
    {
        rez = oprd1 + oprd2;
        cout << "\n" << "The result is: " << nameForNumber(rez) << endl;
        char *aux1 = new char [nameForNumber(rez).length()+1];
        strcpy(aux1,nameForNumber(rez).c_str());
        outtextxy(5, 395, "The result is:");
        outtextxy(230,395,aux1);
    }

    if (searchSubstraction(aux))
    {
        rez = oprd1 - oprd2;
        if (rez >= 0)
        {
            cout << "\n" << "The result is: " << nameForNumber(rez) << endl;
            char *aux1 = new char [nameForNumber(rez).length()+1];
            strcpy(aux1,nameForNumber(rez).c_str());
            outtextxy(5, 395, "The result is: ");
            outtextxy(230,395,aux1);
        }
        else
        {
            rez = abs(oprd1 - oprd2);
            cout << "\n" << "The result is: minus " << nameForNumber(rez) << endl;
            char *aux1 = new char [nameForNumber(rez).length()+1];
            strcpy(aux1,nameForNumber(rez).c_str());
            outtextxy(5, 395, "The result is: minus");
            outtextxy(230,395,aux1);
        }
    }

    if (searchMultiplication(aux))
    {
        rez = oprd1 * oprd2;
        cout << "\n" << "The result is: " << nameForNumber(rez) << endl;
        char *aux1 = new char [nameForNumber(rez).length()+1];
        strcpy(aux1,nameForNumber(rez).c_str());
        outtextxy(5, 395, "The result is: ");
        outtextxy(230,395,aux1);
    }

    if (searchDivision(aux) && oprd2 > 0)
    {
        rez = oprd1 / oprd2;
        if (oprd1 % oprd2 == 0)
        {
            cout << "\n" << "The result is: " << nameForNumber(rez) << endl;
            char *aux1 = new char [nameForNumber(rez).length()+1];
            strcpy(aux1,nameForNumber(rez).c_str());
            outtextxy(5, 395, "The result is: ");
            outtextxy(230,395,aux1);
        }
        else
        {
            a = oprd1;
            b = oprd2;
            r = (float)(a / b);
            cout << "\n" << "The result is: " << nameForNumber(rez) << " point " << nameForNumber((r - rez) * 10) << endl;
            char *aux1 = new char [nameForNumber(rez).length()+1];
            strcpy(aux1,nameForNumber(rez).c_str());
            outtextxy(5, 395, "The result is: ");
            outtextxy(230,395,aux1);
            outtextxy(290,395," point ");
            char *aux5 = new char [nameForNumber((r - rez)*10).length()+1];
            strcpy(aux5,nameForNumber((r-rez)*10).c_str());
            outtextxy(410,395,aux5);

        }

    }
    else if (searchDivision(aux) && oprd2 == 0)
    {
        cout << "\n" << "Impossible calculation" << endl;
        outtextxy(5,395,"Impossible calculation");
    }

    //convertorEN();
}
vector<string> unite { "zero","un ", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf" };
vector<string> douzaines{ "dix ", "onze", "douze", "treize", "quatorze", "quinze","seize", "dix-sept", "dix-huit", "dix-neuf"};
vector<string> ddouzaines{ "", "", "vingt", "trente ", "quarante", "cinquante ", "soixante", "soixante-dix", "quatre-vingts", "quatre-vingt-dix"};
string nomPourNumero(long numero)
{
    if (numero < 10)
    {
        return unite[numero];
    }
    else if (numero < 20)
    {
        return douzaines[numero - 10];
    }
    else if (numero==21 || numero==31 || numero==41 ||numero==51 ||numero==61 ||numero==71 ||numero==81 ||numero==91)
    {
        return ddouzaines[numero / 10] + ((numero % 10 != 0) ? " et " + nomPourNumero(numero % 10) : "");
    }
    else if (numero < 100)
    {
        return ddouzaines[numero / 10] + ((numero % 10 != 0) ? "-" + nomPourNumero(numero % 10) : "");
    }
    else if (numero < 200)
    {
        return nomPourNumero(numero / 100) + " cent" + ((numero % 100 != 0) ? " " + nomPourNumero(numero % 100) : "");
    }
    else if (numero < 1000)
    {
        return nomPourNumero(numero / 100) + " cents" + ((numero % 100 != 0) ? " " + nomPourNumero(numero % 100) : "");
    }

    else if (numero < 1000000)
    {
        return nomPourNumero(numero / 1000) + " mille" + ((numero % 1000 != 0) ? " " + nomPourNumero(numero % 1000) : "");
    }
    else if (numero < 2000000)
    {
        return nomPourNumero(numero / 1000000) + "million" + ((numero % 1000000 != 0) ? " " + nomPourNumero(numero % 1000000) : "");
    }
    else if (numero < 1000000000)
    {
        return nomPourNumero(numero / 1000000) + "millions" + ((numero % 1000000 != 0) ? " " + nomPourNumero(numero % 1000000) : "");
    }
    else if (numero <2000000000)
    {
        return nomPourNumero(numero / 1000000000) + "milliards" + ((numero % 1000000000 != 0) ? " " + nomPourNumero(numero % 1000000000) : "");
    }
    else if (numero < 1000000000000)
    {
        return nomPourNumero(numero / 1000000000) + "milliards" + ((numero % 1000000000 != 0) ? " " + nomPourNumero(numero % 1000000000) : "");
    }

}
int motCle(char* s1, char* s2)
{
    if (strstr(s1, s2))
        return true;
    return false;
}
bool rechercherAddition(char* s1)
{
    char addition[6][20] = { "somme","addition","plus","ajoutes","ajoutee","ajout"};
    for (int i = 0; i < 6; i++)
    {
        if (motCle(s1, addition[i]))
        {
            return true;
        }

    }
    return false;
}
bool rechercherSoustraction(char* s1)
{
    char soustraction[4][20] = { "soustraction","moins","difference","soustrait"};
    for (int i = 0; i < 4; i++)
    {
        if (motCle(s1, soustraction[i]))
        {
            return true;
        }

    }
    return false;
}
bool rechercherMultiplication(char* s1)
{
    char multiplication[4][20] = { "multiplier","fois","multiplication", "multiplie"};
    for (int i = 0; i < 4; i++)
    {
        if (motCle(s1, multiplication[i]))
        {
            return true;
        }

    }
    return false;
}
bool rechercherDivision(char* s1)
{
    char division[3][20] = { "dividing","divise","division"};
    for (int i = 0; i < 3; i++)
    {
        if (motCle(s1, division[i]))
        {
            return true;
        }

    }
    return false;
}
void erreur(char* s1)
{
    if (!(rechercherAddition(s1) || rechercherSoustraction(s1) || rechercherMultiplication(s1) || rechercherDivision(s1)))

    {
        cout << "\n" << "Erreur : La phrase ne contient aucun operateur" << "\n";
        outtextxy(5,395,"Erreur : La phrase ne contient aucun operateur");
    }
}
void unites(char* p, int& oprd, int& nr) // de la 0 la 9
{
    char mot[100];
    if (strcmp(p, mot) == 0)
        nr = nr + 0;

    strcpy(mot, "un");
    if (strcmp(p, mot) == 0)
        nr = nr + 1;

    strcpy(mot, "deux");
    if (strcmp(p, mot) == 0)
        nr = nr + 2;

    strcpy(mot, "trois");
    if (strcmp(p, mot) == 0)
        nr = nr + 3;

    strcpy(mot, "quatre");
    if (strcmp(p, mot) == 0)
        nr = nr + 4;

    strcpy(mot, "cinq");
    if (strcmp(p, mot) == 0)
        nr = nr + 5;

    strcpy(mot, "six");
    if (strcmp(p, mot) == 0)
        nr = nr + 6;

    strcpy(mot, "sept");
    if (strcmp(p, mot) == 0)
        nr = nr + 7;

    strcpy(mot, "huit");
    if (strcmp(p, mot) == 0)
        nr = nr + 8;

    strcpy(mot, "neuf");
    if (strcmp(p, mot) == 0)
        nr = nr + 9;

}

void douzaine(char* p, int& oprd, int& nr) /// de la 10 la 90
{
    char mot[100];
    short int hit = 0;
    strcpy(mot, "dix");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 10;
        hit = 1;
    }

    strcpy(mot, "onze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 11;
        hit = 1;
    }

    strcpy(mot, "douze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 12;
        hit = 1;
    }

    strcpy(mot, "treize");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 13;
        hit = 1;
    }

    strcpy(mot, "quatorze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 14;
        hit = 1;
    }

    strcpy(mot, "quinze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 15;
        hit = 1;
    }

    strcpy(mot, "seize");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 16;
        hit = 1;
    }

    strcpy(mot, "dix-sept");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 17;
        hit = 1;
    }

    strcpy(mot, "dix-huit");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 18;
        hit = 1;
    }

    strcpy(mot, "dix-neuf");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 19;
        hit = 1;
    }

    strcpy(mot, "vingt");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 20;
        hit = 1;
    }

    strcpy(mot, "trente");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 30;
        hit = 1;
    }

    strcpy(mot, "quarante");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 40;
        hit = 1;
    }

    strcpy(mot, "cinquante");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 50;
        hit = 1;
    }

    strcpy(mot, "soixante");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 60;
        hit = 1;
    }

    strcpy(mot, "quatre-vingt");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 80;
        hit = 1;
    }
    strcpy(mot, "soixante-dix");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 70;
        hit = 1;
    }
    strcpy(mot, "soixante-onze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 71;
        hit = 1;
    }
    strcpy(mot, "soixante-douze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 72;
        hit = 1;
    }
    strcpy(mot, "soixante-treize");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 73;
        hit = 1;
    }
    strcpy(mot, "soixante-quatorze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 74;
        hit = 1;
    }
    strcpy(mot, "soixante-quinze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 75;
        hit = 1;
    }
    strcpy(mot, "soixante-seize");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 76;
        hit = 1;
    }
    strcpy(mot, "soixante-dix-sept");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 77;
        hit = 1;
    }
    strcpy(mot, "soixante-dix-huit");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 78;
        hit = 1;
    }
    strcpy(mot, "soixante-dix-neuf");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 79;
        hit = 1;
    }

    strcpy(mot, "quatre-vingt-dix");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 90;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-onze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 91;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-douze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 92;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-treize");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 93;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-quatorze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 94;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-quinze");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 95;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-seize");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 96;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-dix-sept");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 97;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-dix-huit");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 98;
        hit = 1;
    }
    strcpy(mot, "quatre-vingt-dix-neuf");
    if (strcmp(p, mot) == 0)
    {
        nr = nr + 99;
        hit = 1;
    }
    if (hit==0)
        unites(p,oprd,nr);
}
void cent(char* p, int& oprd, int& nr, int& mid) // de la 100 la 999
{
    char mot[100];
    int hit = 0;
    strcpy(mot, "cent");
    if (strcmp(p, mot) == 0)
    {
        mid = 100;
        hit = 1;
        nr = 0;
    }
    strcpy(mot, "cents");
    if (strcmp(p, mot) == 0)
    {
        mid = nr*100;
        hit = 1;
        nr = 0;
    }


    if (hit == 0)
        douzaine(p, oprd, nr);
}

void milles(char* p, int& oprd, int& nr, int& mid) // de la 1000 la 999999
{
    char mot[100];
    int hit = 0;
    strcpy(mot, "mille");
    if (strcmp(p, mot) == 0)
    {
        oprd = oprd + 1000;
        hit = 1;
    }
    strcpy(mot, "milles");
    if (strcmp(p, mot) == 0 && mid != 0 || strcmp(p, mot) == 0 && nr != 0)
    {
        if (nr != 0)
        {
            mid = mid + nr;
            nr = 0;
        }
        nr = nr + mid * 1000;
        mid = 0;
        hit = 1;
    }
    if (hit == 0)
        cent(p, oprd, nr, mid);
}
void millions(char* p, int& oprd, int& nr, int& mid) // de la 1000000 la 999999999
{
    char mot[100];
    int hit = 0;
    strcpy(mot, "million");
    if (strcmp(p, mot) == 0)
    {
        oprd = oprd + 1000000;
        hit = 1;
    }
    strcpy(mot, "millions");
    if ((strcmp(p, mot) == 0 && mid != 0) || (strcmp(p, mot) == 0 && nr != 0))
    {
        if (nr != 0)
        {
            mid = mid + nr;
            nr = 0;
        }
        oprd = oprd + mid * 1000000;
        hit = 1;
        mid = 0;
    }
    if (hit == 0)
        milles(p, oprd, nr, mid);
}
int transformasionInt(char s[101])
{
    int nombre=0, cif=0;
    for (int i = 0 ; i < strlen(s) ; i++ )
    {
        cif=s[i]-'0';
        nombre=nombre*10+cif;
    }
    return nombre;
}
void convertorFR(char sentence[100])
{
    int oprd = 0, pred = 0, mid = 0;
    int oprd1 = 0, oprd2 = 0;
    float rez = 0;
    float a = 0, b = 0;
    float r = 0, rest = 0;
    char * p, sep[] = " ", aux[100];
    strcat(aux, sentence);
    p = strtok(sentence, sep);
    while (p)
    {
        if ( (strcmp(p, " , ") == 0) || (strcmp(p, "par") == 0) || (strcmp(p, "moins") == 0) || (strcmp(p, "soustrait") == 0) || (strcmp(p, "plus") == 0) || (strcmp(p, "ajoutee") == 0))
        {
            if (pred != 0)
                oprd = oprd + pred;
            if (mid != 0)
                oprd = oprd + mid;
            oprd1 = oprd;
            oprd = 0;
            pred = 0;
            mid = 0;

        }
        char aux1[100];
        strcpy(aux1,p);
        if(isdigit(aux1[0]))
            oprd=transformasionInt(aux1);
        millions(p, oprd, pred, mid);

        p = strtok(NULL, sep);
    }
    if (pred != 0)
    {
        oprd = oprd + pred;

    }
    if (mid != 0)
    {
        oprd = oprd + mid;

    }
    oprd2 = oprd;
    erreur(aux);
    if (rechercherAddition(aux))
    {
        rez = oprd1 + oprd2;
        cout << "\n" << "Le resultat est: " << nomPourNumero(rez) << endl;
        char *aux1 = new char [nomPourNumero(rez).length()+1];
        strcpy(aux1,nomPourNumero(rez).c_str());
        outtextxy(5, 395, "Le resultat est:");
        outtextxy(230,395,aux1);
    }

    if (rechercherSoustraction(aux))
    {
        rez = oprd1 - oprd2;
        if (rez >= 0)
        {
            cout << "\n" << "Le resultat est: " << nomPourNumero(rez) << endl;
            char *aux1 = new char [nomPourNumero(rez).length()+1];
            strcpy(aux1,nomPourNumero(rez).c_str());
            outtextxy(5, 395, "Le resultat est:");
            outtextxy(230,395,aux1);
        }
        else
        {
            rez = abs(oprd1 - oprd2);
            cout << "\n" << "Le resultat est: moins " << nomPourNumero(rez) << endl;
            char *aux1 = new char [nomPourNumero(rez).length()+1];
            strcpy(aux1,nomPourNumero(rez).c_str());
            outtextxy(5, 395, "Le resultat est:");
            outtextxy(230,395,aux1);
        }
    }

    if (rechercherMultiplication(aux))
    {
        rez = oprd1 * oprd2;
        cout << "\n" << "Le resultat est: " << nomPourNumero(rez) << endl;
        char *aux1 = new char [nomPourNumero(rez).length()+1];
        strcpy(aux1,nomPourNumero(rez).c_str());
        outtextxy(5, 395, "Le resultat est:");
        outtextxy(230,395,aux1);
    }

    if (rechercherDivision(aux) && oprd2 > 0)
    {
        rez = oprd1 / oprd2;
        if (oprd1 % oprd2 == 0)
        {
            cout << "\n" << "Le resultat est: " << nomPourNumero(rez) << endl;
            char *aux1 = new char [nomPourNumero(rez).length()+1];
            strcpy(aux1,nomPourNumero(rez).c_str());
            outtextxy(5, 395, "Le resultat est:");
            outtextxy(230,395,aux1);
        }
        else
        {
            a = oprd1;
            b = oprd2;
            r = (float)(a / b);
            cout << "\n" << "Le resultat est: " << nomPourNumero(rez) << " point " << nomPourNumero((r - rez) * 10) << endl;
            char *aux1 = new char [nomPourNumero(rez).length()+1];
            strcpy(aux1,nomPourNumero(rez).c_str());
            outtextxy(5, 395, "Le resultat est:");
            outtextxy(230,395,aux1);
            outtextxy(290,395,"point");
            char *aux5 = new char [nomPourNumero((r - rez)*10).length()+1];
            strcpy(aux5,nomPourNumero((r-rez)*10).c_str());
            outtextxy(410,395,aux5);
        }

    }
    else if (rechercherDivision(aux) && oprd2 == 0)
    {
        cout << "\n" << "Calcul impossible" << endl;
        outtextxy(5,395,"Calcul impossible");
    }

    //convertor();
}
struct punct
{
    int x, y;
};

struct dreptunghi
{
    punct SS, DJ;
};

bool apartine(punct P, dreptunghi D)
{
    return D.SS.x<=P.x && P.x<=D.DJ.x && D.SS.y<=P.y && P.y<=D.DJ.y;

}

struct buton
{
    dreptunghi D;
    int culoare;
    char text[20];
};

buton B[6];
int nrButoane=5;
void deseneazaMeniul()
{
    settextstyle(3,HORIZ_DIR,1);
    setcolor(LIGHTGREEN);
    setfillstyle(SOLID_FILL,BLACK);
    int i;
    for (i=1; i<=nrButoane; i++)
    {
        B[i].D.SS.x=150*i;
        B[i].D.DJ.x=150*(i+1)-10;
        B[i].D.SS.y=240;
        B[i].D.DJ.y=265;
        switch(i)
        {
        case 1:
            strcpy(B[i].text,"Romana");
            break;
        case 2:
            strcpy(B[i].text,"Engleza");
            break;
        case 3:
            strcpy(B[i].text,"Franceza");
            break;
        case 4:
            strcpy(B[i].text,"Despre");
            break;
        case 5:
            strcpy(B[i].text,"IESIRE");
            break;
        }
        rectangle(B[i].D.SS.x, B[i].D.SS.y,B[i].D.DJ.x,B[i].D.DJ.y);
        bar(B[i].D.SS.x, B[i].D.SS.y+30, B[i].D.DJ.x, B[i].D.SS.y);
        setbkcolor(BLACK);
        outtextxy(B[i].D.SS.x+45,B[i].D.SS.y+10,B[i].text);
    }
    setcolor(WHITE);
    rectangle(0,350,getmaxx(),getmaxy());
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(525,500,WHITE);

}
void fundal()
{
    readimagefile("fundal.jpg",0,0,getmaxx(),350);
}
void titlu()
{
    setcolor(LIGHTCYAN);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
    outtextxy(60,100,"Calculator în limba romana, engleza, franceza");
}
int butonAles()
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=nrButoane; i++)
            if (apartine(p,B[i].D))
                return i;
    }
    return 0;
}
char s[100], *p;
int main()
{
    initwindow(1050,600);
    fundal();
    deseneazaMeniul();
    titlu();

    int comanda, butonul_apasat;
    do
    {
        butonul_apasat=butonAles();
        if (butonul_apasat == 1 )
        {
            cleardevice();
            fundal();
            deseneazaMeniul();
            titlu();
            setcolor(WHITE);
            settextstyle(0,HORIZ_DIR,2);
            outtextxy(5,355,"Introduceti propozitia:");
            char c, prop[100];
            int poz = 0;
            c = getch();
            while (c != 13)
            {
                if (c == 8)
                {
                    poz--;
                    prop[poz] = '\0';
                    cleardevice();
                    fundal();
                    deseneazaMeniul();
                    titlu();
                    setcolor(WHITE);
                    settextstyle(0,HORIZ_DIR,2);
                    outtextxy(5,355,"Introduceti propozitia:");
                }
                else
                {
                    prop[poz] = c;
                    poz++;
                    prop[poz] = '\0';
                }
                outtextxy(5, 375, prop);
                c = getch();
            }
            convertor(prop);

        }
        if (butonul_apasat == 2)
        {
            cleardevice();
            fundal();
            deseneazaMeniul();
            titlu();
            setcolor(WHITE);
            settextstyle(0,HORIZ_DIR,2);
            outtextxy(5,355,"Type your sentence:");
            char c, prop[100];
            int poz = 0;
            c = getch();
            while (c != 13)
            {
                if (c == 8)
                {
                    poz--;
                    prop[poz] = '\0';
                    cleardevice();
                    fundal();
                    deseneazaMeniul();
                    titlu();
                    setcolor(WHITE);
                    settextstyle(0,HORIZ_DIR,2);
                    outtextxy(5,355,"Type your sentence:");
                }
                else
                {
                    prop[poz] = c;
                    poz++;
                    prop[poz] = '\0';
                }
                outtextxy(5, 375, prop);
                c = getch();
            }
            convertorEN(prop);
        }
        if (butonul_apasat == 3)
        {
            cleardevice();
            fundal();
            deseneazaMeniul();
            titlu();
            setcolor(WHITE);
            settextstyle(0,HORIZ_DIR,2);
            outtextxy(5,355,"Ecrit la phrase:");
            char c, prop[100];
            int poz = 0;
            c = getch();
            while (c != 13)
            {
                if (c == 8)
                {
                    poz--;
                    prop[poz] = '\0';
                    cleardevice();
                    fundal();
                    deseneazaMeniul();
                    titlu();
                    setcolor(WHITE);
                    settextstyle(0,HORIZ_DIR,2);
                    outtextxy(5,355,"Ecrit la phrase:");
                }
                else
                {
                    prop[poz] = c;
                    poz++;
                    prop[poz] = '\0';
                }
                outtextxy(5, 375, prop);
                c = getch();
            }
            convertorFR(prop);
        }
        if (butonul_apasat == 4)
        {
            cleardevice();
            fundal();
            deseneazaMeniul();
            titlu();
            setcolor(WHITE);
            settextstyle(0,HORIZ_DIR,2);
            outtextxy(5,355,"Programul va putea face calcule simple de tipul operand1 operator operand2,");
            outtextxy(5,375,"în care operatorii sunt cei aritmetici (+,-,*,/) plecand de la o propozitie interogativa");
            outtextxy(5,395,"interogativa in limba romana, engleza sau franceza");
            outtextxy(5,515,"Proiect realizat de:");
            outtextxy(5,535,"Golache Denisa-Ioana");
            outtextxy(5,555,"Morarasu Catalin-Dimitrie");
        }
        if (butonul_apasat!=0)
        {
            comanda=butonul_apasat;
            cout<<"Comanda "<<comanda<<endl;
        }
    }
    while (comanda!=5);
    // getch();
    closegraph();
    return 0;
}
