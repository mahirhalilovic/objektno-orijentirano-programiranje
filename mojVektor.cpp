#include <iostream>

class MojVektor {

    public:
        MojVektor() : capacity{10}, size{0}, arr{new int[capacity]} {}

        MojVektor(const MojVektor& vec) : capacity{vec.capacity}, size{vec.size}, arr{new int[capacity]} {

            for(int i = 0; i < size; i++)
                arr[i] = vec.arr[i];
        }

        MojVektor(unsigned int cap) : capacity{cap}, size{0}, arr{new int[cap]} {}

        int& at(unsigned int index) {
            if(index >= size)
                throw std::string{"Out of range."};

            return arr[index];
        }

        MojVektor& operator = (const MojVektor& vec) {

            delete[] arr;
            arr = new int[vec.capacity];
            size = vec.size;

            for(int i = 0; i < size; i++)
                arr[i] = vec.arr[i];

            return *this;
        }

        MojVektor& push_back(int element) {

            if(size == capacity) {

                int* temp = new int[capacity];

                for(int i = 0; i < size; i++)
                    temp[i] = arr[i];

                delete[] arr;
                capacity += 2;
                for(int i = 0; i < size; i++)
                    arr[i] = temp[i];

                delete[] temp;
            }

            arr[size] = element;
            size++;

            return *this;
        }

        friend std::ostream& operator << (std::ostream& os, const MojVektor& vec) {

            os << "[ ";

            for(int i = 0; i < vec.size; i++)
                os << vec.arr[i] << " ";

            os << "]" << std::endl;

            return os;
        }

        int& operator [] (unsigned int index) {

            if(index >= size)
                throw std::string{"Out of range."};

            return arr[index];
        }

        unsigned int size_() const{

            return size;
        }

        bool empty() {

            return size == 0;
        }

    private:
        unsigned int capacity;
        unsigned int size;
        int* arr;
};

int main() {

    MojVektor vec(10);

    for(int i = 1; i < 11; i++)
        vec.push_back(i);

    std::cout << vec.size_() << std::endl;

    vec.push_back(11);

    std::cout << vec.size_() << std::endl;

    try{

        std::cout << vec.at(12);
    } catch(std::string s) {

        std::cout << s << std::endl;
    }

    MojVektor vec2 = vec;

    std::cout << vec2;

    return 0;
}