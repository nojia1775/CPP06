#ifndef DATA_HPP

# define DATA_HPP

# include <iostream>

class	Data
{
	private:
		const std::string	_name;
		const int		_data;
	
	public:
					Data(void);
					~Data(void);
		
					Data(const std::string& name, const int& data);
					Data(const Data& other);
		Data&			operator=(const Data& other);

		const int		getData(void) const;
		const std::string	getName(void) const;
};

#endif