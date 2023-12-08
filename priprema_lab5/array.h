#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <type_traits>

template <typename T> class Array {
public:
  Array() : capacity_{100}, data_{new T[100]}, size_{0} {}

  Array(const std::size_t capacity)
    : capacity_{capacity}, data_{new T[capacity]}, size_{0} {}

  Array(const Array &other)
    : capacity_{other.capacity_}, data_{new T[capacity_]}, size_{other.size_} {
    
      for(int i = 0; i < size_; i++)
        data_[i] = other.data_[i];
  }
    // Drugi nacin
    // for i = 0 do size_
    //   push_back(other[i])

    // Treci nacin
    // for (auto i = 0u; i < size_; i++) {
    //   data_[i] = other.data_[i];
    // }

    // Cetvrti nacin
    // auto dest = data_;
    // for (auto source = other.data_; source < other.data_ + other.size_;
    //      source++)
    //   *dest++ = *source;

  Array(Array &&other)
    : capacity_{other.capacity_}, data_{other.data_}, size_{other.size_} {
      
      other.data_ = nullptr;
      other.capacity_ = other.size_ = 0;
    }

  // Standardna implementacija
  Array &operator=(const Array &other) {
    if(this != &other) {
      delete[] data_;
      capacity_ = other.capacity_;
      size_ = other.size_;
      data_ = new T[capacity_];

      for(auto i = 0u; i < size_; i++)
        data_[i] = other.data_[i];
    }

    return *this;

    // return *this = Array(other);
  }

  // Standardna implementacija
  Array &operator=(Array &&other) {
    if(this != &other) {
      delete[] data_;
      capacity_ = other.capacity_;
      data_ = other.data_;
      size_ = other.size_;
      other.data_ = nullptr;
      other.capacity_ = other.size_ = 0;
    }

    return *this;
  }

  // Hack implementacija
  // Array &operator=(const Array &other) {
  //   return *this = Array(other);
  // }

  // Hack implementacija
  // Array &operator=(Array &&other) {
  //   std::swap(data_, other.data_);
  //   std::swap(capacity_, other.capacity_);
  //   std::swap(size_, other.size_);
  //   return *this;
  // }
  
  ~Array() { delete[] data_; }

  void push_back(const T &element);
  void push_back(T&& element);

  void pop_back();
  void clear();

  T& front();
  const T& front() const;
  T & back();
  const T& back() const;

  T &operator[](size_t index) { return data_[index]; }

  const T &operator[](size_t index) const { return data_[index]; }

  T &at(size_t index);
  const T &at(size_t index) const;

  bool empty() const { return size_ == 0; }
  size_t size() const { return size_; }

  class Iterator;

private:
  std::size_t capacity_;
  T *data_;
  std::size_t size_;
};

template<typename T>
void Array<T>::push_back(const T& element) {
  if(size_ == capacity_) capacity_ += 2;

  data_[size_++] = element;
}

template<typename T>
void Array<T>::push_back(T&& element) {
  if(size_ == capacity_) capacity_ *= 2;

  data_[size_++] = std::move(element);
}

template<typename T>
T& Array<T>::at(size_t index) {
  if(index < 0 || index >= size_)
    throw std::out_of_range{"Invalid index."};

  return data_[index];
}

template<typename T>
const T& Array<T>::at(size_t index) const {
  if(index < 0 || index >= size_)
    throw std::out_of_range{"Invalid index."};

  return data_[index];
}

template<typename T>
T& Array<T>::front() {
  if(!size_) throw std::out_of_range{"Element not existent."};

  return data_[0];
}

template<typename T>
const T& Array<T>::front() const {
  if(!size_) throw std::out_of_range{"Element not existent."};

  return data_[0];
}

template<typename T>
T& Array<T>::back() {
  if(!size_) throw std::out_of_range{"Element not existent."};

  return data_[size_ - 1];
}

template<typename T>
const T& Array<T>::back() const {
  if(!size_) throw std::out_of_range{"Element not existent."};

  return data_[size_ - 1];
}

template<typename T>
void Array<T>::pop_back() {
  if(empty()) throw std::out_of_range{"Empty list."};

  data_[--size_] = T{};
}

template<typename T>
void Array<T>::clear() {
  for(int i = 0; i < size_; i++)
    data_[i] = T{};

  size_ = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
  for(int i = 0; i < arr.size(); i++)
    out << arr[i] << ' ';

  return out;
}

template<typename T>
class Array<T>::Iterator {

  public:
    // + - += -= ++ -- < > == !=
    
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = T;
    using reference = T&;
    using pointer = T*;

    Iterator() : ptr_{nullptr} {}
    Iterator(T* pt) : ptr_{pt} {}

    Iterator& operator++() {
      ++ptr_;
      return *this;
    }
    Iterator operator++(int) { return Iterator{ptr_++}; }

    Iterator* operator--() {
      --ptr_;
      return *this;
    }
   // Iterator operat

  private:
    T* ptr_{nullptr};
};
