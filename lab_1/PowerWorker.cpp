#include "PowerWorker.h"

SYSTEM_POWER_STATUS PowerWorker::getStatus() {
	GetSystemPowerStatus(&(this->status));
	return this->status;
}

void PowerWorker::getInfoAboutPowerType() {

	SYSTEM_POWER_STATUS status = this->getStatus();

	switch (status.ACLineStatus) {
	case 0 :
		cout << "Offline" << endl;
		break;

	case 1 : 
		cout << "Online" << endl;
		break;

	default: 
		cout << "Unknown status" << endl;
		break;
	}
}

void PowerWorker::getBatteryLifePercent() {

	SYSTEM_POWER_STATUS status = this->getStatus();
	cout << "Battery life percent" << endl;
	cout << static_cast<int>(status.BatteryLifePercent) << endl;
}

void PowerWorker::getPowerMode() {
	SYSTEM_POWER_STATUS status = this->getStatus();

	switch (status.BatteryFlag) {
	case 0: 
		cout << "the battery is not being charged and the battery capacity is between low and high" << endl;
		break;
	case 1 : 
		cout << "High - the battery capacity is at more than 66 percent" << endl;
		break;
	case 2 : 
		cout << "Low - the battery capacity is at less than 33 percent" << endl;
		break;
	case 4:
		cout << "Critical - the battery capacity is at less than five percent" << endl;
	case 8:
		cout << "Charging" << endl;
		break;
	case 128:
		cout << "No system battery" << endl;
		break;
	case 255:
		cout << "Unknown status - unable to read the battery flag information" << endl;
		break;
	}
}

void PowerWorker::enterSleepMode() {
	if (SetSuspendState(FALSE, FALSE, FALSE)) {
		std::cout << "Go to sleep mode..." << std::endl;
	}
	else {
		std::cerr << "Failed to move into sleep mode" << std::endl;
	}
}

void PowerWorker::enterHibernateMode() {

	if (SetSuspendState(TRUE, FALSE, FALSE)) {
		std::cout << "Go to hibernate mode..." << std::endl;
	}
	else {
		std::cerr << "Failed to move into hibernate mode" << std::endl;
	}
}

void PowerWorker::convertTimeToNormalState(DWORD time) {
	cout << "Hours: " << time / 3600 << endl;
	cout << "Minutes: " << time % 3600 / 60 << endl;
	cout << "Seconds: " << time % 3600 % 60 / 60 << endl;
}

void PowerWorker::getBatteryLifeTime() {
	SYSTEM_POWER_STATUS status = this->getStatus();
	if (static_cast<int>(status.BatteryFlag) == 8) {
		cout << "Battery charging" << endl;
		return;
	}
	else if (status.BatteryLifeTime == -1) {
		cout << "Unknown" << endl;
	}
	this->convertTimeToNormalState(status.BatteryLifeTime);
}

void PowerWorker::getBatteryFullLifeTime() {
	SYSTEM_POWER_STATUS status = this->getStatus();
	if (static_cast<int>(status.BatteryFlag) == 8) {
		cout << "Battery charging" << endl;
		return;
	}
	else if (status.BatteryFullLifeTime == -1) {
		cout << "Unknown" << endl;
	}

	this->convertTimeToNormalState(status.BatteryFullLifeTime);
}