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
    @brief ������������ ���� � �������� ��������� ����������� ����������� �������
    @version 1.0
    @date 08.01.2018
*/

#ifndef TRADINGINDICATORS_HPP_INCLUDED
#define TRADINGINDICATORS_HPP_INCLUDED

#include <vector>
#include <numeric>
#include <algorithm>

namespace Indicators {

    /** @brief ����� ������� ���������� �������
        @version 1.0
        @date 08.01.2018
        @code
        Indicators::SMA iSMA(5); // ������� ��������� � �������� 5
        // ������ �� ���� ���������� �������� 100,
        // �� ������ �������� �������
        // �������� �� ��������� 5 ��������.
        double output = iSMA.update(100);
        double output = iSMA.update(100);
        double output = iSMA.update(100);
        @endcode
    */
    class SMA {
        private:
        int n;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        SMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        SMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double update(double input);
    };

    /** @brief ����� ���������������� ���������� �������
        @version 1.0
        @date 08.01.2018
    */
    class EMA {
        private:
        int n;
        double a;
        double prevOut;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        EMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        EMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double update(double input);
    };

    /** @brief ����� ���������� ���������� �������
        @version 1.0
        @date 08.01.2018
    */
    class WMA {
        private:
        int n;
        double a;
        double prevOut;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        WMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        WMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double update(double input);
    };

    /** @brief ������� ���������� �������
        @version 1.0
        @date 08.01.2018
    */
    class SMM {
        private:
        int n;
        std::vector<double> data;
        public:
        /** @brief ������������� ������� ���������� ������� �� ������������ ����������� (������ ����� 10)
        */
        SMM();
        /** @brief ������������� ������� ���������� ������� � �������� ��������
            @param[in] period ������ ����������
        */
        SMM(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double update(double input);
    };

    /** @brief ����� ������� ������������� ����
        @version 1.0
        @date 08.01.2018
    */
    class RSI {
        private:
        SMA iU;
        SMA iD;
        int n;
        double prevInput;
        public:
        bool isStart = false;
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 5)
        */
        RSI();
        /** @brief ������������� ���������� � ��������� ��������
            @param[in] period ������ ����������
        */
        RSI(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double update(double input);
    };

    /** @brief ����� ������� ������������� ���� � �������������� WMA ������ SMA
        @version 1.0
        @date 08.01.2018
    */
    class WRSI {
        private:
        WMA iU;
        WMA iD;
        int n;
        double prevInput;
        public:
        bool isStart = false;
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 5)
        */
        WRSI();
        /** @brief ������������� ���������� � ��������� ��������
            @param[in] period ������ ����������
        */
        WRSI(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double update(double input);
    };

    /** @brief ����� �����������
        @version 1.0
        @date 09.01.2018
    */
    class BollingerBands {
        private:
        int n;
        double d;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 20, ��������� 2)
        */
        BollingerBands();
        /** @brief ������������� ���������� � ��������� �����������
            @param[in] period ������ ����������
            @param[in] d ��������� ������������ ����������
        */
        BollingerBands(int period, double d);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
        */
        void update(double input);
        double tl = 0; ///< ������� ������ �����������
        double bl = 0; ///< ������ ������ �����������
        double ml = 0; ///< ������� ���������� �������
    };

    /** @brief ��������� ����������� ����������
        @param[in] input ������� ������ ����������
        @return ����������� ����������
    */
    template<class dataType>
    double calcStandardDeviation(std::vector<dataType>& input) {
        double mean = std::accumulate(input.begin(), input.end(), 0);
        mean /= (double)input.size();
        double _stdDev = 0;
        for (int i = 0; i < (int)input.size(); i++) {
            double diff = (input[i] - mean);
            _stdDev +=  diff * diff;
        }
        return std::sqrt(_stdDev / (double)(input.size() - 1));
    }

    /** @brief ���������� ������� NoLagMa
        @version 1.0
        @date 09.01.2018
    */
    class NoLagMa {
        private:
        std::vector<double> nlm_values;
        std::vector<double> nlm_prices;
        std::vector<double> nlm_alphas;

        double Pi = 3.14159265358979323846264338327950288;
        int _length = 0;
        int _len = 1;
        int _weight = 2;

        int LengthMA = 10;
        int bars = 0;

        double _update(double price, int length, int r);
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 3)
        */
        NoLagMa();
        /** @brief ������������� ���������� � ��������� �����������
            @param[in] period ������ ����������
            @warning ������ ������ ���� ������ ��� ����� 3
        */
        NoLagMa(int n);
        /** @brief �������� ������� ������ ����������
            @param[in] in ������� ������ ����������
            @return �������� ����������
        */
        double update(double in);
    };

    /** @brief ���������� ������� FATL
        @version 1.0
        @date 09.01.2018
    */
    class FATL {
        private:
        int FATLPeriod = 39;
        double price[39];
        int tick = 0;
        public:
        int trendState = 0; ///< ����������� ������
        double prevOut = 0; ///< ���������� �������� ����������
        double out = 0; ///< �������� ����������
        /** @brief ������������� ����������
        */
        FATL();
        /** @brief �������� ������� ������ ����������
            @param[in] in ������� ������ ����������
            @return �������� ����������
        */
        double update(double in);
    };

    /** @brief ���������� ������� SATL
        @version 1.0
        @date 09.01.2018
    */
    class SATL {
        private:
        int SATLPeriod = 65;
        double price[65];
        int tick = 0;
        public:
        int trendState = 0; ///< ����������� ������
        double prevOut = 0; ///< ���������� �������� ����������
        double out = 0; ///< �������� ����������
        /** @brief ������������� ����������
        */
        SATL();
        /** @brief �������� ������� ������ ����������
            @param[in] in ������� ������ ����������
            @return �������� ����������
        */
        double update(double in);
    };

    /** @brief ��������� RBCI
        @version 1.0
        @date 09.01.2018
    */
    class RBCI {
        private:
        BollingerBands iBB;
        int RBCIPeriod=56;
        int BBPeriod=100;          //������ ��� ������� �����������
        double BandsDeviation = 2; //��������
        double price[56];
        int tick = 0;
        public:
        int trendState = 0;
        double prevOut = 0;
        double out = 0;
        RBCI();
        RBCI(int BBPeriod, double BandsDeviation);
        double update(double in);
        double TL2= 0;
        double TL1 = 0;
        double ML = 0;
        double BL1= 0;
        double BL2 = 0;
    };

    /** @brief ����� �����������. ����� ���������� ������ ��������� �����������
        @version 1.0
        @date 09.01.2018
    */
    class SearchExtrema {
        private:
        int n;
        double a, b;
        double a2, b2;
        bool isStart = false;
        public:
        /** @brief ������������� ����������
        */
        SearchExtrema();
        /** @brief ������������� ���������� � ��������� �����������
            @param[in] nLastExtrema ���������� ��������� ����������� � �������
            @warning ���������� ��������� ����������� � ������� ������ ���� ������ 0
        */
        SearchExtrema(int nLastExtrema);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
        */
        void update(double input);
        /** @brief �������� ������� ������ ����������
            @param[in] high �������� �������� ����
            @param[in] low ������� �������� ����
        */
        void update(double high, double low);
        std::vector<double> lastExtremums; ///< ������ �����������
    };

}

#endif // TRADINGINDICATORS_HPP_INCLUDED
