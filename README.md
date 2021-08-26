# ProjectN
The Near Neighbor Algorithm (or k-NN for short) is an unparalleled local classification and regression algorithm. In both cases the input depends on the k closest observations in the feature space. k-NN can be used for classification or regression: k-NN for classification: Given the input of a new example, the algorithm belongs to the group. The example is associated with the most common class among k nearest neighbors (where k is defined as an integer, usually a small number). If k = 1 the object is associated with the class of the nearest single neighbor. k-NN for Regression: Given a new example, the algorithm returns a sample property value. This value is the average of the k values of the nearest neighbors.

In the first part of our project we made a basic model, as a beginning to the project, of the classifier.
In this part of the project, we made a server, that runs the KNN algorithm on the input that he gets from the client. 
It can run it using TCP or UDP protocls, as the client chooses.
Before running any of the protocols, we connect the UDP and TCP clients.

In order to run the project, download our implemented classes, run a main class of TCP (the main class of the server with the argument "TCP") 
and UDP (the main class of the server with the argument "UDP") and then run the client main with your input: the protocol (TCP or UDP, other input will get an error message),
the file of the unclassified irises and the file of the output.

For our port we chose 55755 for TCP and 55756 for UDP and for our buffer size we chose 4096.

For our implementaion we made classes for UDP and TCP, clients and servers, and we made 2 mains - one for the server and one for the client. 
The mains controls our project and writes the KNN-input to the file.

We implemented the files classified and unclassified.

Clone the git and download the implemented files and classes to your computer. We already determined in the code the files that it gets (as classified and unclassified) and the k (as 5) but it can be changed easily. Run the main class and get the output.txt file (we already implemented it for classified and unclassified).

Good luck !
