I created a class called BigInt for doing basic arithmatic calculations with large integers. The standard type int
only ranges from values about -2.1 billion to +2.1 billion and has a size of 32 bits. I wrote a class that stores 
each digit in a number as a character in a string, allowing the user to perform calculations for numbers
larger than what an int object can store. For simplicity, I wrote it so the digits string in the BigInt object can 
only store numbers, excluding negative values. I may go back and extend the class to include negative 
numbers later.

I am doing this project to improve my algorithm-writing practices-- because large numbers (and very large strings)
take up a lot of space, writing code that is efficient is incredibly important for run-time efficiency.
