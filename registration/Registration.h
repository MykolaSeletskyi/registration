#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::string;
using std::vector;
using std::search;
struct loginPasssword
{
	string login;
	string password;
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
			//	throw такий користувач вже є
			}
		}
		if (user.password.size() <= minSizePass)
		{
			//	throw короткий пароль
		}
		users.push_back(user);
	}
	void login(const loginPasssword& user)
	{
		if (search(users.begin(), users.end(),user)!=users.end())
		{
			std::cout << "Hello" << std::endl;
		}
		else
		{
			//	throw неправильний логін або пароль
		}
		
	}
};

