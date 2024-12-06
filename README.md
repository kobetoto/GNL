This project is about programming a function that returns a line read from a file descriptor.

For this project, "get_next_line," I have opted for a strategy utilizing a linked list to manage the data read by the read() function during each call to read() and get_next_line(). 
The use of a linked list offers an efficient means of storing the incoming data chunks sequentially, thereby facilitating the incremental construction of the complete line. 
Upon completion, the full line is returned in a variable, ensuring that each line is retrieved in a seamless manner, fully adhering to the requirements of the project.

This approach ensures resilience in handling potentially large and irregular inputs, allowing for optimized memory usage while maintaining an orderly mechanism for line extraction. 
Much like the design principles of a decentralized ledger, this solution promotes reliability through distributed memory management, where each node in the linked list acts as a holder of distinct data segments, collectively contributing to the integrity of the final output.

KT.
