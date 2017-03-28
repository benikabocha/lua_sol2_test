#include <sol.hpp>

#include <iostream>
#include <vector>

/*
Callback Test.
*/

int main()
{
	try
	{
		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::package);

		struct Callback
		{
			std::string	m_name;
			sol::object	m_cb;
		};

		std::vector<Callback> callbacks;
		lua["RegisterCallback"] = [&callbacks](const std::string& name, sol::object callback)
		{
			Callback cb;
			if (callback.is<sol::function>())
			{
				cb.m_name = name;
				cb.m_cb = std::move(callback);
				callbacks.emplace_back(std::move(cb));
			}
			else
			{
				std::cout << "RegisterCallback Fail: " << name << "\n";
			}
		};

		lua.script_file("sample03.lua");
		lua.collect_garbage();

		std::cout << "\n======================\n";
		for (auto& cb : callbacks)
		{
			std::cout << "Callback Name : " << cb.m_name << "\n";
			sol::function f = cb.m_cb;
			f();
		}

		std::cout << "\n======================\n";
		for (auto& cb : callbacks)
		{
			std::cout << "Callback Name : " << cb.m_name << "\n";
			sol::function f = cb.m_cb;
			f();
		}
	}
	catch (sol::error e)
	{
		std::cout << "sol error.\n" << e.what() << "\n";
	}
	return 0;
}
