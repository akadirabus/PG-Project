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

//Proje Main Class
#include <iostream>
#include <fstream>
#include "Material.h"
#include <locale.h>
#include "Project.h"
#include <iomanip>
#include "Deserve.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int choice;
	int input;
	char nextInput;

	do {

		//MENÜLER
		string mainMenu = "=============ANA MENÜ============\n\n1. Ürün Ýþlemleri\n2. Proje Ýþlemleri\n3. Hakediþ Ýþlemleri\n0. Çýkýþ\n\n=================================";
		string materialMenu = "========MALZEME ÝÞLEMLERÝ========\n\n1. Ürün Ekle\n2. Ürün Listele\n3. Ürün Sil\n4. Ürün Arama\n5. Raporlama\n\n=================================";
		string projectMenu = "=========PROJE ÝÞLEMLERÝ=========\n\n1. Proje Ekle\n2. Proje Listele\n3. Proje Sil\n4. Proje Arama\n5. Raporlama\n\n=================================";
		string deserveMenu = "========HAKEDÝÞ ÝÞLEMLERÝ========\n\n1. Ürün Listele\n2. Ürün Güncelle\n3. Ürün Ara\n4. Ürün Sil\n5. Hakediþ Ekle\n\n=================================";

		cout << mainMenu;

		cout << "\n\nSeçim: ";
		cin >> choice;

		if (choice == 0)//Uygulamadan Çýk
		{
			cout << "Çýkýþ Yapýldý!";
		}
		else if (choice == 1) //Malzeme Ýþlemleri
		{
			system("CLS");

			cout << materialMenu;

			cout << "\n\nSeçim: ";
			cin >> choice;

			if (choice == 1) //Malzeme Ekleme Bölümü
			{
				string name, brand, unitType;
				double unitPrice;

				system("CLS");

				cout << "===========Ürün Ekleme===========\n\n";

				cout << "Ürün Ýsmi: ";
				cin >> name;
				
				cout << "Ürün Markasý: ";
				cin >> brand;

				cout << "Ürün Birimi: ";
				cin >> unitType;

				cout << "Ürün Birim Fiyatý: ";
				cin >> unitPrice;
			
				Material newMaterial(Material::getMaterialCount("mazeme.txt")+1, brand, name, unitPrice, unitType); //Malzemeyi Oluþtur

				newMaterial.writeMaterialFile(newMaterial, "mazeme.txt"); //Malzemeyi Ekle

				cout << "\n=================================\n\nÝþlem BAÞARILI, Baþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput=='E' || nextInput=='e')
				{
					continue;
				}
				else 
				{
					break;
				}
				

			}
			else if (choice == 2)//Malzemeleri Listele
			{
				
				system("CLS");

				//Dosya Ýþlemleri
				ifstream file;

				file.open("mazeme.txt");

				file >> noskipws;

				string line;
				
				int lineCount = 0;
				cout << "===========ÜRÜNLER===============\n\n";

				while (getline(file,line))
				{
					cout << line<<endl;
					lineCount++;
				}

				cout << "\n=================================\n\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			else if (choice == 3) //Malzeme Silme Bölümü
			{		
				system("CLS");

				cout << "==========ÜRÜN SÝLME=============\n\n";

				int deletedMateriel;

				cout << "Silmek Ýstediðiniz Ürün No: ";
				cin >> deletedMateriel;

				Material::removeMatariel("mazeme.txt", deletedMateriel);

				cout << "\n=================================\n\nSilme Ýþlemi BAÞARILI, Baþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}

			}
			else if (choice == 4)//Malzeme Arama Bölümü
			{

				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========ÜRÜN ARAMA=============\n\n";

				inFile.open("mazeme.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}
				
				cout << "Mazeme No: ";
				cin >> search;


				size_t pos;

				// Search linde index;
				int x = 1;


				int projectCount = Project::getProjectCount("mazeme.txt");

				if (projectCount >= stoi(search) && 0 <= stoi(search))
				{
					while (inFile.good())
					{
						getline(inFile, line);
						pos = line.find(search);
						if (pos != string::npos)
						{
							// Project find Success;
							system("CLS");
							cout << "===========ÜRÜN AYRINTI==========\n\n";
							cout << line;
							cout << "\n=================================\n\n";
						}
						x++;
					}

				}
				else
				{
					
					system("CLS");
					cout << "=================================\n\n";
					cout << "Aranan Ürün Mevcut Deðil!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}


			}
			else if (choice == 5) //Malzeme Raporlama Bölümü
			{

				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========ÜRÜN RAPOR=============\n\n";

				inFile.open("mazeme.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}

				cout << "Ürün No: ";
				cin >> search;


				size_t pos;

				// Search linde index;
				int x = 1;


				int projectCount = Project::getProjectCount("mazeme.txt");

				if (projectCount >= stoi(search) && 0 <= stoi(search))
				{
					while (inFile.good())
					{
						getline(inFile, line);
						pos = line.find(search);
						if (pos != string::npos)
						{
							// Project find Success;
							system("CLS");
							cout << "===========ÜRÜN AYRINTI==========\n\n";
							cout << line;
							cout << "\n=================================\n\n";
						}
						x++;
					}

				}
				else
				{

					system("CLS");
					cout << "=================================\n\n";
					cout << "Aranan Ürün Mevcut Deðil!";
					cout << "\n=================================\n\n";
				}

				cout << "\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			 
		}
		else if (choice == 2) {//Proje Ýþlemleri Bölümü

			system("CLS");

			cout << projectMenu;

			cout << "\n\nSeçim: ";
			cin >> choice;
	
			if (choice==1)//Proje Ekle
			{		
				string name, companyName, manager, controller;

				system("CLS");
				cout << "===========Proje Ekleme===========\n\n";

				cout << "Proje Ýsmi: ";
				cin >> name;

				cout << "Proje Yürütücü Firma: ";
				cin >> companyName;

				cout << "Proje Sorumlusu: ";
				cin >> manager;
				
				cout << "Proje Kontolörü: ";
				cin >> controller;


				Project newProject(Project::getProjectCount("projeler.txt") + 1, name, manager, controller, companyName); //Proje Oluþtur

				newProject.writeProjectFile(newProject, "projeler.txt");//Proje Yaz

				cout << "\n=================================\n\nÝþlem BAÞARILI, Baþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
				
			}
			if (choice == 2)//Projeler Listele
			{
				
				ifstream file;

				file.open("projeler.txt");

				file >> noskipws;

				string line;

				int lineCount = 0;

				system("CLS");
				
				cout << "===========PROJELER==============\n\n";

				while (getline(file, line))
				{
					cout << line << endl;
					lineCount++;
				}
				cout << "\n=================================\n\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			if (choice == 3)//Proje Sil
			{		
				system("CLS");
				cout << "==========PROJE SÝLME=============\n\n";

				int deletedProje;

				cout << "Silmek Ýstediðiniz Proje Numarasý: ";
				cin >> deletedProje;
				Material::removeMatariel("projeler.txt", deletedProje);


				cout << "\n=================================\n\nSilme Ýþlemi BAÞARILI, Baþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			if (choice == 4)//Project Arama
			{			
				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========PROJE ARAMA=============\n\n";

				inFile.open("projeler.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}
				cout << "Proje No: ";
				cin >> search;


				size_t pos;
				
				int x = 1;

				
				int projectCount = Project::getProjectCount("projeler.txt");

				if (projectCount>=stoi(search) && 0<=stoi(search))
				{
					while (inFile.good())
					{
						getline(inFile, line);
						pos = line.find(search);
						if (pos != string::npos)
						{
							system("CLS");
							cout << "===========PROJE AYRINTI==========\n\n";
							cout << line;
							cout << "\n=================================\n\n";

						}
						x++;
					}

				}
				else 
				{
					system("CLS");
					cout << "=================================\n\n";
					cout << "Aranan PROJE Mevcut Deðil!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}


			}
			if (choice == 5)//Proje Raporlama
			{
						
				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========ÜRÜN RAPOR=============\n\n";

				inFile.open("projeler.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}
				cout << "Proje No: ";
				cin >> search;


				size_t pos;

				
				int x = 1;


				int projectCount = Project::getProjectCount("projeler.txt");

				if (projectCount >= stoi(search) && 0 <= stoi(search))
				{
					while (inFile.good())
					{
						getline(inFile, line);
						pos = line.find(search);
						if (pos != string::npos)
						{
							system("CLS");
							cout << "===========PROJE AYRINTI==========\n\n";
							cout << line;
							cout << "\n=================================\n\n";

						}
						x++;
					}

				}
				else
				{
					system("CLS");
					cout << "=================================\n\n";
					cout << "Aranan PROJE Mevcut Deðil!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}

			}
		}
		else if (choice == 3) { //Hakediþ Bölümü

			system("CLS");

			cout << deserveMenu;
			cin >> choice;
			system("CLS");

			
			if (choice == 1) //Projeye ait malzemeler
			{
			
				int dizi[20];
				string projectNo;

				cout << "Hakediþ Listelemek Ýstediðiniz Proje No: ";
				cin >> projectNo;

				system("CLS");

				cout << "==========PROJE MALZEMELER==========\n\n";

				ifstream file;

				file.open("hakedis.txt");

				file >> noskipws;

				string line;

				int lineCount = 0;

				while (getline(file, line))
				{
					cout << line << endl;
					lineCount++;

				}

				cout << "\n=================================\n\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
		
			}
			if (choice == 2) {//Hakediþ GÜNCELLE

				cout << "\n=================================\n\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}

			}
			if (choice == 3) {//Hakediþ ARA
			
				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========HAKEDÝS ARAMA=============\n\n";

				inFile.open("mazeme.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}

				cout << "Hakediþ No: ";
				cin >> search;


				size_t pos;

		
				int x = 1;


				int projectCount = Project::getProjectCount("hakedis.txt");

				if (projectCount >= stoi(search) && 0 <= stoi(search))
				{
					while (inFile.good())
					{
						getline(inFile, line);
						pos = line.find(search);
						if (pos != string::npos)
						{
							//Find Success;
							system("CLS");
							cout << "===========HAKEDÝÞ AYRINTI==========\n\n";
							cout << line;
							cout << "\n=================================\n\n";
						}
						x++;
					}

				}
				else
				{

					system("CLS");
					cout << "=================================\n\n";
					cout << "Aranan Hakediþ Mevcut Deðil!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBaþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}

			}
			if (choice == 4) {//Hakediþ SÝL
				

				system("CLS");

				cout << "==========ÜRÜN SÝLME=============\n\n";

				int deletedMateriel;

				cout << "Silmek Ýstediðiniz Ürün No: ";
				cin >> deletedMateriel;

				Material::removeMatariel("mazeme.txt", deletedMateriel);

				cout << "\n=================================\n\nSilme Ýþlemi BAÞARILI, Baþka bir iþlem yapmak istiyor musunuz?(E/?): ";
				cin >> nextInput;

				system("CLS");

				if (nextInput == 'E' || nextInput == 'e')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			if (choice == 5) //Hakediþ Ekle
			{
				string projectNumber, materialNumber;


				system("CLS");
				cout << "=================================\n";
				cout << "Hakdeiþ Eklemek Ýstediðin Proje No: ";
				cin >> projectNumber;
				cout << "\nEklemek Ýstediðin Malzeme: ";
				cin >> materialNumber;

				//hekedis.txt

				Deserve newDeserve(Deserve::getDeserveCount("hakedis.txt") + 1, projectNumber, materialNumber);

				newDeserve.writeDeserveFile(newDeserve, "hakedis.txt");


			}
		}

	} while (choice != 0);

	return 0;
}