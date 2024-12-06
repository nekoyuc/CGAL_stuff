#include "operations.h"

MapModule::MapModule() {}
MapModule::~MapModule() {}

void imageIndexToCanvasIndex(int& image_x, int& image_y, cv::Mat& image, Canvas& canvas, int& canvas_x, int& canvas_y) {
    canvas_x = static_cast<int>(std::floor(static_cast<float>(image_x) / static_cast<float>(image.cols) * static_cast<float>(canvas.m_width_cell_num)));
    canvas_y = static_cast<int>(std::floor(static_cast<float>(image_y) / static_cast<float>(image.rows) * static_cast<float>(canvas.m_height_cell_num)));
}

void topoMapFromImage(Canvas& canvas, cv::Mat& image, MapModule* mapModule) {
    std::cout << "Function topoMapFromImage called." << std::endl;
    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return;
    } else if (image.channels() == 3) {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    } else if (image.channels() == 4) {
        cv::cvtColor(image, image, cv::COLOR_BGRA2GRAY);
    } else {
        std::cout << "Image loaded successfully" << std::endl;
    }
    for (int image_y = 0; image_y < image.rows; image_y++) {
        for (int image_x = 0; image_x < image.cols; image_x++) {
            uchar pixel_value = image.at<uchar>(image_y, image_x);
            std::cout << "Pixel value at (" << image_x << ", " << image_y << "): " << (int)pixel_value << std::endl;
            int canvas_x = 0;
            int canvas_y = 0;
            imageIndexToCanvasIndex(image_x, image_y, image, canvas, canvas_x, canvas_y);
            int layers = std::ceil(static_cast<float>(pixel_value) / 255.0f * static_cast<float>(canvas.m_max_layer));
            std::cout << "Layers: " << layers << std::endl;
            //std::cout << "Layers: " << layers << std::endl;
            canvas.setCell(canvas_x, canvas_y, layers);
        }
    }
}
