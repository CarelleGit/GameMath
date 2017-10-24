#pragma once
#include "rain.h"


class Emitter : public FObject
{
	float spawnAccumulator;

public:
	Emitter();
	int textureID;
	bool enable = true;
	// Collection of all particles
	FObject rock[100];

	// Current particle id.
	int rockId;

	// Time between each particle spawned.
	float spawnInterval;

	 void update() override;
	 void draw() override;

};
