#include "opencv2/opencv.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main(){
 
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  VideoCapture cap("c.MP4"); 
    
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
     
  // Default resolution of the frame is obtained.The default resolution is system dependent. 
   
  // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file. 
  VideoWriter video("outcpp.mp4",CV_FOURCC('D', 'I', 'V', 'X'),30, Size(2560,1440)); 
  while(1)
  { 
    Mat frame; 
     
    // Capture frame-by-frame 
    cap >> frame;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
     
    /// mess with the frame
    
	Mat frame_out = Mat::zeros (frame.rows, 2560, frame.type() );
	float start = 0.15;
	//cout << "rows: " << frame.rows << " cols: " << frame.cols << endl;
	Mat roi = frame( Rect(int(frame.cols*start),0,int(frame.cols - frame.cols*start*2),frame.rows) );
	roi.copyTo ( Mat ( frame_out, Rect ( 320 + frame.cols*start, 0, frame.cols - frame.cols*start*2, frame.rows ) ) );

 	Mat roi_left = frame( Rect(0,0,int(frame.cols*start),frame.rows) );
 	Mat frame_out_l = frame_out(Rect(0,0,320 + frame.cols*start,frame.rows) );
 	resize(roi_left,frame_out_l,Size(frame_out_l.cols, frame_out_l.rows), 0, 0, CV_INTER_LINEAR);

 	Mat roi_right = frame( Rect(frame.cols-(int(frame.cols*start)),0,int(frame.cols*start),frame.rows) );
 	Mat frame_out_r = frame_out(Rect(frame_out.cols - (320 + frame.cols*start),0,320 + frame.cols*start,frame.rows) );
 	resize(roi_right,frame_out_r,Size(frame_out_r.cols, frame_out_r.rows), 0, 0, CV_INTER_LINEAR);

   ///end of mess 
    // Write the frame into the file 'outcpp.avi'
    video.write(frame_out);
    
    // Display the resulting frame    
    imshow( "Frame", frame_out );
  
    // Press  ESC on keyboard to  exit
    char c = (char)waitKey(1);
    if( c == 27 ) 
      break;
  }
 
  // When everything done, release the video capture and write object
  cap.release();
  video.release();
 
  // Closes all the windows
  destroyAllWindows();
  return 0;
}
