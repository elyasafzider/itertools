#pragma once

#include <iostream>
#include <string>
// #include <vector>


namespace itertools
{

    class range
    {
    
    /* range members */
    private:
        int m_start, m_end;
    public:
        typedef int value_type;
        /* rane methods - decleration */
        range(int from, int to);
        iterator begin()  ;
        iterator end() ;
        /* the iterator */

        class iterator
        {
        public:
            iterator(int val);
            int operator*() const;
            iterator &operator++();
            bool operator!=(const iterator &other) const;

        private:
            int m_current_number = -1;
        };

    
    };

    
    /* range methods - implementation */
    range::range(int from, int to):
        m_start(from),//5
        m_end(to){}//9

    range::iterator::iterator(int val){ //constructor of iterator
        m_current_number = val; //at start is equal 5
    }  

    range::iterator& range::iterator::operator++(){
        m_current_number++;
        return *this;
    } 

    int range::iterator::operator*() const{ // *it
        return m_current_number;
    }

    bool range::iterator::operator!=(const range::iterator& other) const {
        return m_current_number!=other.m_current_number;
    }

    range::iterator range::begin() {
        return range::iterator{m_start};//dynamic
    } 

    range::iterator range::end() {
        return range::iterator{m_end};//static
    } 
 

} // namespace itertools
