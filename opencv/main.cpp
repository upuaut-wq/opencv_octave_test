
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gdkmm/pixbuf.h>
#include <glibmm/refptr.h>
#include <gtkmm/application.h>
#include <opencv4/opencv2/opencv.hpp>
#include <octave-5.2.0/octave/oct.h>
#include <octave-5.2.0/octave/octave.h>
#include <octave-5.2.0/octave/parse.h>
#include <octave-5.2.0/octave/interpreter.h>

//Convert cv::Mat para Gdk::Pixbuf
//auto size = outImage.size();
//auto img = Gdk::Pixbuf::create_from_data(outImage.data, Gdk::COLORSPACE_RGB, outImage.channels() == 3,8, size.width, size.height, (int) outImage.step);

int main(int argc, char * argv[]){
    auto app = Gtk::Application::create(argc,argv,"exemplo.gtkmm.octave");
    
    Gtk::Window window;
    Gtk::Image image;
    window.add(image);
    /*

    cv::Mat outImage = cv::imread("rice.jpg",cv::IMREAD_GRAYSCALE);
    cv::imwrite("img2.jpg",outImage);
    Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_file("img2.jpg");
    image.set(pixbuf);

    */

    cv::Mat outImage;
    outImage = cv::imread("rice.jpg");
    //cv::cvtColor(outImage, outImage, cv::COLOR_RGB2BGR);
    cv::threshold(outImage,outImage,255,CV_THRESH_BINARY);
    Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_data(outImage.data, Gdk::COLORSPACE_RGB,false, 8, outImage.cols, outImage.rows, outImage.step)->scale_simple( outImage.cols, outImage.rows, Gdk::INTERP_BILINEAR );
    image.set(pixbuf);


    window.show_all_children();
    app->run(window);


    
}