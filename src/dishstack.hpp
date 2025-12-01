#pragma once

#include <string>
#include <iostream>
#include <optional>

#include "dish.hpp"

class DishStack
{
private:
    static const int MAX_SIZE = 10;
    std::optional<Dish> data[MAX_SIZE];
    int top_index;

public:
    DishStack() : top_index(0) {};

    int size()
    {
        return top_index;
    }

    void push(const Dish &dish)
    {
        if (top_index >= MAX_SIZE)
        {
            std::cout << "Stack is full. Cannot push another dish.\n";
            return;
        }
        data[top_index] = dish;
        top_index++;
    }

    Dish peek()
    {
        if (top_index == 0)
        {
            std::cout << "Stack is empty. Cannot peek.\n";
            return Dish("");
        }
        return data[top_index - 1].value();
    }

    Dish pop()
    {
        if (top_index == 0)
        {
            std::cout << "Stack is empty. Cannot pop.\n";
            return Dish("");
        }
        top_index--;
        Dish result = data[top_index].value();
        data[top_index].reset();
        return result;
    }
};