#pragma once

#include "object.h"
#include <string.h>
#include <assert.h>

/**
 * @brief Class for representing a String.
 * 
 */
class String: public Object {
    public:
    
        String(const char* s);

        virtual ~String();

        /**
         * @brief Returns the length of the string.
         * 
         * @return int The length of hte string.
         */
        uint getLength();

        /**
         * @brief Returns whether or not the given object is equal to this string.
         * Equality between strings means that all characters within both
         * strings are the exact same.
         * 
         * @param o The given object ot check equaliity.
         * @return true If both this and the given object are the same.
         * @return false otherwise.
         */
        virtual bool equals(Object* o);

        /**
         * @brief Compares this String with the given string with respect
         * to the strings contents (i.e in alphabetical order). If the given
         * string is larger than this one, a negative int is returned. If the 
         * given string is smaller (alphabetically), a positive int is returned. 
         * If the two strings are equal, 0 is returned.
         * 
         * 
         * @param s The string to compare to.
         * @return int Positive if this string is larger, negative if this string
         * is smaller, 0 otherwise.
         */
        virtual int compareTo(String* s);

        /**
         * @brief Returns the character at the specified index. Index
         * must be within the length of the string and 0.
         * 
         * @param i The index to be queried.
         * @return char The char at the given index.
         */
        char charAt(uint i);

        /**
         * @brief Concacts the given string object with this string object.
         * 
         * @param e The given String.
         */
        String* concat(String* e);

        /**
         * @brief Get the string.
         * 
         * @return const char* The string.
         */
        const char* getString();

        /**
         * @brief Returns the hash of the given string
         * 
         * @return size_t The hash
         */
        size_t hash_me();
};
