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

//Proje ��lemleri Header Class
#pragma once
#include <string>
#include "Material.h"
using namespace std;

class Project
{
private:
	int projectId;
	string projectName;
	string projectCompanyName;
	string projectManager;
	string projectController;
	
public:

	int getProjectId() { return projectId; }
	string getProjectName() { return projectName; }
	string getProjectCompanyName() { return projectCompanyName; }
	string getProjectManager() { return projectManager; }
	string getProjectController() { return projectController; }

	void setProjectId(int id) { projectId = id; }
	void setProjectName(string name) { projectName = name; }
	void setProjectCompanyName(string companyName) { projectCompanyName = companyName; }
	void setProjectManager(string manager) { projectManager = manager; }
	void setProjectController(string controller) { projectController = controller; }

	static void writeProjectFile(Project& project, string fileName);
	static int getProjectCount(string fileName);

	static void removeProject(const char* file_name, int n);
	
	Project(int id, string name, string manager, string controller, string companyName)
	{
		setProjectId(id);
		setProjectCompanyName(companyName);
		setProjectController(controller);
		setProjectManager(manager);
		setProjectName(name);
	
	}

};

