/*
* trading_indicators - Indicators for technical analysis.
*
* Copyright (c) 2018 Yaroslav Barabanov. Email: elektroyar@yandex.ru
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

/** @file
    @brief ������������ ���� � �������� ��� ���������� �������� � ����� ���������� ��� ��������
    @version 1.0
    @date 11.01.2018
*/

#ifndef DRAWING_HPP_INCLUDED
#define DRAWING_HPP_INCLUDED

#include <vector>
#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"

namespace Drawing {

    /** @brief ����� ��� �������� ������ �������� ������
        @version 1.0
        @date 11.01.2018
    */
    class CandlesType {
        public:
        CandlesType();
        /** @brief ���������� ������ �������� �����
            @param[in] _open ������ ������� �����
            @param[in] _close ������ �������� �����
            @param[in] _high ������ ��������� �����
            @param[in] _low ������ �������� �����
        */
        CandlesType(double _open, double _close, double _high, double _low);
        /** @brief ���������� ������ ����������
            @warning ������ ���������� ������ ���������� ������ ������� � ��������� �������!
            @param[in] data ������ ����������
        */
        void setIndicator(double data);
        void setArrowUp();
        void setArrowDown();
        void setArrow(char arrow);
        void setCircle(int state);

        // ������� ��� ���������� ������
        void updataIndicator(double data, int pos);
        void updataArrow(char arrow);

        double open;
        double close;
        double high;
        double low;
        char isArrow = 0;
        char isCirc = 0;
        std::vector<double> indicator;
    };

    /** @brief ����� ��� ����� ������ �������� ������
        @version 1.0
        @date 11.01.2018
    */
    class Window {
        private:
        std::vector<CandlesType> data;
        int N = 0;
        public:
        Window();
        Window(int n);
        void updata(double open, double high, double low, double close);
        void updataLast(double open, double high, double low, double close);
        void setArrow(char arrow);
        void setCircle(int state, int pos);
        void setIndicator(double dataInd);
        void updateIndicator(double dataInd, int pos);
        void getCandlesType(std::vector<CandlesType>& out);
        std::vector<CandlesType> getCandlesType();
    };

    /** @brief �������� ������ ������
        @param[in] out �����������
        @param[in] width ������ �����������
        @param[in] height ������ �����������
        @param[in] in ������ � ������� ������
        @param[in] backgroundColor ���� ����
        @param[in] backgroundColor2 ���� ����
        @param[in] lineColor ���� ����� �����������
    */
    void getCandleGraph(cv::Mat& out,
                        int width, int height,
                        std::vector<CandlesType>& in,
                        cv::Scalar backgroundColor, cv::Scalar backgroundColor2, std::vector<cv::Scalar>& lineColor);

    /** @brief �������� ������ ������
        @param[in] name ��� ���� �����������
        @param[in] in ������ � ������� ������
        @param[in] flag ���� ��������� �������� ������ (��� �������� ����� ���� ������ ���������� P)
    */
    void viewCandleGraph(std::string name, std::vector<CandlesType>& in, int flag);

    /** @brief ��������� ������ ������
        @param[in] name ��� ���� �����������
        @param[in] in ������ � ������� ������
    */
    void saveCandleGraph(std::string name, std::vector<CandlesType>& in);

    /** @brief �������� ������
        @param[in] name ��� ���� �����������
        @param[in] text ���� �� �����������
        @param[in] in1 ������ � �������
        @param[in] in2 ������ � �������
        @param[in] in3 ������ � �������
        @param[in] in4 ������ � �������
        @param[in] width ������ �����������
        @param[in] height ������ �����������
        @param[in] mask ����, ������� ���� ����� 0x10 ������� ���������� �������� � ����� img � ������ name.jpg
    */
    char drawOscilloscope4xBeam(
    std::string name, std::string text,
    std::vector<double> in1, std::vector<double> in2, std::vector<double> in3, std::vector<double> in4,
    int width, int height, int mask);


    void drawCandleGraph(cv::Mat& output, int x, int y, int width, int height, std::vector<CandlesType>& in, cv::Scalar backgroundColor, std::vector<cv::Scalar>& lineColor, int isAutoCircl);
    void viewCandleGraph2(std::string name, Window& iWind, int width, int height);
}

#endif // DRAWING_HPP_INCLUDED
