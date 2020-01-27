## OVERVIEW


Provided in Queue.h is a queue interfece designed with a shell class (used as the api interface) called Queue. 

This is a queue for any object that is an or extends the Object class, stored as an object class wich works due to polymorphism.
 
This queue class points to the start and end of a singly linked list (as well as remembering the length of the que). The functions this interface supports are 
add(Object o), which adds an element to the end of the queue
peek(), which returns the next object in the queue without removing it
remove(),  which returns the next object in the queue with removing it
size(), which returns the current length of the queue

The linked list is implemented using a Class QueueBody, which is a class that contains a pointer to the next member of the queue or a nullptr if none exists, and the object passed in through the queue interface. This class must be constructed with the object pointer to be stored, and it supports the function
AddNextMember() which sets the next pointer of the Queue body

