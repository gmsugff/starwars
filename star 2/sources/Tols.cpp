#include "Tols.h"
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include "star.h"
Tols::Tols()
{
}

void Tols::showMenu() {
	std::cout << "1 - персонаж" << std::endl;
	std::cout << "2- Выход" << std::endl << std::endl;
	system("chcp 65001");
}

void Tols::showSchedule(int num)
{
	
	YaScheduleApp* app = new YaScheduleApp(num);
	std::vector <std::vector <std::map <std::string, std::string>>>fer;
	app->getCityCode(num);
	for (int i = 0; i < fer.size(); i++) {
		for (int j = 0; j < fer[i].size(); j++) {
			std::cout << fer[i][j][" Name"] << " ";
			std::cout << fer[i][j]["Birth Year"] << " ";
			std::cout << fer[i][j]["gender"] << " ";
			std::cout << fer[i][j]["height"] << " ";
			std::cout << fer[i][j]["mass"] << " " << endl << endl;

		}
	}
	system("chcp 1251");
}


