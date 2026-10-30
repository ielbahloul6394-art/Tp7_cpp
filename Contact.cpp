
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    // Constructeur avec nom uniquement
    Contact(string n) {
        nom = n;
        telephone = "Non disponible";
        email = "Non disponible";
    }

    // Constructeur avec nom et telephone
    Contact(string n, string t) {
        nom = n;
        telephone = t;
        email = "Non disponible";
    }

    // Constructeur avec nom, telephone et email
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

int main() {
    Contact personne1("Imane");
    Contact personne2("Sara", "0612345678");
    Contact personne3("Youssef", "0623456789", "youssef@gmail.com");

    personne1.afficher();

    cout << "-------------------" << endl;

    personne2.afficher();

    cout << "-------------------" << endl;

    personne3.afficher();

    return 0;
}
