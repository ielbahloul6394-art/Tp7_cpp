
#include <iostream>
using namespace std;

class CompteBancaire {
private:
    double solde;
    int codeSecret;

public:
    // Constructeur sans solde initial
    CompteBancaire() {
        solde = 0;
        codeSecret = 1234;
    }

    // Constructeur avec solde initial
    CompteBancaire(double montant) {
        if (montant >= 0) {
            solde = montant;
        } else {
            solde = 0;
        }

        codeSecret = 1234;
    }

    void afficherSolde() {
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    // Retrait sans code de securite
    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide !" << endl;
        }
        else if (montant > solde) {
            cout << "Solde insuffisant !" << endl;
        }
        else {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        }
    }

    // Retrait avec code de securite
    void retrait(double montant, int code) {
        if (code != codeSecret) {
            cout << "Code de securite incorrect !" << endl;
        }
        else if (montant <= 0) {
            cout << "Montant invalide !" << endl;
        }
        else if (montant > solde) {
            cout << "Solde insuffisant !" << endl;
        }
        else {
            solde -= montant;
            cout << "Retrait securise effectue avec succes." << endl;
        }
    }
};

int main() {
    CompteBancaire compte1;
    CompteBancaire compte2(1500);

    cout << "Compte 1 :" << endl;
    compte1.afficherSolde();

    cout << "\nCompte 2 :" << endl;
    compte2.afficherSolde();

    cout << "\nPremier retrait :" << endl;
    compte2.retrait(200);
    compte2.afficherSolde();

    cout << "\nDeuxieme retrait :" << endl;
    compte2.retrait(300, 1234);
    compte2.afficherSolde();

    cout << "\nTest avec un code incorrect :" << endl;
    compte2.retrait(100, 9999);
    compte2.afficherSolde();

    return 0;
}
