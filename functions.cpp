//
// Created by myatz on 5/19/2023.
//

#include "functions.h"
void arabic2RomanNumerals()
{
    char answer;
    do
    {
        int arabicNumber;
        std::vector<std::string>romanNumerals;
        std::vector<int>arabicNumeralsVector;
        std::cout << "Enter a number:\n";
        std::cin >> arabicNumber;
        for(int i = 3; i > -1; i--)
        {
            int digit = static_cast<int>((arabicNumber / pow(10, i))) % 10;
            arabicNumeralsVector.push_back(digit);
        }
        romanNumerals.push_back("M");
        romanNumerals.push_back("CDM");
        romanNumerals.push_back("XLC");
        romanNumerals.push_back("IVX");
        for(int i = 0; i < arabicNumeralsVector.size(); i++)
        {
            if(arabicNumeralsVector[i] >= 1 && arabicNumeralsVector[i] <= 3)
            {
                for(int j = 0; j < arabicNumeralsVector[i]; j++)
                    std::cout << romanNumerals.at(i).at(0);
            }
            else if(arabicNumeralsVector[i] == 4)
                std::cout<< romanNumerals.at(i).at(0) << romanNumerals.at(i).at(1);
            else if(arabicNumeralsVector[i] >= 5 && arabicNumeralsVector[i] <= 8)
            {
                std::cout << romanNumerals.at(i).at(1);
                for(int j = 5; j < arabicNumeralsVector[i]; j++)
                    std::cout << romanNumerals.at(i).at(0);
            }
            else if(arabicNumeralsVector[i] == 9)
                std::cout<< romanNumerals.at(i).at(0) << romanNumerals.at(i).at(2);
        }
        std::cout << "\nWould you like to calculate again? y/n\n";
        std::cin >> answer;
    }while(tolower(answer) == 'y');
}