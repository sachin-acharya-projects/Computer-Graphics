from matplotlib import pyplot as plt

def DDA(x_0, y_0, x_1, y_1):
    # Absolute Difference
    d_x = abs(x_0 - x_1)
    d_y = abs(y_0 - y_1)

    # Maximum difference
    steps = max(d_x, d_y)
    
    increment_x = d_x / steps
    increment_y = d_y / steps
    
    x = float(x_0)
    y = float(y_0)
    
    coord_x = [0] * steps
    coord_y = [0] * steps
        
    for i in range(steps):
        coord_x[i] = x; x += increment_x
        coord_y[i] = y; y += increment_y
    # Mainloop
    plt.plot(coord_x, coord_y, marker='o', markersize=1, markerfacecolor='green')
    plt.show()
    
if __name__ == '__main__':
    x_0, y_0 = input("Enter Coordinates of First Point (X, Y): ").split(", ")
    x_1, y_1 = input("\nEnter Coordinates of First Point (X, Y): ").split(", ")
    DDA(
        int(x_0), 
        int(y_0), 
        int(x_1), 
        int(y_1)
    )
    # DDA(
    #     int(input("Initial X-Coordinate: ")), 
    #     int(input("Initial Y-Coordinate: ")), 
    #     int(input("Final X-Coordinate: ")), 
    #     int(input("Final Y-Coordinate: "))
    # )