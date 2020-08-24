/****************************************************************************
** SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
** BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
** PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
** ÖDEV NUMARASI.............: I
** ÖÐRENCÝ ADI...............: ABDULKADÝR ABUÞ
** ÖÐRENCÝ NUMARASI..........: B151210111
** DERS GRUBU................: 1A
****************************************************************************/


//Hakediþ Ýþlemleri Main Class
#include "Deserve.h"
#include <fstream>
#include <locale.h>

void Deserve::writeDeserveFile(Deserve& deserve, string fileName)//Hakediþ Yaz
{
    ofstream file;

    file.open(fileName, ios::app);

    file << deserve.getProjectName() << ": " << deserve.getMaterialName() << "\n";

    file.close();
}

int Deserve::getDeserveCount(string fileName)//Hakediþ Getir
{
    ifstream file;

    file.open(fileName);
    file >> noskipws;

    string line;

    int lineCount = 0;

    while (getline(file, line))
    {
        lineCount++;
    }

    return lineCount;
}
