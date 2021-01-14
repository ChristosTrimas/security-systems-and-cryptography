Assignment No.8

Buffer overflow exploitation.

Christos Trimas
2016030054

Before anything, make sure you have installed the gcc-multilib package. If not run the following command:
	
	$sudo apt-get install gcc-multilib

Helpful for compilation of different architecture program-system.

Then I created a simple script that creates the exploit, using a premade shellcode found online.
After the creation of exploit.txt, I simple run the Greeter(see below how to run) and the exploit does its job and return a terminal within the program. To test that simple run ls command and the files of the folder will be listed.

To run the program:

	$python2 shell.py > exploit.txt
	$(cat exploit.txt ;cat)| ./Greeter
	$ls(new terminal)

Make sure to have python version 2 installed, otherwise it will not compile the shell.py.
