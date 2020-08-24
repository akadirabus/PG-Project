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

//Hakedi� ��lemleri Header Class
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

