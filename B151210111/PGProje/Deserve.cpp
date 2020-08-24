/****************************************************************************
** SAKARYA �N�VERS�TES�
** B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
** B�LG�SAYAR M�HEND�SL��� B�L�M�
** PROGRAMLAMAYA G�R��� DERS�
**
** �DEV NUMARASI.............: I
** ��RENC� ADI...............: ABDULKAD�R ABU�
** ��RENC� NUMARASI..........: B151210111
** DERS GRUBU................: 1A
****************************************************************************/


//Hakedi� ��lemleri Main Class
#include "Deserve.h"
#include <fstream>
#include <locale.h>

void Deserve::writeDeserveFile(Deserve& deserve, string fileName)//Hakedi� Yaz
{
    ofstream file;

    file.open(fileName, ios::app);

    file << deserve.getProjectName() << ": " << deserve.getMaterialName() << "\n";

    file.close();
}

int Deserve::getDeserveCount(string fileName)//Hakedi� Getir
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
