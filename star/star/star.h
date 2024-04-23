
#pragma once
#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <vector>
using namespace std;
class YaScheduleApp {
	httplib::Client* starClient = new httplib::Client("https://swapi.dev");

	std::string peopleClient = ("/api/people/");
	std::string planetsClient = ("/api/planets/");
	std::string filmsClient = ("/api/films/");
	int num;

	std::vector <std::vector <std::map <std::string, std::string>>> schedule;
public:
	YaScheduleApp();
	YaScheduleApp(int& num);
	nlohmann::json makeRequest(httplib::Client* client, std::string request);
	std::string getCityCode(int& num);
	std::vector<std::vector <std::map <std::string, std::string>>> mapStarOpen();
	void showSchedule( int& num);

		

};