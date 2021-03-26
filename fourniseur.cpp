#include "fourniseur.h"
#include <QObject>
#include <QMessageBox>

Fourniseur::Fourniseur()
{
}
Fourniseur::Fourniseur(int id,QString nom,QString adresse,int nb_materiel,QString type)
{
    this->id=id;
    this->nom=nom;
    this->adresse=adresse;
    this->NbMateriel=nb_materiel;
    this->type=type;

}

int Fourniseur::getID(){
    return this->id;
}
QString Fourniseur::getNom()
{
    return this->nom;
}
QString Fourniseur::getType()
{
    return this->type;
}
QString Fourniseur::getAdresse()
{
    return this->adresse;
}
int Fourniseur::getNbMateriel(){
    return this->NbMateriel;
}

void Fourniseur::setId(int id)
{
    this->id=id;
}
void Fourniseur::setNom(QString nom)
{
    this->nom=nom;
}
void Fourniseur::setType(QString type)
{
    this->type=type;
}
void Fourniseur::setAdresse(QString adresse)
{
    this->adresse=adresse;
}

void Fourniseur::setNbMateriel(int nb)
{
    this->NbMateriel=nb;
}

bool Fourniseur::ajouterFourniseur()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into fourniseur (id,nom,adresse,nb_materiel,type_materiel) values (:id,:nom,:adresse,:nb_materiel,:type_materiel)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":nb_materiel",QString::number(NbMateriel));
    query.bindValue(":type_materiel",type);
    return query.exec();
}

bool Fourniseur::supprimer()
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Delete from fourniseur where id =:id ");
    query.bindValue(":id",res);
    return  query.exec();
}

QSqlQueryModel * Fourniseur::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from fourniseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_materiel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_materiel"));
    return model;

}
bool Fourniseur::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id);
query.prepare("update fourniseur set id=:id,nom=:nom,adresse=:adresse,nb_materiel=:nb_materiel,type_materiel=:type_materiel where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":nb_materiel",QString::number(NbMateriel));
    query.bindValue(":type_materiel",type);
    return query.exec();

}

Fourniseur Fourniseur::afficherF(int id)
{    QSqlQuery query;
     Fourniseur F;
      QString res = QString::number(id);
     query.prepare("select * from fourniseur where id ='"+res+"'");
     if(query.exec())
      {if(query.first())
       F.setId(query.value(0).toInt());
         F.setNom(query.value(1).toString());
         F.setAdresse(query.value(2).toString());
         F.setNbMateriel(query.value(3).toInt());
         F.setType(query.value(4).toString());

      }


    return F;
}










