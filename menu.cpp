#include "menu.h"

#include <iostream>
#include <chrono>

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::showByExperience(const int& experience)
{
    const std::chrono::time_point now{std::chrono::system_clock::now()};

    std::time_t today = std::chrono::system_clock::to_time_t(now);
    std::tm today_local_tm = *localtime(&today);
    int year = today_local_tm.tm_year + 1900;

    std::vector<std::string> matching_workers;

    for(std::vector<Worker>::iterator it = workers.begin(); it != workers.end(); ++it){
        if(year - it->getEnlistmentYear() >= experience){
            FullName full_name = it->getName();
            matching_workers.push_back(full_name.surname);
        }
    }
    if(matching_workers.empty()){
        std::cout << "No fitting workers!" << '\n';
        return;
    }
    std::cout << "List of workers' surnames which fit the experience requirement:" << '\n';
    for(std::vector<std::string>::const_iterator it = matching_workers.begin(); it != matching_workers.end(); ++it){
        std::cout << *it.base() << '\n';
    }

}

void Menu::sortByExperience()
{
    std::cout << "Enter desired experience:" << '\n';
    int experience;
    std::cin >> experience;
    showByExperience(experience);
}

static std::string parseName()
{
    std::cout << "Enter name:" << '\n';
    std::string name;
    std::cin >> name;
    return name;
}

static std::string parseSurname()
{
    std::cout << "Enter surname:" << '\n';
    std::string surname;
    std::cin >> surname;
    
    return surname;
}

static std::string parsePatronymic()
{
    std::cout << "Enter patronymic:" << '\n';
    std::string patronymic;
    std::cin >> patronymic;
    return patronymic;
}

static FullName parseFullName()
{
    std::string name = parseName();    
    std::string surname = parseSurname();    
    std::string patronymic = parsePatronymic();    
    
    return FullName{name, surname, patronymic};
}

static JobTitle parseJobTitle()
{
    std::cout << "Pick a job title:" << '\n';
    size_t job_title_matches_size = sizeof(job_title_matches) / sizeof(job_title_matches[0]);
    for(int i = 0; i < job_title_matches_size ; ++i){
        std::cout << i << " " << job_title_matches[i].job_title << '\n';
    }
    int job_enum = 0;
    std::cin >> job_enum;
    while(job_enum < 0 || job_enum >= job_title_matches_size){
        std::cout << "No such job title. Try again!" << '\n';
        std::cin >> job_enum;
    }

    return JobTitle(job_enum);
}

static double parseSalary()
{
    std::cout << "Enter salary:" << '\n';
    double salary = 0;
    std::cin >> salary;
    return salary;
}

static double parseEnlistmentYear()
{
    std::cout << "Enter enlistment year:" << '\n';
    int year = 0;
    std::cin >> year;
    return year;
}

void Menu::addWorker()
{
    FullName full_name = parseFullName();
    JobTitle job_title = parseJobTitle();
    double salary = parseSalary();
    double enlistment_year = parseEnlistmentYear();
    
    workers.push_back(Worker(full_name, job_title, salary, enlistment_year));
}

bool Menu::showOptions()
{
    std::cout << "Pick an option by number:" << '\n';
    std::cout << "1. Add new worker" << '\n';
    std::cout << "2. List workers based on experience" << '\n';
    std::cout << "3. Exit" << '\n';
    int option = 0;
    std::cin >> option;
    switch(option)
    {
        case 1:
            addWorker();
            break;
        case 2:
            sortByExperience();
            break;
        case 3:
            return false;
            break;
        default:
            std::cout << "No such option! Try again!." << '\n';
            break;
    }
    return true;
}

void Menu::start()
{
    while(showOptions()){
    }
    return;
}