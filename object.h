#pragma once

#include <stdio.h>

class Object
{
  public:
    size_t hash();

    virtual ~Object();

    virtual size_t hashme();

    virtual bool equals(Object o);
};
