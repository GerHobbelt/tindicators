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
        double output = iSMA.updata(100);
        double output = iSMA.updata(100);
        double output = iSMA.updata(100);
        @endcode
    */
    class SMA {
        private:
        int n;
        std::vector<double> data;
        double prevData;
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
        double updata(double input);
        double test(double input);
        int getPeriod() {return n;};
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
        double updata(double input);
        int getPeriod() {return n;};
        bool isInit;
    };

    /** @brief ����� ���������������� ���������� �������
        @version 1.0
        @date 08.01.2018
    */
    class MMA {
        private:
        int n;
        double a;
        double prevOut;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        MMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        MMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double updata(double input);
        double test(double input);
        int getPeriod() {return n;};
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
        double updata(double input);
        int getPeriod() {return n;};
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
        double updata(double input);
        int getPeriod() {return n;};
    };

    /** @brief ����� ������� ������������� ���� � �������������� WMA ������ SMA
        @version 1.0
        @date 08.01.2018
    */
    class WRSI {
        private:
        MMA iU;
        MMA iD;
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
        double updata(double input);
        double test(double input);
        int getPeriod() {return n;};
    };

    /** @brief ����� ������� ������������� ���� � �������������� SMM ������ SMA
        @version 1.0
        @date 08.01.2018
    */
    class SRSI {
        private:
        SMM iU;
        SMM iD;
        int n;
        double prevInput;
        public:
        bool isStart = false;
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 5)
        */
        SRSI();
        /** @brief ������������� ���������� � ��������� ��������
            @param[in] period ������ ����������
        */
        SRSI(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        double updata(double input);
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
        void updata(double input);
        void test(double input);
        double tl = 0; ///< ������� ������ �����������
        double bl = 0; ///< ������ ������ �����������
        double ml = 0; ///< ������� ���������� �������
        int getPeriod() {return n;};
        double getStdDevFactor() {return d;};
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

        double _updata(double price, int length, int r);
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
        double updata(double in);
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
        double updata(double in);
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
        double updata(double in);
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
        double updata(double in);
        double TL2= 0;
        double TL1 = 0;
        double ML = 0;
        double BL1= 0;
        double BL2 = 0;
    };

    /** @brief ����� �����������. ����� ���������� ������ ��������� �����������
        @version 1.0
        @date 11.01.2018
    */
    class SearchExtrema {
        private:
        int isMinMax = 0;
        int n;
        double a, b;
        double a2, b2;
        bool isStart = false;
        double extDeviation = 0.05;
        public:
        /** @brief ������������� ����������
        */
        SearchExtrema();
        /** @brief ������������� ���������� � ��������� �����������
            @param[in] nLastExtrema ���������� ��������� ����������� � �������
            @warning ���������� ��������� ����������� � ������� ������ ���� ������ 0
        */
        SearchExtrema(int nLastExtrema);
        /** @brief ������������� ���������� � ��������� �����������
            @param[in] nLastExtrema ���������� ��������� ����������� � �������
            @warning ���������� ��������� ����������� � ������� ������ ���� ������ 0
        */
        SearchExtrema(int nLastExtrema, double extDeviation);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
        */
        void updata(double input);
        /** @brief �������� ������� ������ ����������
            @param[in] high �������� �������� ����
            @param[in] low ������� �������� ����
        */
        void updata(double high, double low);
        std::vector<double> lastExtremums; ///< ������ �����������
    };

#if(0)
    class ZigZag {
        private:
        int step = 0;
        int extDepth = 12;
        double extDeviation= 0.05;
        int extBackstep = 3;
        int isMinimumSearch = 1;
        int nLastExtrema = 10;
        double lastMin;
        double lastMax;
        std::vector<double> vDepth;
        public:
        ZigZag();
        ZigZag(int extDepth, double extDeviation, int extBackstep, int nLastExtrema);
        void updata(double input);
        void updata(double high, double low);
        std::vector<double> lastExtremums; ///< ������ �����������
    };
