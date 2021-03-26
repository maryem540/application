#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fourniseur.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //control de saisie ajout fourniseur
    ui->id->setValidator(new QIntValidator(0, 100000, this)) ;
    ui->nbMateriel->setValidator(new QIntValidator(0, 100000, this)) ;
    ui->nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->adresse->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->type->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));

    //control de saisie modifier fourniseur
    ui->id1->setValidator(new QIntValidator(0, 100000, this)) ;
    ui->nbMateriel1->setValidator(new QIntValidator(0, 100000, this)) ;
    ui->nom1->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->adresse1->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->type1->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    //aficher  liste fourniseuur
     ui->liste->setModel(f.afficher());
     /****************equipement******/
//coontrol de saisie
     ui->id2->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->prix2->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->stock2->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->nom2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->marque2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));


     //afficher dans combobox
     QStringList l;

     QList<Fourniseur> fi=e.afficherF();
     for(int i=0;i<fi.size();i++)
     {
   Fourniseur fo;
        fo=fi.at(i);
        l.append(fo.getNom());
     }ui->listeF->addItem("");
     ui->listeF->addItems(l);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    /******/

    int  id =ui->id->text().toInt();
    int nbMateriel=ui->nbMateriel->text().toInt();
    QString type =ui->type->text();
    QString nom=ui->nom->text();
    QString adresse=ui->adresse->text();
    Fourniseur fi(id,nom,adresse,nbMateriel,type);
    if( ui->id->text()=="" || ui->nbMateriel->text()=="" || ui->type->text()=="" || ui->nom->text()=="" || ui->adresse->text()=="")
    {QMessageBox::critical(nullptr, QObject::tr("Ajout fourniseur"),
                           QObject::tr("erreur.\n"
                                       "Veuillez remplir tous les champs"), QMessageBox::Cancel);

    }

    else
    {
    if(fi.ajouterFourniseur())
       { ui->liste->setModel(f.afficher());
        ui->listeF->addItem(fi.getNom());

        ui->id->setText("");
        ui->nom->setText("");
        ui->adresse->setText("");
        ui->type->setText("");
        ui->nbMateriel->setText("");
        QMessageBox::information(nullptr, QObject::tr("Ajout fourniseur"),
                                QObject::tr("add successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajout fourniseur"),
                               QObject::tr("add failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void MainWindow::on_pushButton_2_clicked()
{
    Fourniseur fi;
f=f.afficherF(ui->id1->text().toInt());
          fi=f.afficherF(ui->id1->text().toInt());

          QString nom=f.getNom();

                  fi.setId(ui->id1->text().toInt());
           fi.setNom(ui->nom1->text());
            fi.setType(ui->type1->text());
             fi.setAdresse(ui->adresse1->text());
              fi.setNbMateriel(ui->nbMateriel1->text().toInt());
              for(int i=0;i<ui->listeF->count();i++)
                                 {
                                     if(ui->listeF->itemText(i)==f.getNom())
                                        { ui->listeF->removeItem(i);


                                     ui->listeF->addItem(fi.getNom());
                                     }


                                 }

               if( ui->id1->text()=="" || ui->nbMateriel1->text()=="" || ui->type1->text()=="" || ui->nom1->text()=="" || ui->adresse1->text()=="")
               {QMessageBox::critical(nullptr, QObject::tr("Modifier fourniseur"),
                                      QObject::tr("erreur.\n"
                                                  "Veuillez remplir tous les champs"), QMessageBox::Cancel);

               }
    else{

                 if( fi.modifier())
              {



                     ui->liste->setModel(f.afficher());


                     ui->id1->setText("");
                     ui->nom1->setText("");
                     ui->adresse1->setText("");
                     ui->type1->setText("");
                     ui->nbMateriel1->setText("");
                          QMessageBox::information(nullptr, QObject::tr("Modifier fourniseur"),
                                      QObject::tr("Modify successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

              }else
              {
                  QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                     QObject::tr("Modify failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);


              }
     }
}

void MainWindow::on_liste_clicked(const QModelIndex &index)
{
    int id =ui->liste->model()->data(index).toInt();
    Fourniseur fi;
    fi=f.afficherF(id);


 ui->id1->setText(QString :: number(fi.getID()));
 ui->nom1->setText(fi.getNom());
 ui->adresse1->setText(fi.getAdresse());
 ui->type1->setText(fi.getType());
 ui->nbMateriel1->setText(QString::number(fi.getNbMateriel()));
}


void MainWindow::on_pushButton_3_clicked()
{
/*****************/

    f=f.afficherF(ui->id1->text().toInt());

    if( f.supprimer())
     {   for(int i=0;i<ui->listeF->count();i++)
        {
            if(ui->listeF->itemText(i)==f.getNom())
                ui->listeF->removeItem(i);
        }
        ui->liste->setModel(f.afficher());

            ui->id1->setText("");
            ui->nom1->setText("");
            ui->adresse1->setText("");
            ui->type1->setText("");
            ui->nbMateriel1->setText("");


                 QMessageBox::information(nullptr, QObject::tr("supprimer fourniseur"),
                             QObject::tr("delete successful.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

     }else
     {
         QMessageBox::critical(nullptr, QObject::tr("delete is not open"),
                            QObject::tr("Modify failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


     }
}
/**equipement****/

void MainWindow::on_listeF_currentIndexChanged(int index)
{

    int res=e.recupererId(ui->listeF->itemText(index));

  ui->listeE->setModel(e.afficher(res));
}

void MainWindow::on_pushButton_4_clicked()
{
    e.setID(ui->id2->text().toInt());
    e.setPrix(ui->prix2->text().toInt());
    e.setNomEq(ui->nom2->text());
    e.setStock(ui->stock2->text().toInt());
    e.setMarque(ui->marque2->text());
    int res=e.recupererId(ui->listeF->itemText(ui->listeF->currentIndex()));
    e.setIdFourniseur(res);

    if(ui->id2->text()=="" || ui->prix2->text()=="" || ui->nom2->text()=="" || ui->stock2->text()=="" || ui->prix2->text()=="" || ui->marque2->text()=="")
    {  QMessageBox::critical(nullptr, QObject::tr("ajout equipements"),
                             QObject::tr("Modify failed.\n"
                                         "Veuillez remplir tous les champs."), QMessageBox::Cancel);

    }else
   { if(e.ajouterEquipement())
    {   ui->liste->setModel(f.afficher());
        ui->listeE->setModel(e.afficher(res));

        ui->id2->setText("");
        ui->nom2->setText("");
        ui->prix2->setText("");
        ui->marque2->setText("");
        ui->stock2->setText("");
        QMessageBox::information(nullptr, QObject::tr("Ajout equipement"),
                                QObject::tr("add successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

    } else
        QMessageBox::critical(nullptr, QObject::tr("Ajout equipement"),
                           QObject::tr("add failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_5_clicked()
{
    e.setID(ui->id2->text().toInt());
    e.setPrix(ui->prix2->text().toInt());
    e.setNomEq(ui->nom2->text());
    e.setStock(ui->stock2->text().toInt());
    e.setMarque(ui->marque2->text());

if(ui->id2->text()=="" || ui->prix2->text()=="" || ui->nom2->text()=="" || ui->stock2->text()=="" || ui->prix2->text()=="" || ui->marque2->text()=="")
{  QMessageBox::critical(nullptr, QObject::tr("Modifier equipements"),
                         QObject::tr("Modify failed.\n"
                                     "Veuillez remplir tous les champs."), QMessageBox::Cancel);

}
else
               { if( e.modifier())
             {   ui->listeE->setModel(f.afficher());


                    ui->id2->setText("");
                    ui->nom2->setText("");
                    ui->prix2->setText("");
                    ui->stock2->setText("");
                    ui->marque2->setText("");
                         QMessageBox::information(nullptr, QObject::tr("Modifier equipement"),
                                     QObject::tr("Modify successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

             }else
             {
                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("Modify failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);


             }
}
}

void MainWindow::on_listeE_clicked(const QModelIndex &index)
{int id =ui->listeE->model()->data(index).toInt();
        Equipement eq;
        eq=e.afficherEquipement(id);
        ui->id2->setText(QString::number(id));
        ui->nom2->setText(eq.getNomEq());
         ui->marque2->setText(eq.getMarque());
          ui->stock2->setText(QString::number(eq.getStock()));
            ui->prix2->setText(QString::number(eq.getPrix()));

}

void MainWindow::on_pushButton_6_clicked()
{
    e.setID(ui->id2->text().toInt());
    int x=e.getId();

 Equipement i=e.afficherEquipement(x);
 int z=i.getIdFourniseur();
        if( e.supprimer())
         {
            ui->listeE->setModel(e.afficher(i.getIdFourniseur()));
                ui->id2->setText("");
                ui->nom2->setText("");
                ui->marque2->setText("");
                ui->stock2->setText("");
                ui->prix2->setText("");


                     QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                                 QObject::tr("delete successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

         }else
         {
             QMessageBox::critical(nullptr, QObject::tr("delete is not open"),
                                QObject::tr("Modify failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


         }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    /*QStringList l;

    QList<Fourniseur> fi=e.afficherF();
    for(int i=0;i<fi.size();i++)
    {  ui->listeF->removeItem(i);
  Fourniseur fo;

       fo=fi.at(i);
       l.append(fo.getNom());
    }ui->listeF->addItem("");
    ui->listeF->addItems(l);*/
}
