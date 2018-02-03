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
    @brief ������������ ���� � ��������� ��� ��������
    @version 1.0
    @date 08.01.2018
*/

#ifndef TRAINING_HPP_INCLUDED
#define TRAINING_HPP_INCLUDED

#include <vector>
#include <string>

namespace TrainingFunctions {

    /** @brief �������� ������� ������
        @param[in] path ������ ����� �� ������ � �������
        @param[in] data ������ ������
        @param[in] start ������� ������ ������ (�� 0 �� 1)
        @param[in] stop ������� ����� ������ (�� 0 �� 1)
    */
    void getData(std::vector<std::string>& path, std::vector<std::vector<double>>& data, double start, double stop);

    void getExtremaDetectorTrainData(std::string name, std::vector<std::vector<double>>& data, int numTrainingSamples, int nWindow);

    /** @brief �������� ������� ��������� � ����������
        @param[in] close ������� ������
        @param[out] dataMin ������ ���������
        @param[out] dataMax ������ ���������
    */
    void getMaxMinData(std::vector<double>& close, std::vector<double>& dataMin, std::vector<double>& dataMax);

    /** @brief �������� ������ ��� �������� � ������ �������
        @param[in] name ��� ����� ��� ����������
        @param[in] numTrainingSamples ���������� ������ ��� ��������
        @param[in] nWindow ������ ����
        @param[in] data ������ ��� ���������
    */
    void getWindowTrainData(std::string name, int numTrainingSamples, int nWindow, std::vector<double>& data);

    /** @brief �������� ������ ������������� ������ ����� �����������
        @param[in] name ��� ����� ��� ����������
        @param[in] numTrainingSamples ���������� ������ ��� ��������
        @param[in] nMa ������ ���������� ������� ��� ���������� ������
        @param[in] nBb ������ �����������
        @param[in] d ��������� ������������ ���������� ����� �����������
        @param[in] nRsi ������ rsi
        @param[in] nWindow ������ ����
        @param[in] data ������ ��� ���������
    */
    void getNormBbRsiTrain(std::string name, int numTrainingSamples, int nMa, int nBb, double d, int nRsi, int nWindow, std::vector<double>& data);


    void getGoodTimeEmaRsiTrainData(std::string name, int numTrainingSamples, std::vector<double>& data);

    void getBbTrainData(std::string name, int numTrainingSamples, int nWindow, double d, std::vector<double>& data);

}

#endif // TRAINING_HPP_INCLUDED
