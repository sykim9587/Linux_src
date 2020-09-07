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
    typedef unsigned int size_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef const T& const_reference;
    typedef T& reference;
    //in order to do deep copy, create all.
    Vector();
    explicit Vector(size_type size, const T& val = T()); //so that other type can come in. 
    // vector<int> v2 = 10; won't work because of 'explicit'
    Vector(const_iterator begin, const_iterator end);
    Vector(const Vector<T>& rhs);
    ~Vector();

    Vector<T>& operator=(const Vector<T>& rhs);

    T& operator[](int index);
    const T& operator[](int index) const;

    void push_back(const T& val);

    size_type size() const;

    //when reading the const object
    const_iterator begin() const;
    const_iterator end() const;

    //when changing
    iterator begin();
    iterator end();

private:
    iterator data;
    iterator limit;
    iterator avail;

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
    size_type new_size = max(2* (this->limit - this->data),long(1)); //when it's not created yet. make it to 1
    //this->limit is long-int (type casted), so 1 should also be long  int
    
    //iterator new_data = new T[new_size];
    iterator new_data = alloc.allocate(new_size);

    //copy
    /*
    for (size_type i = 0; i < this->avail - this->data; ++i)
    {
        new_data[i] = this->data[i];

    }
    */
    iterator new_avail = uninitialized_copy(this->data, this->avail, new_data);

    
    this->uncreate();
    this->avail = new_avail;
    this->data = new_data;
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
    //this->data = new T[size];
    this->data = alloc.allocate(size);

    /*
    for (size_type i = 0; i != size; ++i){
        //this->data[i] = val;
        alloc.construct(this->data + i,val);
    }
    */

    uninitialized_fill(this->data, this->data + size, val);
    this->limit = this->avail = this->data + size;

}

template <typename T>
void Vector<T>::create(const_iterator begin, const_iterator end)
{
    size_type size = end - begin;
    //this->data = new T[size];
    this->data = alloc.allocate(size);
    //for (size_type i = 0; i != size; ++i)
    //    this->data[i] = begin[i];
    uninitialized_copy(begin,end,this->data);
    this->limit = this->avail = this->data + size;
}


template <typename T>
void Vector<T>::uncreate()
{
    if (this->data )
    {
        //delete [] this->data;
        iterator iter = this->avail;
        while(iter!= this->data) //coming back
            alloc.destroy(--iter);

        alloc.deallocate(this->data, this->limit-this->data);
    }
    this->data = this->avail = this->limit = 0;
        
}

template <typename T>
Vector<T>::Vector() //: data(0), limit(0) -> original before having create function
{
    this->create();
}

template <typename T>
Vector<T>::Vector(size_type size, const T& val)
{
    
    /*
    this->data = new T[size]; //overhead, defult constructor for T called 
    for (int i = 0; i < size; ++i)
        this->data[i] = val;
    this->limit = this->data + size;
    */

    this->create(size,val);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs)
{
    /*
    int size = rhs.limit - rhs.data; // pointer - pointer (type casting done)
    this->data = new T[size];
    for (int i = 0; i < size; ++i)
        this->data[i] = rhs.data[i];
    
    this->limit = this->data + size;
    */
   this->create(rhs.begin(), rhs.end());
}

template <typename T>
Vector<T>::Vector(typename Vector<T>::const_iterator begin, typename Vector<T>::const_iterator end)
{
    /*
    int size = end - begin;
    this->data = new T[size];
    for (int i = 0; i<size; ++i)
        this -> data[i] = begin[i];
    this->limit = this->data + size;
    */
   this->create(begin, end);
}

template <typename T>
Vector<T>::~Vector()
{
    /*
    if (this->data)
        delete [] this->data;
    */
   this->uncreate();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    if (this != &rhs)
    {
        
        /*
        if (this->data)
            delete [] this->data;

        int size = rhs.limit - rhs.data; // pointer - pointer (type casting done)
        this->data = new T[size];
        for (int i = 0; i < size; ++i)
            this->data[i] = rhs.data[i];
    
        this->limit = this->data + size;
        */
       this->uncreate();
       this->create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int index)
{
    return this->data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const
{
    return this->data[index];
}

//different push_back function
template <typename T>
void Vector<T>::push_back(const T& val)
{
    if(this->avail == this->limit)  //times 2
    {
        this->grow();
    }
    this->unchecked_append(val);
}


/* original push_back function
template <typename T>
void Vector<T>::push_back(const T& val)
{
    if(this->avail == this->limit)  //times 2
    {
        size_type new_size = max(2* (this->limit - this->data),long(1)); //when it's not created yet. make it to 1
        //this->limit is long-int (type casted), so 1 should also be long  int
        iterator new_data = new T[new_size];

        //copy
        for (size_type i = 0; i < this->avail - this->data; ++i)
        {
            new_data[i] = this->data[i];

        }
        this->uncreate();
        this->avail = new_data + (this->limit - this->data);
        this->data = new_data;
        this->limit = new_data + new_size;
    }
    *this->avail = val;
    ++this->avail;
}
*/


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
    return this->limit;    
}


#endif