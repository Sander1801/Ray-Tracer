#include "Engine.h"

#include <iostream>

Engine::Engine() : m_bIsRunning(false)
{
}

Engine::~Engine()
{
}

bool Engine::OnCreate()
{
	return false;
}

void Engine::OnDestroy()
{
	m_bIsRunning = false;
}