#endif

    /** @brief ����� ������������ ������������ ��������� ���������� �������
        @version 1.0
        @date 14.01.2018
    */
    template <class MA_TYPE>
    class MultiMa {
        private:
        std::vector<MA_TYPE> vMa;
        int nMa;
        public:
        MultiMa() {};
        /** @brief ���������������� ������� ����������
            @param[in] startPeriod ����������� ������ ������� ����������
            @param[in] stepPeriod ��� �������
            @param[in] nMa ���������� ������� ����������
        */
        MultiMa(int startPeriod, int stepPeriod, int nMa) {
            for(int n = 0; n < nMa; n++) {
                vMa.push_back(MA_TYPE(startPeriod + n*stepPeriod));
            }
            vOutput.resize(nMa);
            vPrevOutput.resize(nMa);
            MultiMa::nMa = nMa;
        };
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
        */
        void updata(double input) {
            vPrevOutput = vOutput;
            for(int n = 0; n < nMa; n++) {
                vOutput[n] = vMa[n].updata(input);
            }
        };
        std::vector<double> vOutput; ///< ������ �������� ������� ����������
        std::vector<double> vPrevOutput;
    };

    /** @brief ���������� ����
        @version 1.0
        @date 14.01.2018
    */
    class Window {
        private:
        int n;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        Window();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        Window(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
            @return �������� ����������
        */
        std::vector<double> updata(double input);
        std::vector<double> data; ///< ������ ��������� n ���������
        int getPeriod() {return n;};
    };

    class SearchMinMax {
        private:
        bool isStart = false;
        public:
        Window iWindow;
        SearchMinMax();
        SearchMinMax(int period);
        void updata(double input);
        double minData;
        double maxData;
        double minPrevData;
        double maxPrevData;
        bool isNewMin = false;
        bool isNewMax = false;
    };

    class BasicExtrema {
        private:
        int nWinow;
        int nExtrema;
        std::vector<double> data;
        void getExtrema(std::vector<double>& in, std::vector<double>& out, int dist);
        public:
        BasicExtrema();
        BasicExtrema(int nWinow, int nExtrema);
        void updata(double input);
    };

    /** @brief �������� ����������
        @version 1.0
        @date 21.01.2018
    */
    class ExtremaDetector {
        private:
        double prevInput = 0;
        bool isInit = false;
        int state = 0;
        public:
        bool isUpdataExtremaUp = false;
        bool isUpdataExtremaDown = false;
        ExtremaDetector();
        void updata(double input);
        double dataMin = 0, dataMax = 0;
    };

    /** @brief ������ ������ �������
        @version 1.0
        @date 30.01.2018
    */
     class LowPassFilter {
        private:
        double alfa;
        double beta;
        double prevY;
        char isStart = 0;
        public:
        double tranTime;
        LowPassFilter();
        LowPassFilter(double tranTime, double period, double errorSignal);
        LowPassFilter(double n, double errorSignal);
        LowPassFilter(double n);
        double updata(double in);
        char isInit(void) {return isStart;};
    };

    /** @brief ��������� n ����������
        @version 1.0
        @date 21.01.2018
    */
    class LastExtrema {
        private:
        bool isInit = false;
        int state = 0;
        int numExtrema = 10;
        int tick = 0;
        int initStep = 0;
        //int period = 10;
        Window iWindow;
        SMA iSmaMin;
        SMA iSmaMax;
        SearchMinMax iSearchMinMax;

        int stateMin = 0, stateMax = 0;
        public:
        double smaMin, smaMax, prevSmaMin, prevSmaMax;
        bool isUpdataExtremaUp = false;
        bool isUpdataExtremaDown = false;
        std::vector<double> vExtremaUp;
        std::vector<double> vExtremaDown;
        std::vector<double> vExtrema;
        LastExtrema();
        LastExtrema(int numExtrema, int period);
        void updata(double input);
        int getNumExtrema() {return numExtrema;};
        int getTick() {return tick;};
        int getInitState() {if(initStep & 0x07) return 1; return 0;};
    };

    /** @brief �������������� ������ ������
        @version 1.0
        @date 30.01.2018
    */
    class PsychologicalLevel {
        private:
        Window iWindow;
        int factor;
        bool isFactor = false;
        double diffMin;
        int nLevel;
        public:
        PsychologicalLevel();
        PsychologicalLevel(int nLevel);
        PsychologicalLevel(int nLevel, int nWindow);
        void updata(double input);
        bool isLevel100 = false;
        bool isLevel80 = false;
        bool isLevel50 = false;
        bool isLevel20 = false;
    };

    void getMinMaxBands(std::vector<double>& input, std::vector<double>& vMin, std::vector<double>& vMax, int period, int offset);

    /** @brief �������� �������
        �������� ������� ������������ � ���� ��������� �� 0.0 �� 1.0
        @version 1.0
        @date 03.02.2018
    */
    class ShannonEntropy {
        public:
        Window iWindow;
        double maxEntropy;
        ShannonEntropy();
        ShannonEntropy(int period);
        double updata(double input);
    };

    /** @brief ���������� �������� ����
    */
    class PriceMovementStatistics {
        public:
        int period, nHist;
        Window iWindow;
        PriceMovementStatistics();
        PriceMovementStatistics(int period, int nHist);
        void updata(double in);
        std::vector<double> hist;
        double pos;
        double up, down, neutral;
    };

    class TrendIndicator {
        public:
        std::vector<double> diff;
        Window iWindow;
        TrendIndicator();
        TrendIndicator(int period);
        double updata(double input);
        int state;
    };

    /** @brief ����������� ����������
    */
    class StandardDeviation {
        private:
        int n;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 20)
        */
        StandardDeviation();
        /** @brief ������������� ���������� � ��������� �����������
            @param[in] period ������ ����������
            @param[in] d ��������� ������������ ����������
        */
        StandardDeviation(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] input ������� ������ ����������
        */
        double updata(double input);
    };

    /** @brief ����� ���������
    */
    class NewTimeFrame {
        public:
        enum ePeriod {
            T5 = 5,
            T10 = 10,
            T15 = 15,
            T30 = 30,
            T60 = 60
        };
        ePeriod iPeriod;
        NewTimeFrame();
        /** @brief ������������� ����������
            @param[in] period �������� ���������
        */
        NewTimeFrame(ePeriod period);
        /** @brief �������� ������ ����������
            ������� ��������� ���������� out � ���������� 1 � ������ ���������
            ������ ���� ������ ����������.
            ���������� out �������� ��������� ��� ������ ����������.
            @param[in] in ����
            @param[in] minutes ������
            @return ������ 1 � ������ ��������� ������ ���� ������ ����������.
        */
        int updata(double in, int minutes);
        double out;
    };

    class ATR {
        private:
        bool isInit = false;
        EMA iEmaAtr;
        int n = 0;
        double prevClose;
        public:
        ATR();
        ATR(int period);
        double updata(double high, double low, double close);
        double TRj = 0;
    };

    class ADX {
        private:
        bool isInit = false;
        EMA iEmaP;
        EMA iEmaM;
        EMA iEmaAdx;
        int n = 0;
        double prevHigh;
        double prevLow;
        double prevClose;
        public:
        ADX();
        ADX(int period);
        double updata(double high, double low, double close);
        double adxj;
    };

    class VMA {
        private:
        int n;
        std::vector<double> data;
        std::vector<double> w;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        VMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        VMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] in ������� ������ ����������
            @return �������� ����������
        */
        double updata(double in, double vol);
        int getPeriod() {return n;};
    };

    class DMA {
        private:
        EMA iEMA;
        int n;
        double a;
        double prevOut;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        DMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        DMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] in ������� ������ ����������
            @return �������� ����������
        */
        double updata(double in);
        int getPeriod() {return n;};
        bool isInit;
    };

    class TMA {
        private:
        DMA iDMA;
        int n;
        double a;
        double prevOut;
        std::vector<double> data;
        public:
        /** @brief ������������� ���������� �� ������������ ����������� (������ ����� 10)
        */
        TMA();
        /** @brief ������������� ���������� � �������� ��������
            @param[in] period ������ ����������
        */
        TMA(int period);
        /** @brief �������� ������� ������ ����������
            @param[in] in ������� ������ ����������
            @return �������� ����������
        */
        double updata(double in);
        int getPeriod() {return n;};
        bool isInit;
    };

    /** @brief ����� ���������� ���������� �������
        @version 1.0
        @date 08.01.2018
    */
    class WMA {
        private:
        int n;
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
        double updata(double in);
        int getPeriod() {return n;};
    };

    class CA {
        private:
        int n;
        double prevData;
        public:
        CA();
        double updata(double in);
        int getPeriod() {return n;};
    };

    class AMA {
        private:
        StandardDeviation iSD;
        std::vector<double> data;
        int n, s, f;
        double _K;
        double prevAMA;
        bool isX2;
        public:
        AMA();
        AMA(int n, int f, int s, int d, double K);
        double updata(double in);
        double filter;
        int state;
        int getPeriod() {return n;};
    };

    class SMMA {
        private:
        std::vector<double> data;
        int n;
        //bool isInit;
        double smma2;
        public:
        SMMA();
        SMMA(int n);
        double updata(double in);
        int getPeriod() {return n;};
    };

    // ����������� ���������� ���������� �������
    class FRAMA {
        private:
        int n;
        double coeff = 4.6;
        std::vector<double> vdata;
        std::vector<double> vhigh;
        std::vector<double> vlow;
        double prevFRAMA;
        bool isUseHighLow;
        public:
        bool isFlexFrama; ///< ���������������� FlexFrama
        FRAMA();
        FRAMA(int n);
        FRAMA(int n, bool isUseHighLow);
        double updata(double in, double high, double low);
        int getPeriod() {return n;};
    };

    // ���������� ������� ����
    class HMA {
        private:
        int n;
        WMA iWMAn;
        WMA iWMAn2;
        WMA iWMAsqrtn;
        public:
        HMA();
        HMA(int n);
        double updata(double in);
        int getPeriod() {return n;};
    };

    //
    class VIDYA {
        private:
        double prevInput;
        double prevVIDYA;
        double F;
        SMA iSumUp;
        SMA iSumDn;
        int n;
        bool isStart;
        public:
        VIDYA();
        VIDYA(int n);
        double updata(double in);
        int getPeriod() {return n;};
    };

    class TrendFlatIndicator {
        private:
        LastExtrema iLastExtrema;
        EMA iEMA;
        double dX;
        double trendData = 0.0;
        public:
        TrendFlatIndicator();
        TrendFlatIndicator(int _n, int nFilter, double dX);
        double updata(double in);
    };
}

#endif // TRADINGINDICATORS_HPP_INCLUDED
