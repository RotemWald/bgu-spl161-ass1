#ifndef CYBER_EXPERT
#define CYBER_EXPERT

#include <iostream>
#include <string>
#include <vector>

#include "../include/cyberpc.h"
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"

using namespace std;

class CyberExpert
{
private:
	const std::string cyber_expert_name_;
	const int cyber_expert_work_time_;
	const int cyber_expert_rest_time_;
	const int cyber_expert_efficiency_;
	CyberExpert(); // Prevent the use of an empty constructor

	int rest_counter_;
	int work_counter_;
	bool is_rest_;

public:
	CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
	void Clean(CyberPC & cyber_pc);

	const std::string& getExpertName();
	const int& getExpertWorkTime() const;
	const int& getExpertRestTime() const;
	const int& getExpertefficiency() const;

	bool isReadytoStart();
	void endDay();
};

#endif
