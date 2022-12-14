#ifndef MVRE_VECTOR_BASE_
#define MVRE_VECTOR_BASE_

#include "math_concept.hpp"
#include <string>
#include <cstring>
#include <math.h>

namespace mvre_math {

    template<typename T, size_t Length> requires arithmetic<T> class vector_base {
    protected:
        T m_data[Length] = {0};
    public:

        vector_base() = default;

        vector_base(const vector_base<T, Length>& _val) {
            memcpy(m_data, _val.m_data, sizeof(T) * Length);
        }

        explicit vector_base(T* _val) {
            memcpy(m_data, _val, sizeof(T) * Length);
        }

        inline T get(size_t i) const {
            return m_data[i];
        }

        inline void set(size_t i, T value) {
            m_data[i] = value;
        }

        inline T& operator[](size_t i) {
            return m_data[i];
        }

        vector_base<T, Length> operator+(const vector_base<T, Length>& right) const {
            T new_data[Length];
            for (auto i = 0; i < Length; i++)
                new_data[i] = m_data[i] + right.get(i);

            return vector_base<T, Length>(new_data);
        }

        vector_base<T, Length> operator-(const vector_base<T, Length>& right) const {
            T new_data[Length];
            for (auto i = 0; i < Length; i++)
                new_data[i] = m_data[i] - right.get(i);

            return vector_base<T, Length>(new_data);
        }

        vector_base<T, Length> operator/(const vector_base<T, Length>& right) const {
            T new_data[Length];
            for (auto i = 0; i < Length; i++)
                new_data[i] = m_data[i] / right.get(i);

            return vector_base<T, Length>(new_data);
        }

        vector_base<T, Length> operator*(const vector_base<T, Length>& right) const {
            T new_data[Length];
            for (auto i = 0; i < Length; i++)
                new_data[i] = m_data[i] * right.get(i);

            return vector_base<T, Length>(new_data);
        }

        vector_base<T, Length> operator*(const float& right) const {
            T new_data[Length];
            for (auto i = 0; i < Length; i++)
                new_data[i] = m_data[i] * right;

            return vector_base<T, Length>(new_data);
        }

        vector_base<T, Length> operator/(const float& right) const {
            T new_data[Length];
            for (auto i = 0; i < Length; i++)
                new_data[i] = m_data[i] / right;

            return vector_base<T, Length>(new_data);
        }

        vector_base<T, Length>& operator+=(const vector_base<T, Length>& right) {
            for (auto i = 0; i < Length; i++)
                m_data[i] += right.get(i);
            return *this;
        }

        vector_base<T, Length>& operator-=(const vector_base<T, Length>& right) {
            for (auto i = 0; i < Length; i++)
                m_data[i] -= right.get(i);
            return *this;
        }

        vector_base<T, Length>& operator*=(const vector_base<T, Length>& right) {
            for (auto i = 0; i < Length; i++)
                m_data[i] *= right.get(i);
            return *this;
        }

        vector_base<T, Length>& operator/=(const vector_base<T, Length>& right) {
            for (auto i = 0; i < Length; i++)
                m_data[i] /= right.get(i);
            return *this;
        }

        vector_base<T, Length>& operator*=(const float& right) {
            for (auto i = 0; i < Length; i++)
                m_data[i] *= right;
            return *this;
        }

        bool operator==(const vector_base<T, Length>& _right) const {
            return memcmp(&m_data, &_right.m_data, sizeof(T) * Length) == 0;
        }
    };
}

#endif