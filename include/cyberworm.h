#ifndef CYBER_WORM
#define CYBER_WORM

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CyberWorm
{
private:
	const std::string cyber_worm_os_;
	const std::string cyber_worm_name_;
	const int cyber_worm_dormancy_time_;
	CyberWorm(); // Prevent the use of an empty constructor

	bool isAwaken_;

public:
	CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other); //copy constructor;

	const std::string& getOs() const;
	const std::string& getName() const;
	const int& getDormancyTime() const;

	void Awake();
	bool isAwaken();
};

#endif
