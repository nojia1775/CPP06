#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <iostream>

class	ScalarConverter
{
	private:
		char			*_nbrc;
		double			*_nbrd;
		float			*_nbrf;
		int			*_nbri;

					ScalarConverter(void);
					~ScalarConverter(void);

					ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);

		bool			isInt(const std::string str) const;
		bool			isChar(const std::string str) const;
		bool			isFloat(const std::string str) const;
		bool			isDouble(const std::string str) const;

	public:
		static void		convert(const std::string str);
};

#endif