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

    void on_pulsante_torna_menu_clicked();

    void on_pulsante_tornaalmenu_clicked();

    void on_pulsante_aggiungi_rivista_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
