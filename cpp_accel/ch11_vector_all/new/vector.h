#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <memory>

using std::max;
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;

template <typename T>
class Vector {
public:
typedef T value_type;
typedef T& reference;
typedef const T& const_reference;
typedef unsigned int size_type;
typedef T* iterator;
typedef const T* const_iterator;

    Vector();
    explicit Vector(size_type size, const_reference val = T());
    Vector(const_iterator begin, const_iterator end);
    Vector(const Vector<T>& rhs);
    ~Vector();

    Vector<T>& operator=(const Vector<T>& rhs);

    reference operator[](int index);
    const_reference operator[](int index) const;

    void push_back(const T& val);

    size_type size() const;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    void clear();

private:
    iterator data;                // first
    iterator avail;
    iterator limit;               // last next

    allocator<T> alloc;

    void grow();
    void unchecked_append(const T& val);

    void create();
    void create(size_type size, const T& val);
    void create(const_iterator begin, const_iterator end);
    void uncreate();

};

template <typename T>
void Vector<T>::grow()
{
    size_type new_size = max(2 * (this->limit - this->data), long(1));
    iterator new_data = alloc.allocate(new_size);

    iterator new_avail = uninitialized_copy(this->data, this->avail, new_data);

    this->uncreate();

    this->data = new_data;
    this->avail = new_avail;
    this->limit = new_data + new_size;
}

template <typename T>
void Vector<T>::unchecked_append(const T& val)
{
    *this->avail = val;
    ++this->avail;
}

template <typename T>
void Vector<T>::create()
{
    this->data = this->avail = this->limit = 0;
}

template <typename T>
void Vector<T>::create(size_type size, const T& val)
{
    this->data = alloc.allocate(size);
    
    uninitialized_fill(this->data, this->data + size, val);

    this->limit = this->avail = this->data + size;
}

template <typename T>
void Vector<T>::create(const_iterator begin, const_iterator end)
{
    size_type size = end - begin;
    this->data = alloc.allocate(size);
    
    uninitialized_copy(begin, end, this->data);

    this->limit = this->avail = this->data + size;
}

template <typename T>
void Vector<T>::uncreate()
{
    if(this->data){
        iterator iter = this->avail;
        while (iter != this->data)
            alloc.destroy(--iter);
        
        alloc.deallocate(this->data, this->limit - this->data);
    }
    this->data = this->avail = this->limit = 0;
}

template <typename T>
Vector<T>::Vector()
{
    this->create();
}

template <typename T>
Vector<T>::Vector(size_type size, const_reference val)
{
    this->create(size, val);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs)
{
    this->create(rhs.begin(), rhs.end());
}

template <typename T>
Vector<T>::Vector(const_iterator begin, const_iterator end)
{
    this->create(begin, end);
}

template <typename T>
Vector<T>::~Vector()
{
    this->uncreate();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    if (this != &rhs) {
        this->uncreate();

        this->create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](int index)
{
    return this->data[index];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::operator[](int index) const
{
    return this->data[index];
}

template <typename T>
void Vector<T>::push_back(const T& val)
{
    if(this->avail == this->limit){
        this->grow();
    }
    this->unchecked_append(val);
}

template <typename T>
typename Vector<T>::size_type Vector<T>::size() const
{
    return this->avail - this->data;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return this->data;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return this->data;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return this->avail;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
    return this->avail;
}

template <typename T>
void Vector<T>::clear()
{
    this->uncreate();
}

#endif