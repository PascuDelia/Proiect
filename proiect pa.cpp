#include <iostream>
#include <string>
#include <map> //Pentru a gestiona asocierea dintre litere si codurile lor
using namespace std;

int main()
{
    map<char, string> codificare;  // Map pentru codificare,pt a asocia fiecare litera cu un cod n
    map<string, char> decodificare;  // Map pentru decodificare
    string mesaj, mesaj_codificat;

    cout << "Limbaj Secret \n";
    cout << "Introduceti codificarea pentru fiecare litera a alfabetului:\n";

    // Citim de la tastatură codificarea pentru fiecare literă a alfabetului
    for (char litera = 'a'; litera <= 'z'; litera++)
    {
        string cod;
        cout << "Cod pentru litera '" << litera << "': ";
        cin >> cod;
        codificare[litera] = cod;       // Asociem litera cu codul său
        decodificare[cod] = litera;    // Asociem codul cu litera
    }

    // Mapăm literele mari la aceleași coduri
    for (char litera = 'A'; litera <= 'Z'; litera++)
    {
        codificare[litera] = codificare[litera + 32]; // litera + 32 = litera mică
        decodificare[codificare[litera]] = litera;   // Mapăm invers și pentru litere mari
    }

    // Codificăm caractere speciale
    codificare[' '] = " "; // Spațiul rămâne spațiu
    codificare['.'] = "."; // Punctele rămân puncte
    codificare[','] = ","; // Virgulele rămân virgule
    codificare['!'] = "!"; // Semnul exclamării
    codificare['?'] = "?"; //Semnul întrebării

    //Decodificam caracterele speciale
    decodificare[" "] = ' '; // Spațiul rămâne spațiu
    decodificare["."] = '.'; // Punctele rămân puncte
    decodificare[","] = ','; // Virgulele rămân virgule
    decodificare["!"] = '!'; // Semnul exclamării
    decodificare["?"] = '?'; // Semnul întrebării

    // Citim mesajul de la utilizator
    cout << "\nIntroduceti mesajul pe care vreti sa il codificati: ";
    cin.ignore(); // Golim buffer-ul
    getline(cin, mesaj); // Citim un șir întreg

    // Codificăm mesajul
    mesaj_codificat = "";
    for (char c : mesaj) //procesam pe rand fiecare carcater din sirul mesajului
{
        if (codificare.count(c))  // Verificam daca cheia c există în map
        {
            mesaj_codificat += codificare[c] + " "; //adaugam spatiu intre coduri
        }
        else
        {
            mesaj_codificat += "*"; // Caracter necunoscut
        }
    }

    cout << "\nMesajul codificat este: \n" << mesaj_codificat << endl;

    // Descifrare
    cout << "\nIntroduceti mesajul codificat pentru descifrare: ";
    string mesaj_de_codificat, cod, mesaj_descifrat = "";
    cin.ignore(); // Golim buffer-ul
    getline(cin, mesaj_de_codificat);

    // Procesăm fiecare cod (separat prin spațiu)
    size_t start = 0, end;
    while ((end = mesaj_de_codificat.find(' ', start)) != string::npos) {
        cod = mesaj_de_codificat.substr(start, end - start); // Extragem codul
        if (decodificare.count(cod)) { // Dacă codul există în map-ul de decodificare
            mesaj_descifrat += decodificare[cod];
        } else {
            mesaj_descifrat += "*"; // Caracter necunoscut
        }
        start = end + 1; // Avansăm la următorul cod
    }

    cout << "\nMesajul descifrat este: \n" << mesaj_descifrat << endl;
    return 0;
}
