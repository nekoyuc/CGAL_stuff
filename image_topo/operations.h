#pragma once
#include <opencv2/opencv.hpp>

#include "canvas.h"

//typedef std::shared_ptr<Canvas> MapModule;

class MapModule{
    public:
        MapModule();
        ~MapModule();
};

void imageIndexToCanvasIndex(int& image_x, int& image_y, cv::Mat& image, Canvas& canvas, int& canvas_x, int& canvas_y);

void topoMapFromImage(Canvas& canvas, cv::Mat& image, MapModule* mapModule = nullptr);
