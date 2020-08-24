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
#pragma once
#include <string>

//Malzeme Ýþlemleri Header Class
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
