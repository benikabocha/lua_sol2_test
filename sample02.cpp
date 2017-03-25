#include <sol.hpp>

#include <iostream>

int main()
{
	try
	{
		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::package);
		lua.script_file("sample02.lua");

		std::cout << "lua a = " << lua["a"].get<int>() << "\n";
		std::cout << "lua b = " << lua["b"].get<int>() << "\n";
		std::cout << "lua c = " << lua["c"].get<int>() << "\n";
		auto undefineValue = lua["x"];
		if (!undefineValue.valid())
		{
			std::cout << "lua x is undefined.\n";
		}
		std::cout << "\n";

		sol::table table1 = lua["table1"];
		std::cout << "lua table1 size = " << table1.size() << "\n";
		for (auto it = table1.begin(); it != table1.end(); ++it)
		{
			std::cout << (*it).first.as<int>() << " : " << (*it).second.as<int>() << "\n";
		}
		std::cout << "\n";

		sol::table table2 = lua["table2"];
		std::cout << "lua table2 size = " << table2.size() << "\n";
		for (auto it = table2.begin(); it != table2.end(); ++it)
		{
			sol::table elem = (*it).second.as<sol::table>();
			std::cout << "name = " << elem["name"].get<std::string>() << " value = " << elem["value"].get<int>() << "\n";
		}
		std::cout << "\n";
	}
	catch (sol::error e)
	{
		std::cout << "sol error.\n" << e.what() << "\n";
	}
	return 0;
}
