#include "BitcoinExchange.hpp"

std::map<std::string, float> read_csv()
{
    std::map<std::string, float> value;
    std::ifstream fn("data.csv");
    if (!fn)
    {
        return value;
    }
    std::string line;
    std::string date;
    float count;

    std::getline(fn, line);
    while (std::getline(fn, line))
    {
        int i = 0;
        i = line.find(',');
        date = line.substr(0, i);
        line.erase(0, i + 1);
        count = std::stod(line);
        value[date] = count;
    }
    return value;
}

std::map<std::string, std::string> read_input(std::string data){
    std::map<std::string, std::string> value;
    std::ifstream fn(data);
    if (!fn)
    {
        return value;
    }
    
    std::string line;
    std::string date;
    std::string count;

    std::getline(fn, line);
    const char* line_cmp = static_cast<const char*>(line.c_str());
    if (strcmp(line_cmp, "date | value") != 0 && strcmp(line_cmp, "date | value") != 13)
    {
        std::cout << "wrong first row: '" << line << "'\n";
        exit(1);
    }
    int i = 0;
    int linec = 100000;
    while (std::getline(fn, line))
    {
        if (line.empty() || isPrint(line))
        {
            std::cout << "Error: null line or space is not allowed\n";
            exit(-1);
        }
        i = line.find(' ');
        date = line.substr(0, i);
        if (line.size() <= 10)
            line = " ";
        else if (line.find('|') == std::string::npos)
            line = " ";
        line.erase(0, i + 1);
        if (line.size() < 3 || line[0] == '\0')
            count = "|";
        else if (line[0] != '|' || line[1] != ' ')
        {
            count = " ";
        }
        else
        {
            line = line.substr(2);
            count = line;
        }
        if (count.empty())
            count = " ";
        date = std::to_string(linec) + date;
        value[date] = count;
        linec++;
    }
    if (line.empty() || isPrint(line))
    {
        std::cout << "Error: null line or space is not allowed\n";
        exit(-1);
    }
    return value;
}

int isNumber(std::string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 48 || str[i] > 57)
            return 1;
        i++;
    }
    return 0;
}

int isPrint(std::string str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 33 && str[i] <= 126)
            count++;
        i++;
    }
    if (count == 0)
        return 1;
    return 0;
}

int maxControl(std::string number)
{
    float value = std::stod(number);
    if (value < 0 || value > 1000)
        return 1;
    return 0;
}

void printList(std::map<std::string, float> data, std::map<std::string, std::string> input){
    std::map<std::string, std::string>::iterator input_first = input.begin();
    std::map<std::string, std::string>::iterator input_end = input.end();

    for (; input_first != input_end; *input_first++)
    {
        try
        {
            std::string date = input_first->first;
            
            int control = dateControl(date);
            if (control)
            {
                if (control == 1)
                    throw BitcoinExchange::NoBitcoin();
                else if (control == 2)
                    throw BitcoinExchange::WrongDate();
                else if (control == 3)
                    throw BitcoinExchange::FutureDate();
            }
            std::string count_s = input_first->second;
            if (count_s[0] == '-')
                throw BitcoinExchange::NegativeNumber();
            else if (count_s == "|" || numberControl(count_s) == 2)
                throw BitcoinExchange::NoNumber();
            else if (maxControl(count_s))
                throw BitcoinExchange::MaxNumber();
            float count = std::stof(input_first->second);
            std::map<std::string, float>::iterator data_first = data.begin();
            std::map<std::string, float>::iterator data_end = data.end();

            std::string year = date.substr(6, 4);
            std::string month = date.substr(11, 2);
            std::string day = date.substr(14, 2);
            std::string previous;
            std::map<std::string, float>::iterator previous_first = data.begin();
            std::string current_date;
            for (; data_first != data_end; *data_first++)
            {
                previous_first = data_first;
                previous = previous_first->first;
                *previous_first++;
                current_date = previous_first->first;
                int current_year = std::stoi(current_date.substr(0, 4));
                int current_month = std::stoi(current_date.substr(5, 2));
                int current_day = std::stoi(current_date.substr(8, 2));

                if (current_year == std::stoi(year) && current_month == std::stoi(month) && current_day == std::stoi(day)){
                    break;
                }
                if (current_year > std::stoi(year) || (current_year == std::stoi(year) && current_month > std::stoi(month)) || (current_year == std::stoi(year) && current_month == std::stoi(month) && current_day > std::stoi(day))){
                    current_date = previous;
                    break;
                }
            }
            std::cout << date.substr(6) << " => " << count << " = " << count * data[current_date] << "\n";
        }
        catch (const BitcoinExchange::FutureDate& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const BitcoinExchange::NegativeNumber& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const BitcoinExchange::MaxNumber& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const BitcoinExchange::WrongDate& e)
        {
            std::cerr << e.what() <<  input_first->first.substr(6) <<'\n';
        }
        catch(const BitcoinExchange::NoBitcoin& e)
        {
            std::cerr << e.what() << " => " << input_first->first.substr(6) <<  '\n';
        }
        catch(const BitcoinExchange::NoNumber& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const BitcoinExchange::AFewSpace& e)
        {
            std::cerr << e.what() << "\n";
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: no number.\n";
        }
    }
}

