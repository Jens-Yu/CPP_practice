
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <chrono>
#include <string>
#include <limits>



bool getValidInput()
{
    std::string str;
    while (true) {

        if (std::cin >> str && str[0] == 'y'  && str.length() == 1) 
        {
            break;
            return true;
        }
        else if (std::cin >> str && str[0] == 'n' && str.length() == 1)
        {
            break;
            return false;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
}

double getValidAnswer() {
    std::string str;
    double num;
    bool invalidInput = true;

    while (invalidInput) {
        std::cin >> str;

        invalidInput = false;  

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9'||str[i]=='.') {
                continue;
            }

            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again." << std::endl;
                invalidInput = true; 
                break;
            }
        }
    }
    num = std::stod(str);
    return num;
}


struct Mystruct
{
    int a;
    int b;
    std::vector<int> arr;
    std::vector<double> time;
    std::vector<double> right;
};

int* g_random(int size, int number)
{
    int* arr = new int[size];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < size; i++)
    {
        arr[i]=std::rand() % number;
    }
    return arr;
}
int getsymbol()
{
    int symbol;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    symbol = std::rand() % 4;
    return symbol;

}

Mystruct easy(int x, int* n)
{
    Mystruct fin_res;
    fin_res.a = 0;
    fin_res.b = 0;
    std::vector<double> times;
    std::vector<int> Myarr;
    std::vector<double> rightanswer;
    double result;
    for (int i = 0; i < x; i++)
    {
        if (0 == (i % 2))
        {
            std::cout << "(" << i + 1 << ") " << n[2 * i] << " + " << n[2 * i + 1] << " = ";
            auto start = std::chrono::high_resolution_clock::now();
            result = getValidAnswer();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            times.push_back(duration.count());
            std::cout << std::endl;
            if (result == (n[2 * i] + n[2 * i + 1]))
            {
                fin_res.a += 1;
            }
            else
            {
                fin_res.b += 1;
                Myarr.push_back(i+1);
                rightanswer.push_back(n[2 * i] + n[2 * i + 1]);
            }
        }
        else
        {
            std::cout << "(" << i + 1 << ") " << n[2 * i] << " - " << n[2 * i + 1] << " = ";
            auto start = std::chrono::high_resolution_clock::now();
            result = getValidAnswer();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            times.push_back(duration.count());
            std::cout << std::endl;
            if (result == (n[2 * i] - n[2 * i + 1]))
            {
                fin_res.a += 1;
            }
            else
            {
                fin_res.b += 1;
                Myarr.push_back(i + 1);
                rightanswer.push_back(n[2 * i] - n[2 * i + 1]);
            }
        }
    }
    fin_res.arr = Myarr;
    fin_res.time = times;
    fin_res.right = rightanswer;
    return fin_res;
}
Mystruct com(int x, int* n)
{
    Mystruct fin_res;
    fin_res.a = 0;
    fin_res.b = 0;
    std::vector<double> times;
    std::vector<int> Myarr;
    std::vector<double> rightanswer;
    double result;
    for (int i = 0; i < x; i++)
    {
        int symbol = getsymbol();
        if (0 == symbol)
        {
            std::cout << "(" << i + 1 << ") " << n[2 * i] << " + " << n[2 * i + 1] << " = ";
            auto start = std::chrono::high_resolution_clock::now();
            result = getValidAnswer();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            times.push_back(duration.count());
            std::cout << std::endl;
            if (result == (n[2 * i] + n[2 * i + 1]))
            {
                fin_res.a += 1;
            }
            else
            {
                fin_res.b += 1;
                rightanswer.push_back(n[2 * i] + n[2 * i + 1]);
                Myarr.push_back(i + 1);
            }
        }
        else if(1==symbol)
        {
            std::cout << "(" << i + 1 << ") " << n[2 * i] << " - " << n[2 * i + 1] << " = ";
            auto start = std::chrono::high_resolution_clock::now();
            result = getValidAnswer();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            times.push_back(duration.count());
            std::cout << std::endl;
            if (result == (n[2 * i] - n[2 * i + 1]))
            {
                fin_res.a += 1;
            }
            else
            {
                fin_res.b += 1;
                rightanswer.push_back(n[2 * i] - n[2 * i + 1]);
                Myarr.push_back(i + 1);
            }
        }
        else if (2 == symbol)
        {
            std::cout << "(" << i + 1 << ") " << n[2 * i] << " * " << n[2 * i + 1] << " = ";
            auto start = std::chrono::high_resolution_clock::now();
            result = getValidAnswer();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            times.push_back(duration.count());
            std::cout << std::endl;
            if (result == (n[2 * i] * n[2 * i + 1]))
            {
                fin_res.a += 1;
            }
            else
            {
                fin_res.b += 1;
                rightanswer.push_back(n[2 * i] * n[2 * i + 1]);
                Myarr.push_back(i + 1);
            }
        }
        else
        {
            std::cout << "(" << i + 1 << ") " << n[2 * i] << " / " << n[2 * i + 1] << " = ";
            if (n[2 * i + 1 != 0])
            {
                auto start = std::chrono::high_resolution_clock::now();
                result = getValidAnswer();
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                times.push_back(duration.count());
                std::cout << std::endl;
                double realresult = static_cast<double>(n[2 * i]) / n[2 * i + 1];
                std::cout << std::fixed << std::setprecision(1);
                const double e = 0.05;
                double tolerance = std::abs(result - realresult);
                if (tolerance < e)
                {
                    fin_res.a += 1;
                }
                else
                {
                    fin_res.b += 1;
                    rightanswer.push_back(realresult);
                    Myarr.push_back(i + 1);
                }
            }
            else {
                std::cout << "Division by zero is not allowed." << std::endl;
                continue;
            }
        }
    }
    fin_res.arr = Myarr;
    fin_res.time = times;
    fin_res.right = rightanswer;
    return fin_res;
}

