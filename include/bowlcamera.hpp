/**
 * @file bowlcamera.cpp
 * @brief Mockup for cpp features testing.
 *
 * Mockup for cpp features testing. This project intend to improve some project skills.
 *
 * @author Matheus Nascimento.
 * @date August 2018.
 */

#ifndef EFF_CPP_INCLUDE_TEST_H
#define EFF_CPP_INCLUDE_TEST_H

#include <iostream>
#include <opencv2/highgui.hpp>
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include <thread>
#include <exception>


namespace eff_cpp
{

enum BowlEncoding
{
    mono8,
    rgb8,
    bgr8,
    bayer_rg8,
    bayer_gr8,
    bayer_bg8,
    yuv_422
};

class Exception : public std::exception
{
  public:
    Exception(std::string msg) :msg_(msg){
      std::cout << "Here ..." <<std::endl;
    }
    virtual ~Exception(){}
    const char* what() const throw()
    {
        std::cout << "Here2 ..." <<std::endl;
        return msg_.c_str();
    }
  protected:
    std::string msg_;
};

class BowlCamera
{
  public:
    /**
     * @brief Default Constructor.
     *
     * BowlCamera default constructor.
     *
     * @return nothing.
     */
    explicit BowlCamera();
    /**
     * @brief BowlCamera destructor.
     *
     * BowlCamera destructor.
     *
     * @return nothing.
     */
    virtual ~BowlCamera();
    /**
     * @brief BowlCamera copy constructor.
     * @return nothing.
     */
    BowlCamera(const BowlCamera& obj);

    /**
     * \typedef Typedef to a callback function pointer.
     */
    typedef void (*CallBackPtr)(cv::Mat&);

    /**
     * @brief Setups the camera regular parameters.
     * @param width Image width.
     * @param height Image height.
     * @param encoding Image encoding.
     * @param fcnt_ptr Pointer to a function to receive the acquired images.
     * @return bool.0
     */
    bool cameraSetup(int width, int height, BowlEncoding encoding,
                     CallBackPtr fcnt_ptr, void *obj_ptr);
    static void frameThread(void* params) throw();
    void waitingStopStreaming();

  private:

     int *buffer_ptr_;
     std::thread *callback_thread_;
     CallBackPtr grab_param_;


};

} //eff_cpp

#endif //EFF_CPP_INCLUDE_TEST_H
