#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

#include "canvas.h"
#include "operations.h"

int main() {
    // Load the image
    cv::Mat image_1a = cv::imread("../../assembly_planner/images/About_WildBird-mobile.jpg", cv::IMREAD_COLOR);
    cv::Mat image_1b = cv::imread("../../assembly_planner/images/About_WildBird-mobile.jpg", cv::IMREAD_GRAYSCALE);

    cv::Mat image_1c = cv::imread("../../assembly_planner/images/About_WildBird-mobile.jpg", cv::IMREAD_UNCHANGED);
    cv::Mat image_2a = cv::imread("../../assembly_planner/images/cat.jpg", cv::IMREAD_COLOR);
    cv::Mat image_2b = cv::imread("../../assembly_planner/images/cat.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat image_2c = cv::imread("../../assembly_planner/images/cat.jpg", cv::IMREAD_UNCHANGED);

    // Check if the image was loaded successfully
    if (image_1a.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return -1;
    } else {
        std::cout << "Image loaded successfully" << std::endl;
    }

    Canvas canvas(10, 10, 3, 5);
    canvas.getSize();
    canvas.getLayerHeight();
    canvas.getCellNum();
    std::cout << "Cell size: " << canvas.getCellWidth() << "x" << canvas.getCellHeight() << std::endl;
    canvas.getTopoGrid();
    std::cout << "\nChange cell numbers" << std::endl;
    canvas.getSize();
    canvas.setCellNum(4, 2);
    canvas.getCellNum();
    std::cout << "Cell size: " << canvas.getCellWidth() << "x" << canvas.getCellHeight() << std::endl;
    canvas.getTopoGrid();

    // Display the image
    cv::imshow("Loaded Image", image_1a);
    // Wait for a keystroke in the window
    cv::waitKey(0);

    cv::imshow("Loaded Image", image_1b);
    cv::waitKey(0);

    cv::imshow("Loaded Image", image_1c);
    cv::waitKey(0);
    
    cv::imshow("Loaded Image", image_2a);
    cv::waitKey(0);
    
    cv::imshow("Loaded Image", image_2b);
    cv::waitKey(0);

    cv::imshow("Loaded Image", image_2c);
    cv::waitKey(0);


    // Get resolution of the image
    int image_width = image_1a.cols;
    int image_height = image_1a.rows;
    std::cout << "\nImage resolution: " << image_width << "x" << image_height << std::endl;

    // Check if the image is a greyscale image
    if (image_1a.channels() == 1) {
        std::cout << "The image is a greyscale image." << std::endl;
    } else {
        std::cout << "The image is not a greyscale image." << std::endl;
    }

    std::cout << "Number of channels: " << image_1a.channels() << std::endl;
    std::cout << "Number of channels: " << image_1b.channels() << std::endl;
    std::cout << "Number of channels: " << image_1c.channels() << std::endl;
    std::cout << "Number of channels: " << image_2a.channels() << std::endl;
    std::cout << "Number of channels: " << image_2b.channels() << std::endl;
    std::cout << "Number of channels: " << image_2c.channels() << std::endl;

    // Print pixel information of image_1b
    /*
    for (int y = 0; y < image_1b.rows; y++) {
        for (int x = 0; x < image_1b.cols; x++) {
            uchar pixel_value = image_1b.at<uchar>(y, x);
            std::cout << "Pixel value at (" << x << ", " << y << "): " << (int)pixel_value << std::endl;
        }
    }
    */

    // Resize the canvas
    std::cout << "\nResize the canvas" << std::endl;
    canvas.setSize(100, 100);
    canvas.getSize();
    canvas.setCellNum(200, 200);
    canvas.getCellNum();
    std::cout << "Cell size: " << canvas.getCellWidth() << "x" << canvas.getCellHeight() << std::endl;

    topoMapFromImage(canvas, image_1b);
    canvas.getTopoGrid();

    std::ofstream file("output.obj", std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << "output.obj" << std::endl;
    } else{
        for (int y_i = 0; y_i < canvas.m_height_cell_num; y_i++) {
            for (int x_i = 0; x_i < canvas.m_width_cell_num; x_i++) {
                float cell_width = canvas.getCellWidth();
                float cell_height = canvas.getCellHeight();
                float x = x_i * cell_width + cell_width / 2;
                float y = y_i * cell_height + cell_height / 2;
                int layers = canvas.getCellValue(x_i, y_i);
                float z = layers * canvas.m_layer_height;
                file << "v " << x << " " << y << " " << z << std::endl;
            }
        }
    }
    file.close();

    return 0;
}