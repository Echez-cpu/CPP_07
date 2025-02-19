
template<typename T>
Array<T>::Array() : input_array(NULL), input_size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) {
	this->input_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->input_array[i] = T();
	this->input_size = n;
}

template<typename T>
Array<T>::Array(Array const &source) : input_array(NULL), input_size(0) {
	*this = source;
}

template<typename T>
Array<T>::~Array() {
	delete [] this->input_array;
}



template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &original_copy) {
    if (this != &original_copy) {  
        delete[] this->input_array;

        this->input_size = orignal_copy.input_size;
        if (this->input_size == 0) {
            this->input_array = NULL;
        } else {
            this->input_array = new T[this->input_size];
            for (int i = 0; i < this->input_size; i++)
                this->input_array[i] = original_copy.input_array[i];
        }
    }
    return *this;
}


template<typename T>
T& 	Array<T>::operator[](int n) const {
    if (n < 0 || n >= this->input_size)
        throw Array::OutOfBoundException();
    return this->input_array[n];
}



template<typename T>
T&	 Array<T>::operator[](int n) {
    if (n < 0 || n >= this->input_size)
        throw Array::OutOfBoundException();
    return this->input_array[n];
}



template <class T>         // both typename T and class T do the same thing
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("The index is out of bound.");
}

template<typename T>
unsigned int		Array<T>::size() const {
	return this->input_size;
}