int getValidInteger() {
    std::string str;
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        std::cin >> str;

        invalidInput = false; 

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                continue;
            }

            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again." << std::endl;
                invalidInput = true;  
                break;
            }
        }
    }
    num = std::stoi(str);
    return num;
}

int main() 
{
    Mystruct res;
    std::cout << "Enter the number of questions :";
    int x = getValidInteger();
    std::cout << "\n";
    std::cout << "Enter the maximum value for random numbers : ";
    int num = getValidInteger();
    std::cout << "\n";
    std::cout << " Add '*'  und  '/'? (y/n): ";
    bool y = getValidInput();
    std::cout << "Total scores:" << x << ",one correct answer get 1 score" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int* n = g_random(2 * x, num);
    if (y)
    {
        res = com(x, n);
    }
    else
    {
        res = easy(x,n);
    }
    std::cout << "Number of correct answers;" << res.a << "\n";
    std::cout << "Number of incorrect answers:" << res.b << "\n";
    std::cout << "Scores you got:" << res.a << std::endl;
    std::cout << "Incorrect questions:" << std::endl;
    for (int i = 0; i < res.b; i++) 
    {
        std::cout << res.arr[i] << " ";
        std::cout << "    The right answer is:"<<res.right[i] << "\n";
    }
    std::cout << std::endl;
    double totaltime = 0;
    double aver_time = 0;
    double min_time = 100000;
    for (int i = 0; i < x; i++)
    {
        totaltime = totaltime + res.time[i];
        if (min_time >= res.time[i])
        {
            min_time = res.time[i];
        }
    }
    aver_time = totaltime / x;
    std::cout << "Average time that you answer a question:" << aver_time <<"ms"<< std::endl;
    std::cout << "Shortest time that you answerr a question:" << min_time << "ms"<<std::endl;
    return 0;
}
