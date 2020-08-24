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

//Hakediþ Ýþlemleri Header Class
#pragma once
#include <string>
#include "Material.h"

using namespace std;

class Deserve
{
private:
	int deserveId;
	string projectName;
	string materialName;
	
public:
	int getDeservetId() { return deserveId; }
	string getProjectName() { return projectName; }
	string getMaterialName() { return materialName; }
	
	void setDeservetId(int id) { deserveId = id; }
	void setProjectName(string name) { projectName = name; }
	void setMaterialName(string m) { materialName = m; }

	static void writeDeserveFile(Deserve& project, string fileName);
	static int getDeserveCount(string fileName);

	Deserve(int id, string projectName, string materialName)
	{
		setDeservetId(id);
		setProjectName(projectName);
		setMaterialName(materialName);
	
	}
};

