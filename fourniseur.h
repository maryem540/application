#ifndef FOURNISEUR_H
#define FOURNISEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class Fourniseur
{
public:
    Fourniseur();
    Fourniseur(int,QString,QString,int,QString);
    //Getters
    int getID();
    QString getNom();
    QString getAdresse();
    int getNbMateriel();
    QString getType();

    //setters
    void setId(int id);
    void setNom(QString nom);
    void setAdresse(QString adresse);
    void setNbMateriel(int nb);
    void setType(QString type);
    //fct
    bool ajouterFourniseur();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer();
    Fourniseur afficherF(int id);


private :
    int id,NbMateriel;
    QString nom,adresse,type;

};

#endif // FOURNISEUR_H
