# duperphew
1920x1440 to 2560x1440 stretch of a videoclip using OpenCV.
  
The stretch is only in horizontal direction and is based on projecting the image on a cylinder secton of plus minus 73 degrees.  
The calculation is in the XL sheet and was exported to a csv file to get rid of the formulas and only get the values.  
The columns that are not used were deleted and was inserted directly in the cpp file.  
  
Conclusion of the first test is that the stretch is too high in the edges but the result is anyway good for a first try.
 
It is started from the command line and expect a file named c.MP4 (1920x1440 30fps) to exist in the same folder.
I will produce a file called outcpp.mp4.

The stretching is like a projecting the image onto a cylinder.

I think it sucks that some of the GoPro cameras no longer have Superview and you have to buy the most expensive ones to get it.
By using this program and further develop it you can get a similar effect without haveing Superview on you camera.
 
