import matplotlib.pyplot as plt

def linear_regression(x,y):
    
    sum_x = 0
    sum_y = 0
    x_sq  = 0
    xy    = 0
    
    
    n = len(x)
    
    for i in  range(n):
        
        sum_x += x [ i ]
        
        sum_y += y [ i ]
        
        x_sq  += ( x[ i ] * x[ i ] )
        
        xy    += x[ i ] * y[ i ]
        
    
    a1 = ( n * xy ) - ( sum_x * sum_y )
    
    b = ( n * x_sq ) - ( sum_x * sum_x )
    
    a1 /= (1.00 * b)
    
    x_mean = sum_x / ( n * 1.00 )
    
    y_mean = sum_y / ( n * 1.00 )
    
    a0 = y_mean - ( a1 * x_mean )
    
    
    plt.scatter(x,y)
    
    print("Linear Regression Line of the given data is \n")
    
    print('y = (%.3f) + (%.3f)x' % (a0, a1))
    
    plt.xlabel("X")
    
    plt.ylabel("Y")
    
    plt.title("Linear Regression Model")
        
    y_val = []
    
    for i in range(n):
        
        y_val.append(a0 + a1*x[i])
    
    
    
    plt.plot(x,y_val,color="g")

    plt.show()           






number_of_data_points = int(input("Enter the number of data points you are about to give\n"))

print("Enter the data points x f(x) format seperated by space")

x=[]

y=[]


for i in range(0,number_of_data_points):
    
    data = input(" x f(x) {} : ".format(i+1)).split()
    
    x.append(float(data[0]))
    y.append(float(data[1]))
    
linear_regression(x,y)
