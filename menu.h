#pragma once

#include "worker.h"
#include <vector>

class Menu
{
public:
    Menu();
    ~Menu();

public:
    void start();

private:
    bool showOptions();
    void showByExperience(const int& experience);
    void sortByExperience();
    void addWorker();

private:
    std::vector<Worker> workers;
};