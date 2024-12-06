#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <iostream>

class	ScalarConverter
{
	private:
					ScalarConverter(void);
					~ScalarConverter(void);

					ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);

	public:
		void			convert(const std::string num) const;
};

#endif