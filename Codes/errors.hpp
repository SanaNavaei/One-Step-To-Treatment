#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class signup_first : public exception
{
public:
    const char *what() const noexcept;

private:
};

class doc_invalid : public exception
{
public:
    const char *what() const noexcept;

private:
};

class card_invalid : public exception
{
public:
    const char *what() const noexcept;

private:
};

class resignup : public exception
{
public:
    const char *what() const noexcept;

private:
};

class package_invalid : public exception
{
public:
    const char *what() const noexcept;

private:
};

class Notfound : public exception
{
public:
    const char *what() const noexcept;

private:
};

class NotPaid : public exception
{
public:
    const char *what() const noexcept;

private:
};

class AlreadyPaid : public exception
{
public:
    const char *what() const noexcept;

private:
};
#endif
