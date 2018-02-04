#ifndef FOREXTESTING_HPP_INCLUDED
#define FOREXTESTING_HPP_INCLUDED

#include <vector>

namespace ForexTesting {

    double calcProfitsLosses(double contract, double openPrice, double closePrice, int isBuyOrSell);

    class Testing {
        public:
        int countId = 0;
        double money = 100000.0; ///< ������� � ������� ������
        double onePoint = 0.00001; ///< ��� ����
        std::vector<double> vMoney;

        typedef struct sOrder {
            int id; ///< ����� ������
            double contract; /// ������ ���������
            double lot; ///< ������ ����
            double onePointValue; ///< ��������� ������
            double openPrice; ///< ���� �� ������ ���������� ���������
            double closePrice; ///< ���� �� ������ �������� ���������
            double pledge; ///< �����
            double stopLoss;
            double takeProfit;
            int isBuyOrSell;
            int isClose;
        };

        std::vector<sOrder> vOrder;

        Testing();

        /** @brief ���������� �����
            @param[in] price ������� ����
            @param[in] lot ����� (���)
            @param[in] leverage ��������� �����
            @param[in] isBuyOrSell ��� ������ (buy 1, sell -1)
            @param[in] spread ������ ������
            @param[in] stopLoss ���� ����
            @param[in] takeProfit ���� ������
            @param[in] id ����� ������
        */
        void setOrder(double price, double lot, int leverage, int isBuyOrSell, double spread, double stopLoss, double takeProfit, int& id);

        /** @brief �������� ������ �� �������
            @param[in] priceHigh ���� high ����
            @param[in] priceLow ���� low ����
            @param[in] price ���� �������� ����
            @param[in] isBuyOrSell ��� ������ (����� 1, ���� -1)
            @param[in] spread ������ ������
        */
        void updata(double priceHigh, double priceLow, double price, double spread);

        /** @brief ���������� ������ ��������
            @param[in] money ������
        */
        void setMoney(double money);

        /** @brief �������� ������ ������
            @param[in] id ����� ������
            @return ������ 1 � ������ ���� ������ ���� �������
        */
        int getStateOrder(int id);

        /** @brief ���������� ���� ����
            @param[in] id ����� ������
            @param[in] stopLoss ���� ����
        */
        void setStopLoss(int id, double stopLoss);

        /** @brief �������� ���� ���� ������
            @param[in] id ����� ������
            @return ������ 1 � ������ buy ������, -1 � ������ sell ������, 0 � ������ ���� ������ �� �������
        */
        int getBuySellFlag(int id);
    };

}

#endif // FOREXTESTING_HPP_INCLUDED