int dateControl(std::string date){
    std::string n_date = date.substr(6);

    if (n_date.length() != 10)
        return 2;
    if (n_date[4] != '-' || n_date[7] != '-')
        return 2;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (n_date[i] < 48 || n_date[i] > 57)
            return 2;
    }
    int year = std::stoi(date.substr(6, 4));
    int month = std::stoi(date.substr(11, 2));
    int day = std::stoi(date.substr(14, 2));

    if ((year < 1900) || (month < 1 || month > 12) || (day < 1 || day > 31))
        return 2;
    if (year > 2022)
        return 3;
    if ( month == 2 && ((day > 28 && year % 4 != 0) || (day > 29 && year % 4 == 0)))
        return 2;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
        return 2;
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31))
        return 2;
    if (year < 2009 || (year == 2009 && month == 1 && day < 3))
        return 1;
    return 0;
}

int numberControl(std::string value)
{
    int len = value.length();
    int i = 0;
    int dot = 0;

    int dot_i = 0;
    if (len == 1)
    {
        if (value[0] >= '0' && value[0] <= '9')
            return (INT);
        else
            return (IMPOSSIBLE);
    }
    while (value[i])
    {
        if (!(value[i] >= '0' && value[i] <= '9') && value[i] != '.')
            return (IMPOSSIBLE);
        if (value[i] == '.')
        {
            dot++;
            dot_i = i;
        }
        i++;
    }
    if ((dot > 1) || (dot == 1 && (dot_i == 0 || dot_i == (len - 1))))
        return (IMPOSSIBLE);
    if (dot == 0)
        return (INT);
    if (dot == 1)
        return (DOUBLE);
    return (IMPOSSIBLE);
}

const char *BitcoinExchange::WrongDate::what() const throw(){
    return "Error: bad input => ";
}

const char *BitcoinExchange::FutureDate::what() const throw(){
    return "Error: Since the closest date for which data is available is 2022, accurate results cannot be shown.";
}

const char *BitcoinExchange::NoNumber::what() const throw(){
    return "Error: no number.";
}

const char *BitcoinExchange::NegativeNumber::what() const throw(){
    return "Error: not a positive number.";
}

const char *BitcoinExchange::MaxNumber::what() const throw(){
    return "Error: too large a number.";
}

const char *BitcoinExchange::NoBitcoin::what() const throw(){
    return "Error: WTF bro! There is no such thing as bitcoin yet.";
}

const char *BitcoinExchange::AFewSpace::what() const throw(){
    return "Error: a few space.";
}