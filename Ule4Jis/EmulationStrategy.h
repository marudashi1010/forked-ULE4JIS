#pragma once

#include "Emulation.h"
#include "KeyCondition.h"
#include <map>
#include <memory>

//typedef boost::ptr_map<KeyCondition, Emulation> EmulationMapType;
typedef std::map<KeyCondition, std::unique_ptr<Emulation>> EmulationMapType;

class EmulationStrategy {
public:
	virtual ~EmulationStrategy();
	virtual void getEmulationMap(EmulationMapType *dest) = 0;
};

inline EmulationStrategy::~EmulationStrategy() {}
