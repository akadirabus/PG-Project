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
#pragma once
#include <string>

//Malzeme ��lemleri Header Class
using namespace std;
class Material
{
private:
	int materialNo;
	string materialName;
	string materialUnitType;
	double materialUnitPrice;
	string materialBrand;

public:

	int getMaterialNo() { return materialNo; }
	string getMaterialName() { return materialName; }
	string getMaterialUnitType() { return materialUnitType; }
	double getMaterialUnitPrice() { return materialUnitPrice; }
	string getMaterialBrand() { return materialBrand; }

	void setMaterialNo(int no) { materialNo = no; }
	void setMaterialName(string name) { materialName = name; }
	void setMaterialUnitType(string unitType) { materialUnitType = unitType; }
	void setMaterialUnitPrice(double unitPrice) { materialUnitPrice = unitPrice; }
	void setMaterialBrand(string brand) { materialBrand = brand; }

	static void writeMaterialFile(Material &material, string fileName);
	static int getMaterialCount(string fileName);

	static void removeMatariel(const char* file_name, int n);

	Material(int no, string brand, string name, double unitPrice, string unitType) 
	{
		setMaterialBrand(brand);
		setMaterialName(name);
		setMaterialUnitPrice(unitPrice);
		setMaterialUnitType(unitType);
		setMaterialNo(no);
		
	}
};
