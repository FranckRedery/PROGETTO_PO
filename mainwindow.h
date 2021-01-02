/*This file is part of ProgettoPO-2020-2021-Reda-209394.

ProgettoPO-2020-2021-Reda-209394 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProgettoPO-2020-2021-Reda-209394 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProgettoPO-2020-2021-Reda-209394.  If not, see <http://www.gnu.org/licenses/>.*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestore.h"

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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_PAG_F_CERCA_CONFERENZE_COMUN_clicked();

    void on_pulsante_visualizza_Autori_clicked();

    void on_pulsante_visualizza_Riviste_clicked();

    void on_pulsante_visualizza_conferenze_clicked();

    void on_pulsante_visualizza_Articoli_clicked();

    void on_pulsante_aggiungi_autori_file_clicked();

    QString readFile(QString filename);

    void on_pulsante_aggiungi_riviste_file_clicked();

    void on_pulsante_aggiungi_conferenze_file_clicked();

    void on_pulsante_aggiungi_articolo_file_clicked();

    void on_articolo_add_autore_clicked();

    void on_articoli_aggiungi_correlato_clicked();

    void on_PAG_E_pulsante_riviste_spec_clicked();

    void on_sezione_f_articoli_influenzati_clicked();

private:
    Ui::MainWindow *ui;
    Gestore gestore;
};
#endif // MAINWINDOW_H
