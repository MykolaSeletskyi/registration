#include <iostream>
#include "Registration.h"
using namespace std;
int main()
{
	RegistrationAndLogin regAndLog;

	try
	{
		regAndLog.login({ "User","Password" });//пробуєм залогінитись але користувача немає (ошибка wrongUserLoginException)
	}
	catch (const exception& ex)
	{
		cout << ex.what()<<endl;
	}

	try
	{
		regAndLog.registration({ "User","Password" });//все ок
		regAndLog.login({ "User","Password" });//все ок
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	try
	{
		regAndLog.registration({ "User","sda" });//логін аже зареєстрований(ошибка loginAlreadyRegisteredException)
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	try
	{
		regAndLog.registration({ "User2","Passwor" });//короткий пароль (ошибка shortPasswordException)
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}