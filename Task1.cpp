#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayList
{
private:
    int *data;
    int capacity, size;

    void resize(int new_capacity)
    {
        int *new_data = new int[new_capacity]; // created new array
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i]; // Stroing the values of hte previous array in the new array
        }

        delete[] data;   // deleting the previous array to prevent data leak
        data = new_data; // Assigning the new Array to the previous array
        capacity = new_capacity;
    }

public:
    // constructor
    ArrayList(int inistial_capacity = 10) : capacity(inistial_capacity <= 0 ? 10 : inistial_capacity), size(0)
    {
        data = new int[capacity];
    }

    // destructor
    ~ArrayList()
    {
        delete[] data;
    }

    // Add at the index by shifting all others right
    void add(int element, int index)
    {
        if (index < 0 || index > size)
        {
            std::string msg = "Index out of bounds";
            throw std::out_of_range(msg); // std string
        };

        if (size == capacity)
        {
            resize(capacity * 2);
        }

        for (int i = size; i > index; --i)
        {
            data[i] = data[i - 1];
        }

        data[index] = element;
        size++;
    }

    // adding element to the end
    void add(int element)
    {
        add(element, size);
    }

    // Get the element at the specific index
    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            std::string msg = "Index out of bounds";
            throw std::out_of_range(msg); // std string
        }

        return data[index];
    }

    void set(int index, int element)
    {
        if (index < 0 || index >= size)
        {
            std::string msg = "Index out of bounds";
            throw std::out_of_range(msg); // std string
        }
        data[index] = element;
    }

    // removing the element at a specifc index
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            std::string msg = "Index out of bounds";
            throw std::out_of_range(msg); // std string
        }

        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1]; // it takes the element od the next index
        }
        size--;
    }

    // reutrns size
    int getSize() const
    {
        return size;
    }
    // reutrns if the arrray is empty
    bool isEmpty() const
    {
        return size == 0;
    }
    // clears the array
    void clear()
    {
        size = 0;
    }
    // reutrns capacity
    int getCapacity() const
    {
        return capacity;
    }

    // Test function
    void Display() const
    {
        if (isEmpty())
        {

            std::cout << "Array is Empty" << std::endl;
            return;
        }

        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i];
            if (i < size - 1)
                std::cout << " , ";
        }
        std::cout << "]";
    }
};

int main()
{
    ArrayList list(4);
    std::cout << "\nAppending the Elements in the Array" << std::endl;
    list.add(10); // Adding the elements to the ArrayList
    list.add(120);
    list.add(104);
    list.add(104);
    list.add(105);
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();                                               // Displaying the data;

    std::cout << "\nRemoving the element at the index 2" << std::endl;
    list.remove(2);                                               // Removing at the index
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();
    std::cout << std::endl;

    std::cout << "\nRemoving the element at the index 3" << std::endl;
    list.remove(3);                                               // Removing at the index
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();                                               // Displaying the data;
    std::cout << std::endl;

    std::cout << "\nAdding the element at the index 1" << std::endl;
    list.add(15, 1);                                              // Adding the element to the ArrayList at the index
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();                                               // Displaying the data;
    std::cout << std::endl;

    std::cout << "\nAdding the element at the index 2" << std::endl;
    list.add(305, 2);                                             // Adding the element to the ArrayList at the index
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();                                               // Displaying the data;
    std::cout << std::endl;

    std::cout << "\nRemoving the element at the index 0" << std::endl;
    list.remove(0);                                               // Removing at the index
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();
    std::cout << std::endl;

    std::cout << "\nUpdating the element at the index 2" << std::endl;
    list.set(2, 25);                                              // Updating the element in the ArrayList at the index
    std::cout << "Capacity: " << list.getCapacity() << std::endl; // Displaying the capacity
    std::cout << "Size: " << list.getSize() << std::endl;     // Displaying the size
    list.Display();                                               // Displaying the data;
    std::cout << std::endl;

    std::cout << "\n---Info Printing---" << std::endl;
    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "Capacity: " << list.getCapacity() << std::endl;
      std::cout<<std::endl;

    std::cout << "\n--- Clearing List ---\n";
    list.clear();

    list.Display(); // Output: Array is Empty ,  Displaying the List

    return 0;
}
