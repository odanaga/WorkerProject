#include "worker.h"

Worker::Worker(const FullName& full_name, const JobTitle& job_title, const double& salary, const double& enlistment_year)
    : full_name(full_name), job_title(job_title), salary(salary), enlistment_year(enlistment_year)
{
}

Worker::~Worker()
{
}

FullName Worker::getName()
{
    return full_name;
}
JobTitle Worker::getJobTitle()
{
    return job_title;
}
double Worker::getSalary()
{
    return salary;
}
double Worker::getEnlistmentYear()
{
    return enlistment_year;
}

void Worker::changeName(const FullName& full_name)
{
    this->full_name = full_name;
}

void Worker::changeJobTitle(const JobTitle& job_title)
{
    this->job_title = job_title;
}

void Worker::changeSalary(const double& salary)
{
    this->salary = salary;
}

void Worker::changeEnlistmentYear(const double& enlistment_year)
{
    this->enlistment_year = enlistment_year;
}