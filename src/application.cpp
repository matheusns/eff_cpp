#include <application.hpp>


Application::Application()
{
    try
    {
        camera_.cameraSetup(460,360, eff_cpp::BowlEncoding::rgb8, Application::imageCallback, (void*) this);
        sleep(10);
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e->what() << std::endl;
    }
}

Application::~Application()
{

}


Application::Application(const Application& obj)
{

}

void Application::imageCallback(cv::Mat& frame)
{
    cv::imshow("Test", frame);
    int key = cv::waitKey(1);
}
