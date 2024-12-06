#pragma once
#include <iostream>

class Canvas{
    public:
        Canvas(float width = 100.0f, float height = 100.0f, int width_cell_num = 200, int height_cell_num = 200);
        ~Canvas();
        float m_width;
        float m_height;
        int m_width_cell_num;
        int m_height_cell_num;
        float m_layer_height;
        int m_max_layer;

        void setSize(float width, float height);
        void setLayerHeight(float layer_height);
        void setCellNum(int width_cell_num, int height_cell_num);
        void getSize();
        void getLayerHeight();
        void getCellNum();

        float getCellWidth();
        float getCellHeight();
        void setCell(int x, int y, int value);
        int getCellValue(int x, int y);
        void getTopoGrid(); // This function is for testing purposes only
    
    private:
        float m_cell_witdh;
        float m_cell_height;
        std::vector<int> m_topo_grid;

};

 