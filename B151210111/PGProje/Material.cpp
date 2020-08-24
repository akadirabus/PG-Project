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

//Malzeme Ýþlemleri Main Class
#include "Material.h"
#include <fstream>
#include <locale.h>

void Material::writeMaterialFile(Material& material, string fileName)//Malzeme Yaz
{
	ofstream file;

	file.open(fileName, ios::app);

	file << material.getMaterialNo() << ". " << material.getMaterialBrand() << "-" << material.getMaterialName() << "-" << material.getMaterialUnitPrice() << "-" << material.getMaterialUnitType()<<"\n";

	file.close();
}

int Material::getMaterialCount(string fileName)//Malzeme Sayýsýný Getir
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

void Material::removeMatariel(const char* file_name, int n) //Malzeme Sil
{
    ifstream fin(file_name);
    ofstream fout;
    fout.open("temp.txt", ios::out);

    char ch;
    int line = 1;
    while (fin.get(ch))
    {
        if (ch == '\n')
            line++;

        if (line != n)    
            fout << ch;
    }
    fout.close();
    fin.close();
    remove(file_name);
    rename("temp.txt", file_name);
}
