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

#ifndef FANNFUNCTIONS_HPP_INCLUDED
#define FANNFUNCTIONS_HPP_INCLUDED

#include <vector>
#include <string>
#include "fann.h"
#include "floatfann.h"

namespace FannFunctions {

    /** @brief ��������������� ������ ��� ���������� �������
        @param[in] x ���������� �����
        @param[��] y ����� ������
        @return ��������� �� ��������� ������
    */
    fann_type** reserveData(int x, int y);

    /** @brief �������� ������ ���������� �������
        @param[in] x ���������� �����
        @param[in] data ��������� �� ��������� ������
    */
    void deleteData(int x, fann_type** data);

    /** @brief ���������� ������ ���������� �������
        @param[in] in ������ ������ (���������� ������)
        @param[in] data ��������� �� ��������� ������
        @param[in] x ������ ���������� �������
    */
    template<class dataType>
    void setData(std::vector<dataType>& in, fann_type** data, int x) {
        for(int i = 0; i < (int)in.size(); i++) {
            data[x][i] = in[i];
        }
    }

    /** @brief ���������� ������ ��� ���� ��������
        @param[in] in ������ ������� ������ ��������� (���������� ������)
        @param[in] out ������ �������� ������ ��������� (���������� ������)
        @param[in] dataIn ��������� �� ��������� ������ ������� ������ ���������
        @param[in] dataOut ��������� �� ��������� ������ �������� ������ ���������
        @param[in] x ������ ���������� �������
    */
    template<class dataType, class dataType2>
    void setData(std::vector<dataType>& in, std::vector<dataType2>& out, fann_type** dataIn, fann_type** dataOut, int x) {
        for(int i = 0; i < (int)in.size(); i++) {
            dataIn[x][i] = in[i];
        }
        for(int i = 0; i < (int)out.size(); i++) {
            dataOut[x][i] = out[i];
        }
    }

    /** @brief ������������� ������ ������� � ������ ��� ��������� ����
        @param[in] in ������ ������
        @return ��������� �� ������
    */
    template<class dataType>
    fann_type* conversion(std::vector<dataType>& in) {
        fann_type* out = (fann_type*)malloc(in.size() * sizeof(fann_type));
        for(int i = 0; i < (int)in.size(); i++) {
            out[i] = in[i];
        }
        return out;
    }

    template<class dataType>
    void conversion(std::vector<dataType>& in, fann_type* out) {
        for(int i = 0; i < (int)in.size(); i++) {
            out[i] = in[i];
        }
    }

    /** @brief ��������� ���������
        ������� ���������� ������������ ����� ���������, ��� � ������ ���������������� -1
        @param[in] ann ���������
        @param[in] in ������ ������
        @return ����� ������������� ������ ��������� ���  -1 � ������ ��������������� ���������
    */
    template<class dataType>
    int runNet(struct fann* ann, std::vector<dataType>& in) {
        fann_type* input = conversion(in);
        fann_type* calcOut = fann_run(ann, input);
        int nOut = fann_get_num_output(ann);
        fann_type maxOut = 0;
        int pos = -1;
        for(int i = 0; i < nOut; i++) {
            if(calcOut[i] > maxOut) {
                maxOut = calcOut[i];
                pos = i;
            }
        }
        free(input);
        return pos;
    }

    class BaseNet {
        public:
        bool isInit = false;
        std::string path;
        struct fann* ann = NULL;
        fann_type* input = NULL;
        int nInput = 0;
        int nOutput = 0;
        BaseNet();
        BaseNet(std::string path);
        ~BaseNet();
        void updata(std::vector<double>& in, std::vector<double>& out);
        int updata(std::vector<double>& in);
    };

    /*
     class Balance {
        public:
        std::vector<std::vector<double>> vInput;
        Balance(int maxSample, int nInput, int nOutput);
        void setData(std::vector<double>& input, std::vector<double>& output);
     };
     */

}

#endif // FANNFUNCTIONS_HPP_INCLUDED
