#include "equipement.h"

Equipement::Equipement()
{

}
Equipement::Equipement(int id,int idF,QString nom,QString marque,int stock,int prix)
{
    this->id=id;
    this->id_fourniseur=idF;
    this->nom_eq=nom;
    this->marque=marque;
    this->stock=stock;
    this->prix=prix;

}

int Equipement::getId()
{
    return this->id;
}
int Equipement::getPrix()
{
    return this->prix;
}
int Equipement::getStock()
{
    return this->stock;
}
int Equipement ::getIdFourniseur()
{
    return this->id_fourniseur;
}
QString Equipement::getNomEq()
{
    return  this->nom_eq;
}
QString Equipement::getMarque()
{
    return this->marque;
}
void Equipement::setID(int id)
{
    this->id=id;
}
void Equipement::setPrix(int prix)
{
    this->prix=prix;
}
void Equipement::setIdFourniseur(int idF)
{
    this->id_fourniseur=idF;
}
void Equipement::setNomEq(QString nomEq)
{
    this->nom_eq=nomEq;
}
void Equipement::setStock(int stock)
{
    this->stock=stock;
}
void Equipement::setMarque(QString marque)
{
    this->marque=marque;
}
QSqlQueryModel * Equipement::afficher(int id)
{ QString res= QString::number(id);
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select id,nom_eq,marque,stock,prix from equipement where id_fourniseur='"+res+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Marque"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("stock"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));

    return model;

}

bool Equipement::ajouterEquipement()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into equipement (id,id_fourniseur,nom_eq,marque,stock,prix) values (:id,:id_fourniseur,:nom_eq,:marque,:stock,:prix)");
    query.bindValue(":id",res);
    query.bindValue(":id_fourniseur",QString::number(id_fourniseur));
    query.bindValue(":nom_eq",nom_eq);
    query.bindValue(":marque",marque);
    query.bindValue(":stock",QString::number(stock));
    query.bindValue(":prix",QString::number(prix));

    return query.exec();

}

bool Equipement::supprimer()
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Delete from equipement where id =:id ");
    query.bindValue(":id",res);
    return  query.exec();
}
bool Equipement::modifier()
{

    QSqlQuery query;
    QString res = QString::number(id);
query.prepare("update equipement set nom_eq=:nom_eq,marque=:marque,stock=:stock,prix=:prix where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom_eq",nom_eq);
    query.bindValue(":marque",marque);
    query.bindValue(":stock",QString::number(stock));
    query.bindValue(":prix",QString::number(prix));
    return query.exec();
}
QList<Fourniseur> Equipement::afficherF()
{
    QList<Fourniseur> f;
    QSqlQuery query;
        query.prepare("select id,nom from fourniseur ");
        if(query.exec())
         {while(query.next())
            {
                Fourniseur F;
          F.setId(query.value(0).toInt());
          F.setNom(query.value(1).toString());
          f.append(F);

         }}
        return f;


}
int Equipement::recupererId(QString nom)
{QSqlQuery query;
    int id=0;
    query.prepare("select * from fourniseur where nom='"+nom+"'");
    if(query.exec())
     {if(query.first())
        {id=query.value(0).toInt();

     }}
    return id;
}


Equipement Equipement::afficherEquipement(int id)
{
    QSqlQuery query;
        Equipement ei;
         QString res = QString::number(id);
        query.prepare("select * from equipement where id ='"+res+"'");
        if(query.exec())
         {if(query.first())

          ei.setID(query.value(0).toInt());
            ei.setIdFourniseur(query.value(1).toInt());
            ei.setNomEq(query.value(2).toString());
            ei.setMarque(query.value(3).toString());
            ei.setPrix(query.value(5).toInt());
            ei.setStock(query.value(4).toInt());

         }


       return ei;
}
