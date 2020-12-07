#ifndef AUTORE_H
#define AUTORE_H
#include <QString>
#include <QList>

class Autore
{

public:

    Autore();


private:

    int identificativo;
    QString nome;
    QString cognome;
    QList<QString> afferenze;
};

#endif // AUTORE_H
