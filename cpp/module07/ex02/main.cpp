/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:35:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:35:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <Array.hpp>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//




    Array<float> numbers2(MAX_VAL);
    float* mirror2 = new float[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers2[i] = 1.f + i;
        mirror2[i] = 1.f + i;
    }
    //SCOPE
    {
        Array<float> tmp = numbers2;
        Array<float> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror2[i] != numbers2[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers2[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers2[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers2[i] = -1000.f + i;
    }
    delete [] mirror2;//





	Array<std::string> strs(3);
    std::string* mirror3 = new std::string[3];
	strs[0] = "cpp";
	strs[1] = "module";
	strs[2] = "07";
    mirror3[0] = "cpp";
	mirror3[1] = "module";
	mirror3[2] = "07";
    //SCOPE
    {
        Array<std::string> tmp = strs;
        Array<std::string> test(tmp);
    }

    for (int i = 0; i < 3; i++)
    {
        if (mirror3[i] != strs[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        strs[-2] = "0";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        strs[3] = "0";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	strs[0] = "1";
	strs[1] = "2";
	strs[2] = "3";
    delete [] mirror3;//
    return 0;
}