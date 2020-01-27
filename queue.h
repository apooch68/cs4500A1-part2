#pragma once

#include "object.h"

/**
 * @brief Class that represents a queue
 * 
 */
class Queue: public Object
{
public:
    //constructs an empty q
    Queue();

    //deconstructs a q
    ~Queue();

    //adds an object to the end of the queue, (malloc call here)
    void add(Object* ptr);

    //gets the head without removing if it exists, else returns nullptr
    Object* peek();

    //gets the head and removes it from the queue if it exists (free here), else return nullptr
    Object* remove();

    //gets the size of the que
    size_t size();
};

