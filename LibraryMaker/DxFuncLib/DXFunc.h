#pragma once

#include"ObjectIF.h"
#include<memory>

bool Init();

bool MainLoop();

bool Draw(const std::unique_ptr<ObjectIF> &obj);

bool UpDate(const std::unique_ptr<ObjectIF> &obj, Input *input);