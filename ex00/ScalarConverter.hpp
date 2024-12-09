#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>
# include <cctype>
# include <limits>
# include <iomanip>

class	ScalarConverter
{
	private:
					ScalarConverter(void);
					~ScalarConverter(void);

					ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);

		static bool		isInt(const std::string str);
		static bool		isChar(const std::string str);
		static bool		isFloat(const std::string str);
		static bool		isDouble(const std::string str);
		static void		printChar(double &nbr);
		static void		printInt(double &nbr);
		static void		printFloat(double &nbr);
		static void		printDouble(double &nbr);

	public:
		static void		convert(const std::string& str);
};

#endif