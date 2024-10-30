import sys
import matplotlib.pyplot as plt

def main():
    filename = sys.argv[1]
    vertices = []

    with open(filename, 'r') as file:
        file.readline()  # Skip the first line (2D)
        for line in file:
            x, y = map(float, line.split())
            vertices.append((x, y))

    x, y = zip(*vertices)

    plt.figure()
    plt.plot(x, y, 'o-')
    plt.title('2D Shape Visualization')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.axis('equal')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
s