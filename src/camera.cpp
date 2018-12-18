#include "camera.h"
//
//
//
//NAO DESCOMENTA
// ERRO nA OPENCV
//
//
//
Camera::Camera()
{

}

#include <iostream>
#include <fstream>
#include "C:\opencv\build\include\opencv2\highgui/highgui.hpp"
#include "C:\opencv\build\include\opencv2\imgproc/imgproc.hpp"
//#include "C:\opencv2\highgui\highgui.hpp"
//#include "C:\opencv2\imgproc\imgproc.hpp"

using namespace cv;
using namespace std;
/*
int main(int argc, char** argv)
{

    VideoCapture* cap = new VideoCapture(0); //capture the video from web cam


    if (!cap->isOpened())  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }
    namedWindow("Imagens", CV_WINDOW_NORMAL);
    namedWindow("Control", CV_WINDOW_NORMAL); //create a window called "Control"

    int FHole = 0;
    int FPoint = 0;

    int iLowH = 0;
    int iHighH = 255;

    int iLowS = 0;
    int iHighS = 255;

    int iLowV = 0;
    int iHighV = 255;

    //Create trackbars in "Control" window
    cvCreateTrackbar("FPoint", "Control", &FPoint, 10); //FPoint (0 - 10)
    cvCreateTrackbar("FHole", "Control", &FHole, 10); //FHole (0 - 10)

    cvCreateTrackbar("LowH", "Control", &iLowH, 255); //Hue (0 - 255)
    cvCreateTrackbar("HighH", "Control", &iHighH, 255);

    cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    cvCreateTrackbar("HighS", "Control", &iHighS, 255);

    cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    cvCreateTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap->read(imgOriginal); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
        if (FPoint > 0)
        {
            //morphological opening (remove small objects from the foreground)
            erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(FPoint, FPoint)));
            dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(FPoint, FPoint)));

        }if (FHole > 0)
        {
            //morphological closing (fill small holes in the foreground)
            dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(FHole, FHole)));
            erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(FHole, FHole)));
        }

        imshow("Control", imgThresholded); //show the thresholded image
        imshow("Imagens", imgOriginal); //show the original image

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            cout << "Escrevendo configuracao em Config.txt" << endl;
            cout << "Dados escritos: " << endl;
            fstream file;
            try
            {
                file.open("Configs.txt", fstream::out);
                file << "FHole\n" << FHole << endl
                    << "FPoint\n" << FPoint << endl
                    << "ilowH\n" << iLowH << endl
                    << "iHighH\n" << iHighH << endl
                    << "ilowS\n" << iLowS << endl
                    << "iHighS\n" << iHighS << endl
                    << "ilowV\n" << iLowV << endl
                    << "iHighV\n" << iHighV << endl;
            }
            catch (const std::exception)
            {
                cout << "Falhou ao escrever em Config.txt" << endl;
            }
            break;
        }
    }

    return 0;

}
*/
