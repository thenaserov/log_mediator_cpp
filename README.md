# LOG MEDIATOR C++
---------------------------------------------------------------------------------

Simply using this program you will be be able to send your logs to a http server.

This program reads the log from the file and then sends them to your log server
(which in this case we are using an elastic server).


# DEPENDANCIES
---------------------------------------------------------------------------------
(Nothing yet)


# HOW TO RUN
---------------------------------------------------------------------------------
Simply do cmake


# TODO
---------------------------------------------------------------------------------
Implement online/offline switcher
Problems:
1. If the app has locked the file we can not delete it
2. how to handle socket
3. how to handle the size
(the log is written with the day ) -> 2024_12_30.txt

4. handle which logs should be sent


logger should decide to delete the logger

a. size after 100 MB should be gone!
b. date after a month should be gone!

6. format of the file
7. get the fields
8. get the logs from the app using the file or socket




