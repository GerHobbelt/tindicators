#ifndef STRATEGYEFFECTIVENESS_HPP_INCLUDED
#define STRATEGYEFFECTIVENESS_HPP_INCLUDED

#include <vector>

class StrategyEffectiveness {
    public:
    int hwin[24];
    int hloss[24];
    int win = 0; // ���������� ���������
    int loss = 0; // ���������� ����������
    double money = 100; // ������
    double profit = 0.9; // ���������� �� ������
    double rate = 0.01; // ������
    double grossprofit = 0;
    double grossloss = 0;
    std::vector<double> vMoney;
    StrategyEffectiveness();
    void setWin();
    void setLoss();
    void setWin(int hour);
    void setLoss(int hour);
    double getConsistency();
    double getProfitStability();
    double getProfitLoss();
    double getAverageGeometricYield();
    double getCoeffSharpe();
    double getBalanceMaxCoeffSharpe();
    double getEff();

    double getAverageGeometricYieldMx();

    int getGoodHour();
    // ����������� ������������ �������� �������
    double getTSSF();
};

#endif // STRATEGYEFFECTIVENESS_HPP_INCLUDED
