#include <iostream>
#include <vector>
#include <sstream>
#include <tuple>
#include <random>



class Dice
{
private:
    int m_nMax;
    int m_nNumberOfDice;
public:
    int getMax()
    {
        return this->m_nMax;
    }

    int getNumberOfDice()
    {
        return this->m_nNumberOfDice;
    }

    Dice(int max, int number)
    {
        this->m_nMax = max;
        this->m_nNumberOfDice = number;
    }

    int rollDice()
    {
        int total = 0;
        for(int index = 0; index < this->getNumberOfDice(); index++)
        {
            std::random_device rd;

            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(1, this->m_nMax);
            int randomNumber = dist(mt);
            std::cout<<"Index:  "<< index << "\tDice Roll:  " << randomNumber<<std::endl;
            total += randomNumber;
        }
        return total;
    }
};

std::vector<std::string> split(std::string& splitme, char delimiter)
{
    std::vector<std::string> results;
    std::stringstream ss(splitme);
    std::string token;
    while(getline(ss, token, delimiter))
    {
        results.push_back(token);
    }
    return results;
}

std::tuple<int, int> parseContent(std::string Input) // returns first and last number
{
    std::vector<std::string> numbers = split(Input, 'd');
    int first, last;
    first = std::stoi(numbers.at(0));
    last = std::stoi(numbers.at(1));

    std::tuple<int, int> ret = std::make_tuple(first, last);
    return ret;
}
int main() {
    std::cout<<"Please input your dice roll:  ";
    std::string diceRoll;
    std::cin>>diceRoll;
    std::tuple<int, int> ret = parseContent(diceRoll);
    Dice rolling = Dice(std::get<1>(ret), std::get<0>(ret));
    rolling.rollDice();
    return 0;
}
