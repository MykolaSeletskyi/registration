#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <string>
using std::exception;
using std::string;
using std::vector;
using std::find;
using std::endl;
using std::cout;
class loginAlreadyRegisteredException :public exception
{
	string Message;
public:
	loginAlreadyRegisteredException(const string& Message):Message(Message)
	{};
	char const* what() const override
	{
		const_cast<string&>(Message).insert(0, "this login is registered by : ");
		return Message.c_str();
	}
};
class shortPasswordException :public exception
{
	string Message;
public:
	shortPasswordException(const string& Message) :Message(Message)
	{};
	char const* what() const override
	{
		const_cast<string&>(Message).insert(0, "this password is short : ");
		return Message.c_str();
	}
};
class wrongUserLoginException :public exception
{
	string Message;
public:
	wrongUserLoginException(const string& Message) :Message(Message)
	{};
	char const* what() const override
	{
		const_cast<string&>(Message).insert(0, "wrong login or password : ");
		return Message.c_str();
	}
};
struct loginPasssword
{
	string login;
	string password;
	bool operator==(const loginPasssword& obj)
	{
		if (login==obj.login)
		{
			if (password== obj.password)
			{
				return true;
			}
		}
		return false;
	}
};
class RegistrationAndLogin
{
	vector<loginPasssword> users;
	static const size_t minSizePass = 8;
public:
	RegistrationAndLogin() = default;
	void registration(const loginPasssword& user)
	{
		for (loginPasssword i: users)
		{
			if (user.login==i.login)
			{
				throw loginAlreadyRegisteredException(user.login.c_str());//цей логін вже є
			}
		}
		if (user.password.size() < minSizePass)
		{
			string temp;
			temp.resize(user.password.size(), '*');
			throw shortPasswordException(temp);//короткий пароль
		}
		users.push_back(user);
		cout << "you are registered" << endl;
	}
	void login(const loginPasssword& user)
	{
		if (find(users.begin(), users.end(),user) != users.end())
		{
			std::cout << "Hello " << user.login<< std::endl;
		}
		else
		{
			string temp;
			temp.resize(user.password.size(), '*');
			throw wrongUserLoginException((user.login + '(' + temp + ')'));// неправильний логін або пароль
		}
		
	}
};

