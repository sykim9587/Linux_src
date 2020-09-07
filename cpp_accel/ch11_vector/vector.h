#ifndef VECTOR_H
#define VECTOR_H

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
    void create();
    void create(size_type size, const T& val);
    void create(const_iterator begin, const_iterator end);
    void uncreate();
};

template <typename T>
void Vector<T>::create()
{
    this->data = this->limit = 0;
}

template <typename T>
void Vector<T>::create(size_type size, const T& val)
{
    this->data = new T[size];
    for (size_type i = 0; i != size; ++i)
        this->data[i] = val;
    this->limit = this->data + size;

}

template <typename T>
void Vector<T>::create(const_iterator begin, const_iterator end)
{
    size_type size = end - begin;
    this->data = new T[size];
    for (size_type i = 0; i != size; ++i)
        this->data[i] = begin[i];
    this->limit = this->data + size;
}


template <typename T>
void Vector<T>::uncreate()
{
    if (this->data )
        delete [] this->data;
}

template <typename T>
Vector<T>::Vector() //: data(0), limit(0) -> original before having create function
{
    this->create();
}

template <typename T>
Vector<T>::Vector(size_type size, const T& val)
{
    
    /*this->data = new T[size]; //overhead, defult constructor for T called 
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



template <typename T> 
typename Vector<T>::size_type Vector<T>::size() const
{
    return this->limit - this->data;
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
    return this->limit;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
    return this->limit;    
}


#endif