# Capstone
This is my capstone I was hestitente about putting it here on github because of the nature of what it is 
which is a trojan but decided to put it here for employers to see. It is strictly for that purpose and to show 
that I have interest in computer security. The program is a GUI written with the Qt framework.
It checks to see if ccleaner and defraggler are installed on the system and if not asks to install them.
After Installion it pops up with a GUI window that has two buttons. One says run ccleaner and the other says run defraggler.
If either is clicked it run the disired program but also put a C++ executable in the startup programs folder 
which will crash the computer by constantly allocating memory in an infinite loop and before entering that loop 
it calls iself to prevent the OS from being able to kill it.

# Note to Employers: 
I've with-held the malicious part of this program. If you wish to see it please email me. 
