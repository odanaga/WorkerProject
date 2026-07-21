#pragma once

#include <string>

enum class JobTitle
{
    Dean = 0,
    Teacher = 1,
    TechSupport = 2,
    Curator = 3,
    Rector = 4,
}; 

struct JobTitleMatch 
{
    JobTitle job_title_enum;
    std::string job_title;
};

const JobTitleMatch job_title_matches[] = 
{
    {JobTitle::Dean, "Dean"},
    {JobTitle::Teacher,"Teacher"},
    {JobTitle::TechSupport, "TechSupport"},
    {JobTitle::Curator, "Curator"},
    {JobTitle::Rector, "Rector"},
};

struct FullName
{
    std::string name;
    std::string surname;
    std::string patronymic;
};

class Worker
{
public:
    Worker(const FullName& full_name, const JobTitle& job_title, const double& salary, const double& enlistment_year);
    ~Worker();

public:
    FullName getName();
    JobTitle getJobTitle();
    double getSalary();
    double getEnlistmentYear();
    void changeName(const FullName& full_name);
    void changeJobTitle(const JobTitle& job_title);
    void changeSalary(const double& salary);
    void changeEnlistmentYear(const double& enlistment_year);

private:
    FullName full_name;
    JobTitle job_title;
    double salary;
    double enlistment_year;
};