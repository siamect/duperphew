#include "opencv2/opencv.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;

static float new_pos[2560];
int x=0;
int main(int argc, char** argv){
int minutes = atoi(argv[1]); 
int seconds = atoi(argv[2]);
int file_number = atoi(argv[3]);

 /// create table
 for (x=0;x<2560;x++) {
	new_pos[x]= (18821485518263.0*x*x*x*x*x)/401598620231335912189339500.0 - (132758679464694919.0*x*x*x*x)/401598620231335912189339500.0 + (3402878089027632059.0*x*x*x)/4897544149162633075479750.0 - (171993524775281717309.0*x*x)/489754414916263307547975.0 + (2524031576682848584635617.0*x)/4015986202313359121893395.0;
	 	 
	 //cout << x << " " << new_pos[x] << endl;
 }

  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  char infile[255];
  char outfile[255];
  sprintf(infile,"/home/martin/Videos/GOPR%i.MP4",file_number);
  sprintf(outfile,"/home/martin/Videos/%i.mp4",file_number);
  VideoCapture cap(infile); 
    
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
     
  // Default resolution of the frame is obtained.The default resolution is system dependent. 
   
  // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file. 
  VideoWriter video(outfile,CV_FOURCC('D', 'I', 'V', 'X'),30, Size(2560,1440)); 
  //namedWindow("Frame",CV_WINDOW_NORMAL);
  //namedWindow("Frame out",CV_WINDOW_NORMAL);
  Mat frame(Size(1920,1440),CV_8UC3);; 
  int frame_counter=0;

  while(frame_counter++<minutes*60*30+seconds*30)
  { 
     
    // Capture frame-by-frame 
    cap >> frame;
	}
  while(1)
  { 
    cap >> frame;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
     
    /// mess with the frame

	Mat frame_out = Mat::zeros (frame.rows, 2560, frame.type() );

	
	// Parallel execution using C++11 lambda.
	typedef cv::Point3_<uint8_t> Pixel;
	frame_out.forEach<Pixel>([frame](Pixel &p, const int * position) -> void {
		p.x = frame.at<Vec3b>(position[0],new_pos[position[1]])[0];
		p.y = frame.at<Vec3b>(position[0],new_pos[position[1]])[1];
		p.z = frame.at<Vec3b>(position[0],new_pos[position[1]])[2];
	});
	
   ///end of mess 
    // Write the frame into the file 'outcpp.avi'
    video.write(frame_out);
    
    // Display the resulting frame    
    //imshow( "Frame out", frame_out );
    //imshow( "Frame", frame);
  
    // Press  ESC on keyboard to  exit
    //char c = (char)waitKey(1);
    //if( c == 27 ) 
    // break;
  }
 
  // When everything done, release the video capture and write object
  cap.release();
  video.release();
 
  // Closes all the windows
  destroyAllWindows();
  return 0;
}
