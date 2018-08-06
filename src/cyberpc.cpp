#include "../include/cyberpc.h"

using namespace std;

CyberPC::CyberPC() : cyber_pc_os_(""), cyber_pc_name_(""), cyber_pc_connections_(), cyber_pc_time_to_infect_(-1) {
}

CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name) : cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name), cyber_pc_connections_(), cyber_pc_time_to_infect_(-1) {
}

const std::string CyberPC::getName() {
	return cyber_pc_name_;
}

void CyberPC::AddConnection(std::string second_pc) {
	// Let's add second PC name to our connections and print appropriate message
	cyber_pc_connections_.push_back(second_pc);
}

void CyberPC::InfectConnections(const CyberDNS & server) {
    vector<string>::iterator it;

    for (it = cyber_pc_connections_.begin(); it != cyber_pc_connections_.end(); ++it) {
    	CyberWorm* newWorm = new CyberWorm(*cyber_worm_);
    	server.GetCyberPC((*it)).Infect(*newWorm);
    }
}

void CyberPC::Infect(CyberWorm& worm) {
	// Let's check if worm OS is same as our computer
	if (cyber_pc_os_ == worm.getOs()) {
		if (0 != cyber_worm_) {
			delete cyber_worm_;
		}

		cyber_worm_ = &worm;
		cyber_pc_time_to_infect_ = worm.getDormancyTime();

		std::cout << "\t\t" << cyber_pc_name_ << " infected by " << worm.getName() << std::endl;
	}

	// Worm has another OS
	else {
		// Print suitable message
		std::cout << "\t\tWorm " << worm.getName() << " is incompatible with " << cyber_pc_name_ << std::endl;
		// Delete sent worm - we don't need it anymore
		delete &worm;
	}
}


void CyberPC::Run(const CyberDNS& server) {
	if (0 != cyber_worm_) {
		if ((cyber_pc_time_to_infect_==0) && (!cyber_worm_->isAwaken())) {
			std::cout << "\t" << cyber_pc_name_ << " infecting..." << std::endl;

			cyber_worm_->Awake();
			InfectConnections(server);
		}

		else if (!(cyber_worm_->isAwaken())) {
				std::cout << "\t" << cyber_pc_name_ << ": Worm " << cyber_worm_->getName() << " is dormant" << std::endl;
		}

		cyber_pc_time_to_infect_--;
	}
}

void CyberPC::Disinfect() {
	if (0 != cyber_worm_) {
		std::cout << "\t\t" << "Worm " << cyber_worm_->getName() << " successfully removed from " << cyber_pc_name_ << std::endl;

		// Let's set worm pointer to NULL, we don't need it anymore
		delete cyber_worm_;
		cyber_worm_ = NULL;

		// Let's reset time to infect (-1 means healthy computer)
		cyber_pc_time_to_infect_ = -1;
	}

	else {
		std::cout << "\t\t" << "No worm in " << cyber_pc_name_ << std::endl;
	}
}

CyberPC::~CyberPC() {
	if (0 != cyber_worm_) {
		delete cyber_worm_;
	}
}
