#include "../include/cyberexpert.h"
#include "../include/cyberpc.h"
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

CyberExpert::CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_): cyber_expert_name_(cyber_expert_name_), cyber_expert_work_time_(cyber_expert_work_time_), cyber_expert_rest_time_(cyber_expert_rest_time_), cyber_expert_efficiency_(cyber_expert_efficiency_), rest_counter_(0), work_counter_(0), is_rest_(false) {
}

void CyberExpert::Clean(CyberPC & cyber_pc) {
	std::cout << "\t" << getExpertName() << " examining " << cyber_pc.getName() << std::endl;
	cyber_pc.Disinfect();
}

const std::string& CyberExpert::getExpertName() {
	return cyber_expert_name_;
}

const int& CyberExpert::getExpertWorkTime() const {
	return cyber_expert_work_time_;
}

const int& CyberExpert::getExpertRestTime() const {
	return cyber_expert_rest_time_;
}

const int& CyberExpert::getExpertefficiency() const {
	return cyber_expert_efficiency_;
}

bool CyberExpert::isReadytoStart() {
	if (is_rest_ && cyber_expert_rest_time_ > 0) {
		return false;
	}

	return true;
}

void CyberExpert::endDay() {
	if (is_rest_) {
		rest_counter_++;

		if (rest_counter_ >= cyber_expert_rest_time_) {
			is_rest_=false;
			rest_counter_=0;

			std::cout << "\t" << cyber_expert_name_ << " is back to work" << std::endl;
		}
	}

	else {
		work_counter_++;

		if (work_counter_>=cyber_expert_work_time_) {
			is_rest_=true;
			work_counter_=0;

			std::cout << "\t" << cyber_expert_name_ << " is taking a break" << std::endl;
		}
	}
}
