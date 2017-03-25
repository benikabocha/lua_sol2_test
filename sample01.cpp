#include <sol.hpp>

#include <iostream>

int main()
{
	try
	{
		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::package);
		lua.script("print('Hello World')");
	}
	catch (sol::error e)
	{
		std::cout << "sol error.\n" << e.what() << "\n";
	}

	return 0;
}
