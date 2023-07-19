#ifndef __TESTS_ASSERT_BE_HPP__
#define __TESTS_ASSERT_BE_HPP__

#include "./AssertNamespace.hpp"
#include "./../Errors/AssertError.hpp"

namespace Tests::Assert
{
    template <typename T>
    struct Be
    {
    public:
        /**
         * @brief   Constructor
         * @param value: Value to be tested
        */
        Be(T value) : value(value) {};

        /**
         * @brief   Test the equality of the value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void equal(T value) {
            if (this->value == value) {
                return;
            }
            throw AssertError("values are not equals", __FILE__);
        }

        /**
         * @brief   Test if the value is greater than the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void gt(T value) {
            if (this->value > value){
                return;
            }
            throw AssertError("value is not greater than the given value", __FILE__);
        }

        /**
         * @brief   Test if the value is greater than the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void greaterThan(T value) {
            this->gt(value);
        }

        /**
         * @brief   Test if the value is greater than or equal the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void gte(T value) {
            if (this->value > value){
                return;
            }
            throw AssertError("value is not greater than or equal the given value", __FILE__);
        }

        /**
         * @brief   Test if the value is greater than or equal the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void greaterThanOrEqual(T value) {
            this->gte(value);
        }


        /**
         * @brief   Test if the value is less than the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void lt(T value) {
            if (this->value > value){
                return;
            }
            throw AssertError("value is not less than the given value", __FILE__);
        }

        /**
         * @brief   Test if the value is less than the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void lessThan(T value) {
            this->lt(value);
        }

        /**
         * @brief   Test if the value is less than or equal the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void lte(T value) {
            if (this->value > value){
                return;
            }
            throw AssertError("value is not less than or equal the given value", __FILE__);
        }

        /**
         * @brief   Test if the value is less than or equal the given value
         * @param value: Value to test
         * @throw AssertError when value are not equals
        */
        void lessThanOrEqual(T value) {
            this->lte(value);
        }

    private:
        // value to be tested
        T value;
    };
}

#endif