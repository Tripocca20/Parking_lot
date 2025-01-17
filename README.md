# Parking lot problem
1) Content:
Assume that the parking lot is a long and narrow passage that can park n cars, and there is only one gate for cars to enter and exit.  
In the parking lot, the cars are arranged from north to south in the order of their arrival time (the gate is at the southernmost end, and the first
arrived is at the northernmost end). If the parking lot is full of n cars, then the later cars can only wait outside the lot.  
Once a car leaves, the car waiting in the first position can enter (this is a queue with a length of m); when a car in the parking lot needs to leave, the car behind it must give way to it. When the car leaves the parking lot,
other cars enter the stack in order. Each car is charged according to the time.  
2) Requirements:  
Use the stack to simulate the parking lot, and the queue to simulate the sidewalk outside the parking lot.  
Management is simulated according to the sequence of data read from the terminal.  
Each set of input data includes three data: the car's "arrival" ('A') or "departure" ('D') information, the car identification (license plate number) and the time of arrival or departure. The output information after the operation of each set of input data is: if the vehicle arrives, the parking position of the car in the parking lot or on the sidewalk is output; if the vehicle leaves, the time the car stays in the parking lot and the fee to be paid (no fee is charged on the sidewalk) are output. The stack is implemented as a sequential structure, and the queue is implemented as a linked list structure.  
3) Test data: Let n = 3, m = 4, and the parking price is p = 2. The input data is:
(‘A’, 101, 5), (‘A’, 102, 10), (‘D’, 101, 15), (‘A’, 103, 20), (‘A’, 104,
25), (‘A’, 105, 30), (‘D’, 102, 35), (‘D’, 104, 40), (‘E’, 0, 0). Among them, ‘A’
means arrival, ‘D’ means departure, and ‘E’ means end. The time is a relative number of minutes.  
4) Input and output:  
Input data: The program accepts 5 commands, namely: arrival (‘A’, license plate number, time); departure (‘D’, license plate number, time); parking lot (P, 0, 0) displays the cars in the parking lot; waiting lot (W, 0, 0) displays the cars in the waiting lot; exit (E, 0, 0) exits the program.  
Output data: For vehicle arrival, the parking position of the car in the parking lot or on the sidewalk should be output; for vehicle departure, the time the car stays in the parking lot and the fee to be paid (no fee is charged on the sidewalk) should be output.
