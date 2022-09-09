#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(void);
	Weapon(std::string);

	const std::string	&getType(void);
	void				setType(std::string);
};
#endif