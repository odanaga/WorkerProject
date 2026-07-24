#pragma once

#include <string>

enum class JobTitle
{
    GeneralDirector = 0,
    President = 1,
    Rector = 2,
    ViceRector = 3,
    HeadOfDepartment = 4,
    Professor = 5,
    Docent = 6,
    SeniorTeacher = 7,
    Teacher = 8,
    Assistant = 9,
    SeniorResearch = 10,
    Research = 11,
}; 

struct JobTitleMatch 
{
    JobTitle job_title_enum;
    std::string job_title;
};

const JobTitleMatch job_title_matches[] = 
{
    {JobTitle::GeneralDirector, "General Director"},
    {JobTitle::President, "President"},
    {JobTitle::Rector, "Rector"},
    {JobTitle::ViceRector, "Vice Rector"},
    {JobTitle::HeadOfDepartment, "Head Of Department"},
    {JobTitle::Professor, "Professor"},
    {JobTitle::Docent, "Docent"},
    {JobTitle::SeniorTeacher, "Senior Teacher"},
    {JobTitle::Teacher, "Teacher"},
    {JobTitle::Assistant, "Assistant"},
    {JobTitle::SeniorResearch, "Senior Research"},
    {JobTitle::Research, "Research"},
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