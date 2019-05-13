#pragma once
#include "Interface.h"

class MBase : public IModel
{

public:
	MBase() {};
	~MBase() {};

	virtual void Life(float t) = 0;
	virtual void Draw() = 0;

};

