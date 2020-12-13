#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_go_pag_autori_clicked();

    void on_aggiungi_autore_clicked();

    void on_go_pag_riviste_clicked();

    void on_pulsante_aggiungi_rivista_clicked();

    void on_pulsante_aggiungi_conferenza_clicked();

    void on_go_pag_conferenze_clicked();

    void on_backtohome();

    void on_pulsante_pag_aggiungiArticolo_clicked();

    void on_pushButton_clicked();

    void on_SEZIONE_B_clicked();

    void on_SEZIONEB_PULSANTE_VISUALIZZA_clicked();

    void on_SEZIONE_C_PULSANTE_CONFERMA_clicked();

    void on_SEZIONE_C_clicked();

    void on_PAG_D_PULSANTE_CONFERMA_clicked();

    void on_pulsante_sezione_D_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
