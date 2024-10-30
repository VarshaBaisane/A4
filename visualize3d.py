import sys
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def main():
    filename = sys.argv[1]
    vertices = []

    with open(filename, 'r') as file:
        file.readline()  # Skip the first line (3D)
        for line in file:
            x, y, z = map(float, line.split())
            vertices.append((x, y, z))

    x, y, z = zip(*vertices)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(x, y, z)
    ax.plot(x, y, z, label='3D Shape')
    ax.set_title('3D Shape Visualization')
    ax.set_xlabel('X-axis')
    ax.set_ylabel('Y-axis')
    ax.set_zlabel('Z-axis')
    ax.legend()
    plt.show()

if __name__ == "__main__":
    main()
