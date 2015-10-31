# Carving
This is my first repository

For Using this codre you should follow these steps :-

Before making the disk image file of the device you should check the device name by typing "mount" command in the terminal let it is /dev/sdb1 then

1. First of all make a disk image file of the hard disk or the pendrive by typing " dd if=/dev/sdb1 of=raw" in the command line 
2. After that you sholud make three directories maned jpeg(for storing the carved jpeg files),gif(for storing the carved gif files and pdf(for storing the carved pdf files).
3. All these files and directories should be in the same directory wher the all remaing source code is present.
4. After that type gcc project.c then an a.out file is created in the current directory.
5. After that type ./a.out and run the code 

the software is now working follow the code and run the program.
