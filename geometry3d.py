# visualize_3d.py

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def read_vertices_from_file(filename):
    vertices = []
    with open(filename, 'r') as file:
        for line in file:
            if line.startswith("Vertex"):
                parts = line.split("(")[1].split(")")[0].split(",")
                x, y, z = float(parts[0]), float(parts[1]), float(parts[2])
                vertices.append((x, y, z))
    return vertices

def plot_3d_shape(vertices):
    # Unzip the vertices into X, Y, and Z coordinates
    x_coords, y_coords, z_coords = zip(*vertices)

    # Plotting the shape
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    # Plotting vertices
    ax.scatter(x_coords, y_coords, z_coords, color='red', s=50)  # Plotting the vertices in red

    # Plotting edges
    for i in range(len(vertices)):
        for j in range(i + 1, len(vertices)):
            # Plot lines between all pairs of points (can be customized based on the shape)
            x_line = [vertices[i][0], vertices[j][0]]
            y_line = [vertices[i][1], vertices[j][1]]
            z_line = [vertices[i][2], vertices[j][2]]
            ax.plot(x_line, y_line, z_line, color='blue', alpha=0.3)

    # Setting plot properties
    ax.set_title('3D Shape Visualization')
    ax.set_xlabel('X Coordinate')
    ax.set_ylabel('Y Coordinate')
    ax.set_zlabel('Z Coordinate')
    plt.show()

def main():
    filename = "shape3D_properties.txt"  # The file exported from C++ code
    vertices = read_vertices_from_file(filename)
    
    if not vertices:
        print("No vertices found in the file.")
        return

    plot_3d_shape(vertices)

if __name__ == "__main__":
    main()
