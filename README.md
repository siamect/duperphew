# duperphew  
1920x1440 to 2560x1440 stretch of a videoclip using OpenCV.  
  
The stretch is only in horizontal direction and is based on projecting the image on a  
  
The pixel from the 1920 wide original comes by making this calculation where x is the column in the new 2560 wide image:  
  
<p>(18821485518263.0*x^5)/401598620231335912189339500.0</p>   
<p>- (132758679464694919.0*x^4)/401598620231335912189339500.0</p>   
<p>+ (3402878089027632059.0*x^3)/4897544149162633075479750.0</p>   
<p>- (171993524775281717309.0*x^2)/489754414916263307547975.0</p>   
<p>+ (2524031576682848584635617.0*x)/4015986202313359121893395.0;</p>   
  
  

The program is started from the command line and expect a file named c.MP4 (1920x1440 30fps) to exist in the same folder.
It will produce a file called outcpp.mp4.  

