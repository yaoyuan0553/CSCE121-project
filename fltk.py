import os

# List of all the files in courses.cse.tamu.edu/daugher/misc/PPP
files = ["Window.h", "Window.cpp", "Simple_window.h", "Simple_window.cpp", "Point.h", "Graph.h", "Graph.cpp", "GUI.h", "GUI.cpp", "sample_main4.cpp", "std_lib_facilities_4.h"]

try:
        for file in files:
                # Full URL of file to grab
                url = "http://courses.cse.tamu.edu/daugher/misc/PPP/" + file
                os.system("wget " + url)

except:
        print "OOPS"
