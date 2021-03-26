#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include "fourniseur.h"
#include <QSqlQueryModel>
#include <QString>
class Equipement
{
public:
    Equipement();

    Equipement(int,int,QString,QString,int,int);

    //getter
    int getIdFourniseur();
    int getId();
    QString getNomEq();
    QString getMarque();
    int getStock();
    int getPrix();

    //setter
    void setIdFourniseur(int idF);
    void setID(int id);
    void setNomEq(QString  nomEq);
    void setMarque(QString marque);
    void setStock(int stock);
    void setPrix(int prix);
    bool ajouterEquipement();
    QSqlQueryModel * afficher(int id);
    bool modifier();
    bool supprimer();
   QList<Fourniseur>  afficherF();
   int recupererId(QString);
   Equipement afficherE(QString id);
   Equipement afficherEquipement(int id);
    QMap<int,Equipement> listeEq(int idF);
private :
    int id,id_fourniseur,stock,prix;
    QString nom_eq,marque;

};

#endif // EQUIPEMENT_H
