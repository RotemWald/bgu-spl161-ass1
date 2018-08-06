#include "../include/cyberworm.h"

#include <iostream>
#include <string>
#include <vector>

CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time) : cyber_worm_os_(cyber_worm_os), cyber_worm_name_(cyber_worm_name), cyber_worm_dormancy_time_(cyber_worm_dormancy_time), isAwaken_(false) {
}

CyberWorm::CyberWorm(const CyberWorm& other) : cyber_worm_os_(other.getOs()), cyber_worm_name_ (other.getName()), cyber_worm_dormancy_time_ (other.getDormancyTime()), isAwaken_(false) {
}

const std::string& CyberWorm::getOs() const {
	return cyber_worm_os_;
}

const std::string& CyberWorm::getName() const {
	return cyber_worm_name_;
}

const int& CyberWorm::getDormancyTime() const {
	return cyber_worm_dormancy_time_;
}

void CyberWorm::Awake() {
	isAwaken_ = true;
}

bool CyberWorm::isAwaken() {
	return isAwaken_;
}
