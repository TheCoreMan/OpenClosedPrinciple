#pragma once

#include "Buffer.h"


class InterfaceToStorage {
public:
	virtual void store(const buffer& data) = 0;
};