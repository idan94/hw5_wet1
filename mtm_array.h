#ifndef EX5_MTM_ARRAY_H
#define EX5_MTM_ARRAY_H

#include <utility>
#include <stdexcept>

template<class T, int SIZE>
class Array {
    T data[SIZE];

public:
    // TODO: Need to complete interface of iterator classes (x++,++x, ->, operator==, operator!=), as well
    // as that of array itself (operator [], operator [] const, ctor, copy ctor, dtor, operator=),
    // and implement everything.
    //Constructor:
    Array() = default;

    //Destructor:
    ~Array() = default;

    //Copy Constructor:
    Array(const Array &a) = default;

    //Assignment Operator:
    Array &operator=(const Array &a)= default;

    //Operators:
    T &operator[](int index) {
        if (index < 0 || index >= SIZE) {
            throw std::out_of_range(
                    "mtm_array::operator []: index out of range!");
        }
        return data[index];
    }

    const T &operator[](int index) const {
        if (index < 0 || index >= SIZE) {
            throw std::out_of_range(
                    "mtm_array::operator []: index out of range!");
        }
        return data[index];
    }

    class iterator {
        int index;
        Array *array;
    public:
        //Constructor:
        explicit iterator(Array *array) {
            this->array = array;
        }

        iterator operator++() {    //++i
            index++;
            return *this;
        };

        iterator operator++(int) {    //i++
            iterator *temp = this;
            index++;
            return *temp;
        }

        bool operator==(const iterator &i) {
            return bool(index == i.index);
        }

        bool operator!=(const iterator &i) {
            return bool(index != i.index);
        }

        virtual T &operator*() {
            return *array[index];
        }

        virtual T *operator->() {
            return &array[index];
        }
    };

    class const_iterator {
    public:
        T const &operator*() const;
    };


    iterator begin() {
        iterator a(data[0]);
    }

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;
};


#endif //EX5_MTM_ARRAY_H
