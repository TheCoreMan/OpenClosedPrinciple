# OpenClosedPrinciple
An example to the open closed principle.

At this point in time, this code violates the Open\Closed principle.
The FileStorage class is closed, since it available for use in other modules, like the project's "main".
However, it is not open: it is not available to extension. 

If it was, we could switch the storage type from FileStorage to another type without changing the code too much.

We can't because the interface to "storeData" is dependent on FileStorage. 
