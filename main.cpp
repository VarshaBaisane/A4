#include <iostream>
#include <vector>
#include <fstream>
#include <limits> // For input validation

// Define Vertex class
class Vertex {
public:
    float x, y, z;
    Vertex(float xCoord, float yCoord, float zCoord = 0.0f)
        : x(xCoord), y(yCoord), z(zCoord) {}

    void print() const {
        std::cout << "Vertex(" << x << ", " << y << ", " << z << ")\n";
    }
};

// Define Shape2D class
class Shape2D {
public:
    std::vector<Vertex> vertices;

    void addVertex(float x, float y) {
        vertices.emplace_back(x, y, 0.0f); // z is zero for 2D objects
    }

    void printVertices() const {
        std::cout << "2D Shape Vertices:\n";
        for (const auto& vertex : vertices) {
            vertex.print();
        }
    }

    const std::vector<Vertex>& getVertices() const {
        return vertices;
    }
};

// Define Shape3D class
class Shape3D {
public:
    std::vector<Vertex> vertices;

    void addVertex(float x, float y, float z) {
        vertices.emplace_back(x, y, z);
    }

    void printVertices() const {
        std::cout << "3D Shape Vertices:\n";
        for (const auto& vertex : vertices) {
            vertex.print();
        }
    }

    const std::vector<Vertex>& getVertices() const {
        return vertices;
    }
};

// Function to export vertices to a file
void exportVerticesToFile(const std::vector<Vertex>& vertices, const std::string& filename, bool is2D) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }
    // Indicate if it's a 2D or 3D object
    file << (is2D ? "2D" : "3D") << std::endl;
    // Write vertices to the file
    for (const auto& vertex : vertices) {
        file << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
    }
    file.close();
    std::cout << "Vertices exported to " << filename << std::endl;
}

// Function to validate float input
bool getFloatInput(float& input) {
    std::cin >> input;
    if (std::cin.fail()) { // If input is not a number
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear remaining input
    return true;
}

void getVertex3D(float& x, float& y, float& z) {
    while (true) {
        std::cout << "Enter coordinates (x y z): ";
        if (getFloatInput(x) && getFloatInput(y) && getFloatInput(z)) {
            break; // Valid input, break the loop
        }
        std::cout << "Invalid input. Please enter numeric values for (x y z).\n";
    }
}

void getVertex2D(float& x, float& y) {
    while (true) {
        std::cout << "Enter coordinates (x y): ";
        if (getFloatInput(x) && getFloatInput(y)) {
            break; // Valid input, break the loop
        }
        std::cout << "Invalid input. Please enter numeric values for (x y).\n";
    }
}

int main() {
    int choice;
    std::cout << "Do you want to create a 2D or 3D object?\n";
    std::cout << "1. 2D\n";
    std::cout << "2. 3D\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        Shape2D shape2D;
        int numVertices;
        std::cout << "Enter the number of vertices for your 2D object: ";
        std::cin >> numVertices;

        for (int i = 0; i < numVertices; ++i) {
            float x, y;
            getVertex2D(x, y);
            shape2D.addVertex(x, y);
        }

        std::cout << "2D object created with the following vertices:\n";
        shape2D.printVertices();
        
        // Export vertices to a file
        exportVerticesToFile(shape2D.getVertices(), "vertices.txt", true); // is2D = true
    } 
    else if (choice == 2) {
        Shape3D shape3D;
        int numVertices;
        std::cout << "Enter the number of vertices for your 3D object: ";
        std::cin >> numVertices;

        for (int i = 0; i < numVertices; ++i) {
            float x, y, z;
            getVertex3D(x, y, z);
            shape3D.addVertex(x, y, z);
        }

        std::cout << "3D object created with the following vertices:\n";
        shape3D.printVertices();
        
        // Export vertices to a file
        exportVerticesToFile(shape3D.getVertices(), "vertices.txt", false); // is2D = false
    } 
    else {
        std::cout << "Invalid choice. Please restart the program.\n";
    }

    return 0;
}


//Example usage:
//Do you want to create a 2D or 3D object?
//1. 2D
//2. 3D
//Enter your choice (1 or 2): 2
//Enter the number of vertices: 4
//Enter coordinates (x y z) for vertex 1: 0 0 0
//Enter coordinates (x y z) for vertex 2: 1 0 0
//Enter coordinates (x y z) for vertex 3: 0 1 0
//Enter coordinates (x y z) for vertex 4: 0 0 1