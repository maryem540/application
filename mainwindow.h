#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fourniseur.h"
#include <QMainWindow>
#include "equipement.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_liste_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_listeF_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_listeE_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Fourniseur f;
    int resu;
    Equipement e;
};
#endif // MAINWINDOW_H
