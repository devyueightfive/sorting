//
// Created by yuri on 29.04.19.
//

#ifndef UNTITLED_COMPARABLE_H
#define UNTITLED_COMPARABLE_H


/**
* Class consists of main function compare():
*  returns true if first_arg less than second_arg
* @tparam T - type
*/
template<typename T>
class Comparable {
    //true if first<second
public:
    Comparable<T>() = default;

    virtual bool compare(T first, T second) {
        return first < second;
    };

    ~ Comparable() = default;
};

template<typename T>
class Decrease : public Comparable<T> {
public:
//    Decrease();

    bool compare(T first, T second) override {
        return first > second;
    };
};

template<typename T>
class Increase : public Comparable<T> {
public:
//    Increase();

    bool compare(T first, T second) override {
        return first < second;
    };
};


#endif //UNTITLED_COMPARABLE_H
