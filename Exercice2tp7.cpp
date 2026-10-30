
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Facture {
private:
    struct Article {
        string nom;
        double prix;
        int quantite;
        double tva;
    };

    vector<Article> articles;

public:
    // Ajouter un article avec son nom et son prix
    void ajouterArticle(string nom, double prix) {
        articles.push_back({nom, prix, 1, 0});
    }

    // Ajouter un article avec une quantite
    void ajouterArticle(string nom, double prix, int quantite) {
        articles.push_back({nom, prix, quantite, 0});
    }

    // Ajouter un article avec une quantite et une TVA
    void ajouterArticle(string nom, double prix, int quantite, double tva) {
        articles.push_back({nom, prix, quantite, tva});
    }

    void afficherTotal() {
        double total = 0;

        for (const Article& a : articles) {
            double montant = a.prix * a.quantite;
            montant += montant * a.tva / 100;
            total += montant;
        }

        cout << "Total de la facture : " << total << " DH" << endl;
    }
};

int main() {
    Facture f;

    f.ajouterArticle("Stylo", 5.0);
    f.ajouterArticle("Cahier", 20.0, 3);
    f.ajouterArticle("Livre", 100.0, 2, 20.0);

    f.afficherTotal();

    return 0;
}
