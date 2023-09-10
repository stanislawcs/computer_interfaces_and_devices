#pragma once

#include <windows.h>
#include <powrprof.h>
#include <winbase.h>
#include <iostream>
#include <locale.h>

using namespace std;

class PowerWorker
{
private:
	SYSTEM_POWER_STATUS status;

public: 
	SYSTEM_POWER_STATUS getStatus();
	void getInfoAboutPowerType();
	void getBatteryLifePercent();
	void getPowerMode();
	void enterSleepMode();
	void enterHibernateMode();
	void getBatteryLifeTime();
	void getBatteryFullLifeTime();
	void convertTimeToNormalState(DWORD time);
};

