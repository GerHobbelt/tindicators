#include <iostream>
#include "ReadingData.hpp"
#include "TradingIndicators.hpp"
#include "StrategyEffectiveness.hpp"

using namespace std;

int main() {
    std::vector<std::string> vPairName(25);
    vPairName[0] = "..//..//train2018//EURAUD1.csv";
    vPairName[1] = "..//..//train2018//EURJPY1.csv";
    vPairName[2] = "..//..//train2018//EURGBP1.csv";
    vPairName[3] = "..//..//train2018//EURCAD1.csv";
    vPairName[4] = "..//..//train2018//EURNZD1.csv";
    vPairName[5] = "..//..//train2018//EURCHF1.csv";
    vPairName[6] = "..//..//train2018//EURUSD1.csv";

    vPairName[7] = "..//..//train2018//AUDCAD1.csv";
    vPairName[8] = "..//..//train2018//AUDNZD1.csv";
    vPairName[9] = "..//..//train2018//AUDCHF1.csv";
    vPairName[10] = "..//..//train2018//AUDJPY1.csv";
    vPairName[11] = "..//..//train2018//AUDUSD1.csv";

    vPairName[12] = "..//..//train2018//CADCHF1.csv";
    vPairName[13] = "..//..//train2018//CADJPY1.csv";

    vPairName[14] = "..//..//train2018//GBPAUD1.csv";
    vPairName[15] = "..//..//train2018//GBPCHF1.csv";
    vPairName[16] = "..//..//train2018//GBPJPY1.csv";
    vPairName[17] = "..//..//train2018//GBPUSD1.csv";

    vPairName[18] = "..//..//train2018//NZDCAD1.csv";
    vPairName[19] = "..//..//train2018//NZDJPY1.csv";
    vPairName[20] = "..//..//train2018//NZDUSD1.csv";

    vPairName[21] = "..//..//train2018//USDCAD1.csv";
    vPairName[22] = "..//..//train2018//USDCHF1.csv";
    vPairName[23] = "..//..//train2018//USDJPY1.csv";

    vPairName[24] = "..//..//train2018//CHFJPY1.csv";

    int expTime = 3; // ����� ����������
    double start = 0.0; // ������ ������
    double stop = 1.0; // ����� ������

    StrategyEffectiveness iEffAll; // ������������� ��������� �� ���� �������� �����

    for(int n = 0; n < (int)vPairName.size(); n++) {
        CurrencyQuote TestData(vPairName[n],
                               CurrencyQuote::DTYYYYMMDD_TIME_OPEN_HIGH_LOW_CLOSE_VOL);

        int startPos = TestData.close.size() * start; // ������ ������
        int stopPos = TestData.close.size() * stop; // ����� ������
        std::cout << "Source: " << vPairName[n]
            << " data size: " << TestData.close.size() << std::endl;

        StrategyEffectiveness iEff; // ������������� ���������
        Indicators::BollingerBands iBB(20, 2.0); // ��������� ����������
        Indicators::WRSI iRSI(5); // ��������� RSI
        const double RSI_UP = 70; // ������� ������� ���������� RSI
        const double RSI_DN = 30; // ������ ������� ���������� RSI
        for(int i = startPos; i < stopPos - expTime; i++) {
            // ���� �������� ����
            double& close = TestData.close[i];
            // ���� �������� ���� �� �������� �� expTime ����� ������
            double& closeFuture = TestData.close[i + expTime];
            // ������� ������ ���������� Bollinger Bands
            iBB.updata(close);
            // ������� ������ ���������� RSI
            double rsiData = iRSI.updata(close);
            // ��������� �������� ���������,
            // 0 -��� ��������, 1 ��� -1 - ������� � ������������ ����� ��� ����
            int stateStrategy = 0;
            if(rsiData > RSI_UP && close > iBB.tl) {
                stateStrategy = -1;
            } else
            if(rsiData < RSI_DN && close < iBB.bl) {
                stateStrategy = 1;
            }

            if(stateStrategy == 1) {
                if(closeFuture > close) {
                    iEff.setWin(); iEffAll.setWin();
                } else {
                    iEff.setLoss(); iEffAll.setLoss();
                }
            } else
            if(stateStrategy == -1) {
                if(closeFuture < close) {
                    iEff.setWin(); iEffAll.setWin();
                } else {
                    iEff.setLoss(); iEffAll.setLoss();
                }
            }
        } // for i
        std::cout << "eff: " << iEff.getEff()
            << " num: " << (iEff.win + iEff.loss) << std::endl;
        std::cout << "eff all: " << iEffAll.getEff()
            << " num: " << (iEff.win + iEff.loss) << std::endl;
    } // for n

    return 0;
}
