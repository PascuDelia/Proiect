#include <iostream>
#include <string>
#include <map> // pentru a gestiona asocierea dintre litere si codurile lor
using namespace std;

int main()
{
    map<char,string> codificare; //map pt codificare,pt a asocia fiecare litera cu un cod n
    map<string, char>decodificare; // map pt decodificare
    string mesaj, mesaj_codificat;

    cout << "Limbaj secret \n";
    cout << "Introduceti codificarea pentru fiecare litera a alfabetului:\n";

    //citim de la tastatura codificarea pentru fiecare litera a alfabetului
    for(char litera='a';litera <='z';litera++)
    {
        string cod;
        cout << "cod pentru litera " << litera << ":";
        cin>>cod;
        codificare[litera]=cod; //asociem litera cu codul sau
        decodificare[cod]=litera; //asociem codul cu litera
    }

    //mapam literele mari la aceleasi coduri
    for(char litera= 'A';litera <= 'Z';litera++)
    {

        codificare[litera]=codificare[litera+32]; //litera +32=litera mica
        decodificare[codificare[litera]]=litera; //mapam invers si pentru litere mari
    }

    //codificam caractere speciale
    codificare[' ']=" "; //spatiul ramane spatiu
    codificare['.']="."; //punctele raman puncte
    codificare[',']=","; //virgulele raman virgule
    codificare['!']="!"; //semnul exclamarii
    codificare['?']="?"; //semnul intrebarii

    //decodificam caracterele speciale
    decodificare[" "]=' '; //spatiul ramane spatiu
    decodificare["."]='.'; //punctele raman puncte
    decodificare[","]=','; //virgulele raman virgule
    decodificare["!"]='!'; //semnul exclamarii
    decodificare["?"]='?'; //semnul intrebarii

    //citim mesajul de la utilizator
    cout<< "\nIntroduceti mesajul pe care vreti sa il codificati: ";
    cin.ignore(); //golim buffer-ul
    getline(cin,mesaj); //citim un sir intreg

    //codificam mesajul
    mesaj_codificat="";
    for(char c:mesaj) //procesam pe rand fiecare caracter din sirul mesajului
    {
        if(codificare.count(c))//verificam daca cheia c exista in map
        {
            mesaj_codificat+=codificare[c]+" "; //adaugam spatiu intre coduri
        }
        else
        {
            mesaj_codificat+="*"; //caracter necunoscut
        }
    }
    cout << "\nMesajul codificat este:\n" <<mesaj_codificat<<endl;

    //descifrare
    cout<<"\nIntroduceti mesajul codificat pentru descifrare:";
    string mesaj_de_codificat,cod,mesaj_descifrat="";
    cin.ignore(); //golim buffer-ul
    getline(cin,mesaj_de_codificat);

    //procesam fiecare cod(separat prin spatiu)
    size_t start=0,end;
    while((end=mesaj_de_codificat.find(' ',start))!=string::npos){
        cod=mesaj_de_codificat.substr(start,end-start); //extragem codul
        if(decodificare.count(cod)){ //daca codul exista in map-ul de decodificare
            mesaj_descifrat+=decodificare[cod];
        } else {
            mesaj_descifrat+="*"; //caracter necunoscut
        }
        start=end+1;//avansam la urmatorul cod
    }

    cout << "\nMesajul descifrat este:\n" << mesaj_descifrat << endl;
    return 0;
    }
