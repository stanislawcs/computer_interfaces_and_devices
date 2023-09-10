#include "Menu.h"

void Menu::showMenu() {
	cout << "+---------------------------+" << endl;
	cout << "|1 - Power type             |" << endl;
	cout << "|2 - Battery life percent   |" << endl;
	cout << "|3 - Power mode             |" << endl;
	cout << "|4 - Enter sleep mode       |" << endl;
	cout << "|5 - Enter hibernate mode   |" << endl;
	cout << "|6 - Battery life time      |" << endl;
	cout << "|7 - Battery full life time |" << endl;
	cout << "|0 - Exit                   |" << endl;
	cout << "+---------------------------+" << endl;
}

void Menu::menu() {
	int choice;
	bool flag = true;
	PowerWorker pw;
	
	while (flag) {
		this->showMenu();
		cout << "Take the option" << endl;
		cin >> choice;
		switch (choice) {
		case 0 :
			return;
		case 1: 
			system("CLS");
			pw.getInfoAboutPowerType();
			flag = false;
			break;
		case 2 :
			system("CLS");
			pw.getBatteryLifePercent();
			flag = false;
			break;
		case 3:
			system("CLS");
			pw.getPowerMode();
			flag = false;
			break;
		case 4 :
			system("CLS");
			pw.enterSleepMode();
			flag = false;
			break;
		case 5 :
			system("CLS");
			pw.enterHibernateMode();
			flag = false;
			break;
		case 6 :
			system("CLS");
			pw.getBatteryLifeTime();
			flag = false;
			break;
		case 7 :
			system("CLS");
			pw.getBatteryFullLifeTime();
			flag = false;
			break;
		default: 
			system("CLS");
			cout << "Take a right variant" << endl;
			flag = false;
			break;
		}
		flag = true;
	}
}