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

		//MEN�LER
		string mainMenu = "=============ANA MEN�============\n\n1. �r�n ��lemleri\n2. Proje ��lemleri\n3. Hakedi� ��lemleri\n0. ��k��\n\n=================================";
		string materialMenu = "========MALZEME ��LEMLER�========\n\n1. �r�n Ekle\n2. �r�n Listele\n3. �r�n Sil\n4. �r�n Arama\n5. Raporlama\n\n=================================";
		string projectMenu = "=========PROJE ��LEMLER�=========\n\n1. Proje Ekle\n2. Proje Listele\n3. Proje Sil\n4. Proje Arama\n5. Raporlama\n\n=================================";
		string deserveMenu = "========HAKED�� ��LEMLER�========\n\n1. �r�n Listele\n2. �r�n G�ncelle\n3. �r�n Ara\n4. �r�n Sil\n5. Hakedi� Ekle\n\n=================================";

		cout << mainMenu;

		cout << "\n\nSe�im: ";
		cin >> choice;

		if (choice == 0)//Uygulamadan ��k
		{
			cout << "��k�� Yap�ld�!";
		}
		else if (choice == 1) //Malzeme ��lemleri
		{
			system("CLS");

			cout << materialMenu;

			cout << "\n\nSe�im: ";
			cin >> choice;

			if (choice == 1) //Malzeme Ekleme B�l�m�
			{
				string name, brand, unitType;
				double unitPrice;

				system("CLS");

				cout << "===========�r�n Ekleme===========\n\n";

				cout << "�r�n �smi: ";
				cin >> name;
				
				cout << "�r�n Markas�: ";
				cin >> brand;

				cout << "�r�n Birimi: ";
				cin >> unitType;

				cout << "�r�n Birim Fiyat�: ";
				cin >> unitPrice;
			
				Material newMaterial(Material::getMaterialCount("mazeme.txt")+1, brand, name, unitPrice, unitType); //Malzemeyi Olu�tur

				newMaterial.writeMaterialFile(newMaterial, "mazeme.txt"); //Malzemeyi Ekle

				cout << "\n=================================\n\n��lem BA�ARILI, Ba�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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

				//Dosya ��lemleri
				ifstream file;

				file.open("mazeme.txt");

				file >> noskipws;

				string line;
				
				int lineCount = 0;
				cout << "===========�R�NLER===============\n\n";

				while (getline(file,line))
				{
					cout << line<<endl;
					lineCount++;
				}

				cout << "\n=================================\n\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			else if (choice == 3) //Malzeme Silme B�l�m�
			{		
				system("CLS");

				cout << "==========�R�N S�LME=============\n\n";

				int deletedMateriel;

				cout << "Silmek �stedi�iniz �r�n No: ";
				cin >> deletedMateriel;

				Material::removeMatariel("mazeme.txt", deletedMateriel);

				cout << "\n=================================\n\nSilme ��lemi BA�ARILI, Ba�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			else if (choice == 4)//Malzeme Arama B�l�m�
			{

				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========�R�N ARAMA=============\n\n";

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
							cout << "===========�R�N AYRINTI==========\n\n";
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
					cout << "Aranan �r�n Mevcut De�il!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			else if (choice == 5) //Malzeme Raporlama B�l�m�
			{

				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========�R�N RAPOR=============\n\n";

				inFile.open("mazeme.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}

				cout << "�r�n No: ";
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
							cout << "===========�R�N AYRINTI==========\n\n";
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
					cout << "Aranan �r�n Mevcut De�il!";
					cout << "\n=================================\n\n";
				}

				cout << "\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
		else if (choice == 2) {//Proje ��lemleri B�l�m�

			system("CLS");

			cout << projectMenu;

			cout << "\n\nSe�im: ";
			cin >> choice;
	
			if (choice==1)//Proje Ekle
			{		
				string name, companyName, manager, controller;

				system("CLS");
				cout << "===========Proje Ekleme===========\n\n";

				cout << "Proje �smi: ";
				cin >> name;

				cout << "Proje Y�r�t�c� Firma: ";
				cin >> companyName;

				cout << "Proje Sorumlusu: ";
				cin >> manager;
				
				cout << "Proje Kontol�r�: ";
				cin >> controller;


				Project newProject(Project::getProjectCount("projeler.txt") + 1, name, manager, controller, companyName); //Proje Olu�tur

				newProject.writeProjectFile(newProject, "projeler.txt");//Proje Yaz

				cout << "\n=================================\n\n��lem BA�ARILI, Ba�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
				cout << "\n=================================\n\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
				cout << "==========PROJE S�LME=============\n\n";

				int deletedProje;

				cout << "Silmek �stedi�iniz Proje Numaras�: ";
				cin >> deletedProje;
				Material::removeMatariel("projeler.txt", deletedProje);


				cout << "\n=================================\n\nSilme ��lemi BA�ARILI, Ba�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
					cout << "Aranan PROJE Mevcut De�il!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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

				cout << "==========�R�N RAPOR=============\n\n";

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
					cout << "Aranan PROJE Mevcut De�il!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
		else if (choice == 3) { //Hakedi� B�l�m�

			system("CLS");

			cout << deserveMenu;
			cin >> choice;
			system("CLS");

			
			if (choice == 1) //Projeye ait malzemeler
			{
			
				int dizi[20];
				string projectNo;

				cout << "Hakedi� Listelemek �stedi�iniz Proje No: ";
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

				cout << "\n=================================\n\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			if (choice == 2) {//Hakedi� G�NCELLE

				cout << "\n=================================\n\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			if (choice == 3) {//Hakedi� ARA
			
				string search;
				ifstream inFile;
				string line;

				system("CLS");

				cout << "==========HAKED�S ARAMA=============\n\n";

				inFile.open("mazeme.txt");

				if (!inFile) {
					cout << "============!!HATA!!=============\n\n" << endl;
					exit(1);
				}

				cout << "Hakedi� No: ";
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
							cout << "===========HAKED�� AYRINTI==========\n\n";
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
					cout << "Aranan Hakedi� Mevcut De�il!";
					cout << "\n=================================\n\n";
				}
				cout << "\nBa�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			if (choice == 4) {//Hakedi� S�L
				

				system("CLS");

				cout << "==========�R�N S�LME=============\n\n";

				int deletedMateriel;

				cout << "Silmek �stedi�iniz �r�n No: ";
				cin >> deletedMateriel;

				Material::removeMatariel("mazeme.txt", deletedMateriel);

				cout << "\n=================================\n\nSilme ��lemi BA�ARILI, Ba�ka bir i�lem yapmak istiyor musunuz?(E/?): ";
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
			if (choice == 5) //Hakedi� Ekle
			{
				string projectNumber, materialNumber;


				system("CLS");
				cout << "=================================\n";
				cout << "Hakdei� Eklemek �stedi�in Proje No: ";
				cin >> projectNumber;
				cout << "\nEklemek �stedi�in Malzeme: ";
				cin >> materialNumber;

				//hekedis.txt

				Deserve newDeserve(Deserve::getDeserveCount("hakedis.txt") + 1, projectNumber, materialNumber);

				newDeserve.writeDeserveFile(newDeserve, "hakedis.txt");


			}
		}

	} while (choice != 0);

	return 0;
}